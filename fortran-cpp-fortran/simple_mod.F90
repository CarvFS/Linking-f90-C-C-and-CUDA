MODULE simple
  !IMPLICIT NONE
  use simple2_mod
  ! An example of an non-interoperable type (no BIND(C)).
  
CONTAINS
  FUNCTION GetHandle(pda,pdFstr) RESULT(handle) BIND(C, NAME='GetHandle')
    ! USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_PTR, C_LOC, C_INT
    USE ISO_C_BINDING
    TYPE(C_PTR) :: handle
    TYPE(SIMPLEF), POINTER :: p
    integer, value :: pda
    character(C_char),  dimension(256) :: pdFstr
    !***
    ! For the sake of example we are exposing an interface that 
    ! allows client code to create an object.  Perhaps in your 
    ! case the object already exists and its lifetime is managed 
    ! in some other way, in which case:
    !
    !   handle = C_LOC(existing_object_with_target_attribute)
    !
    ! and you are done - no need for ReleaseHandle.
    ALLOCATE(p)
    ! Perhaps some constructory sort of stuff here?
    write(*,*) "In simple_mod.F90: pre-defining a as ", pda
    p%a = pda
    write(*,*) "In simple_mod.F90: pre-defining Fstr as ", pdFstr
    p%Fstr = pdFstr
    ! Use the C address of the object as an opaque handle.
    handle = C_LOC(p)
  END FUNCTION GetHandle

  ! If you create objects, you need to be able to destroy them.
  SUBROUTINE ReleaseHandle(handle) BIND(C, NAME='ReleaseHandle')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_PTR, C_F_POINTER
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    DEALLOCATE(p)
  END SUBROUTINE ReleaseHandle

  SUBROUTINE SetA(handle, a) BIND(C, NAME='SetA')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_INT
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    INTEGER(C_INT), INTENT(IN), VALUE :: a  
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    p%a = a
  END SUBROUTINE SetA

  FUNCTION QueryA(handle) RESULT(a) BIND(C, NAME='QueryA')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_INT
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    INTEGER(C_INT) :: a  
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    a = p%a
  END FUNCTION QueryA

  SUBROUTINE Setdk(handle, dk) BIND(C, NAME='Setdk')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_DOUBLE
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    REAL(C_DOUBLE), INTENT(IN), VALUE :: dk  
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    p%dk = dk
  END SUBROUTINE Setdk

  FUNCTION Getdk(this) RESULT(dk) BIND(C, NAME='Getdk')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_DOUBLE
    TYPE(C_PTR), INTENT(IN), VALUE :: this
    REAL(C_DOUBLE) :: dk  
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(this, p)
    dk = get_dk(p)
  END FUNCTION Getdk

  function get_dk(this) result(dk)
    type(SIMPLEF) :: this
    real :: dk
    dk = this%dk
  end function get_dk


  SUBROUTINE SetB(handle, data, data_size) BIND(C, NAME='SetB')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_INT
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    INTEGER(C_INT), INTENT(IN), VALUE :: data_size
    INTEGER(C_INT), INTENT(IN) :: data(data_size)
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    ! Allocate p%B to appropriate size.
    !
    ! Assuming here the pointer association status of p%B is always 
    ! defined or dissociated, never undefined.  This is much easier 
    ! with allocatable components.
    write(*,*) "In simple_mod.F90's SetB: receiving b as ", data
    IF (ASSOCIATED(p%B)) THEN
      IF (SIZE(p%B) /= data_size) THEN
        DEALLOCATE(p%B)
        ALLOCATE(p%B(data_size))
      END IF
    ELSE
      ALLOCATE(p%B(data_size))
    END IF
    p%B = data
  END SUBROUTINE SetB

  SUBROUTINE QueryBSize(handle, data_size) BIND(C, NAME='QueryBSize')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_INT
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    INTEGER(C_INT), INTENT(OUT) :: data_size
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    ! write(*,*) "In simple_mod.F90's GetB: receiving n as ", data_size
    ! See comments about assumed association status above.
    IF (ASSOCIATED(p%B)) THEN
      data_size = SIZE(p%B, KIND=C_INT)
    ELSE
      data_size = 0_C_INT
    END IF
  END SUBROUTINE QueryBSize

  SUBROUTINE QueryBData(handle, data) BIND(C, NAME='QueryBData')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_INT
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    INTEGER(C_INT), INTENT(OUT) :: data(*)
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    ! See comments about assumed association status above.
    IF (ASSOCIATED(p%B)) THEN
      data(:SIZE(p%B)) = p%B
    ELSE
      ! Someone is being silly.
    END IF
  END SUBROUTINE QueryBData

  function add_a_dk(handle) result(sum) bind(C, name='add_a_dk')
    USE, INTRINSIC :: ISO_C_BINDING, ONLY:  &
        C_PTR, C_F_POINTER, C_DOUBLE, C_INT
    TYPE(C_PTR), INTENT(IN), VALUE :: handle
    REAL(C_DOUBLE) :: sum
    REAL(C_DOUBLE) :: dk  
    INTEGER(C_INT) :: a
    TYPE(SIMPLEF), POINTER :: p
    !***
    CALL C_F_POINTER(handle, p)
    dk = p%dk
    a = p%a
    sum = a + dk
  end function add_a_dk

  ! ...etc...
END MODULE simple
