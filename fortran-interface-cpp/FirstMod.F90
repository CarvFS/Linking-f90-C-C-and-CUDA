module FirstMod
    use iso_c_binding
    implicit none
    
    TYPE, bind(C) :: firstex_v1
      INTEGER(C_INT) :: a
      REAL(C_DOUBLE) :: dk
    !   character, dimension(256) :: Fstr
    !   INTEGER, POINTER :: B(:) => NULL()
    !   integer, pointer :: C(:,:) => NULL()
    !   integer, pointer :: D(:,:,:) => NULL()
    END TYPE firstex_v1

    TYPE :: firstex_v2
      INTEGER :: a
      REAL*8 :: dk
      character(len=256) :: Fstr
    !   INTEGER, POINTER :: B(:) => NULL()
    !   integer, pointer :: C(:,:) => NULL()
    !   integer, pointer :: D(:,:,:) => NULL()
    END TYPE firstex_v2

    interface

        subroutine C_FirstMod_new_v1(p, a_int, dk_real) bind(C,name="Initialize_firstex_v1")
            import
            type(C_ptr) :: p
            integer(C_INT), value :: a_int
            real(C_DOUBLE), value :: dk_real

        end subroutine C_FirstMod_new_v1

        subroutine C_FirstMod_new_v2(p_a, p_dk, p_Fstr, a_int, dk_real, F_str) bind(C,name="Initialize_firstex_v2")
            import
            type(C_ptr) :: p_a, p_dk, p_Fstr
            integer(C_INT), value :: a_int
            real(C_DOUBLE), value :: dk_real
            character(C_CHAR), dimension(*) :: F_str

        end subroutine C_FirstMod_new_v2

    end interface

    interface FirstMod_new_v1
        module procedure new_1
    end interface FirstMod_new_v1

    interface FirstMod_new_v2
        module procedure new_2
    end interface FirstMod_new_v2

    contains

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!> INITIALIZING IN C++
    subroutine new_1(this, a_int, dk_real)
        type(firstex_v1), pointer :: this
        integer :: a_int
        real*8 :: dk_real

        type(C_PTR) :: p_a, p_dk, p
        p_a = C_LOC(this%a)
        p_dk = C_LOC(this%dk)
        
        p = C_LOC(this)

        call C_FirstMod_new_v1(p, a_int, dk_real)
        
    end subroutine new_1

    subroutine new_2(this, a_int, dk_real, F_str)
        type(firstex_v2), pointer :: this
        integer :: a_int
        real*8 :: dk_real
        character(len=*), intent(in) :: F_str

        type(C_PTR) :: p_a, p_dk, p_Fstr, p
        p_a = C_LOC(this%a)
        p_dk = C_LOC(this%dk)
        p_Fstr = C_LOC(this%Fstr)
        
        p = C_LOC(this%a)

        call C_FirstMod_new_v2(p_a, p_dk, p_Fstr, a_int, dk_real, F_str)
        
    end subroutine new_2

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!> INITIALIZING IN FORTRAN
    ! subroutine new_(this, a_int, dk_real, F_str)
    !     type(firstex), intent(inout) :: this
    !     integer :: a_int
    !     real*8 :: dk_real
    !     character(len=*), intent(in) :: F_str

    !     this%a = a_int
    !     this%dk = dk_real
    !     this%Fstr = trim(F_str)

    ! end subroutine new_

end module
