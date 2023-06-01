module FirstMod
    use iso_c_binding
    implicit none
    
    TYPE, bind(C) :: firstex_v1
      INTEGER(C_INT) :: a
      REAL(C_DOUBLE) :: dk
      type(C_ptr) :: Fstr 
      type(C_ptr) :: B
      type(C_ptr) :: B2
    !   CHARACTER(C_CHAR), dimension(256) :: Fstr
    !   INTEGER, POINTER :: B(:) => NULL()
    !   integer, pointer :: C(:,:) => NULL()
    !   integer, pointer :: D(:,:,:) => NULL()
    END TYPE firstex_v1

    TYPE :: firstex_v2
      INTEGER :: a
      REAL*8 :: dk
      character(len=256) :: Fstr
      INTEGER, POINTER :: B(:) => NULL()
    !   integer, pointer :: C(:,:) => NULL()
    !   integer, pointer :: D(:,:,:) => NULL()
    END TYPE firstex_v2

    interface

        subroutine C_FirstMod_new_v1(p, N_1d, a_int, dk_real, Fstr) bind(C,name="Initialize_firstex_v1")
            import
            type(C_ptr) :: p
            integer(C_INT), value :: a_int, N_1d
            real(C_DOUBLE), value :: dk_real
            character(C_CHAR), dimension(*) :: Fstr

        end subroutine C_FirstMod_new_v1

        subroutine C_FirstMod_new_v2(p_a, p_dk, p_Fstr, p_1dptr, N_1d, a_int, dk_real, F_str) bind(C,name="Initialize_firstex_v2")
            import
            type(C_ptr) :: p_a, p_dk, p_Fstr, p_1dptr
            integer(C_INT), value :: a_int, N_1d
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
    subroutine new_1(this, N_1d, a_int, dk_real, Fstr)
        type(firstex_v1), pointer :: this
        integer :: a_int, N_1d
        real*8 :: dk_real
        character(len=256), intent(in) :: Fstr
        type(C_PTR) :: p

        !!> Why do I have to do this??? The order matters...!
        type(C_PTR) :: p_a, p_dk, p_Fstr, p_B, p_B2
        p_a = C_LOC(this%a)
        p_B2 = this%B2
        p_B = this%B
        p_Fstr = this%Fstr
        p_dk = C_LOC(this%dk)
        p = C_LOC(this)
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        write(*,*) "In FirstMod.F90: passing... a = ", this%a, "dk = ", this%dk, "C address to Fstr = ", this%Fstr

        call C_FirstMod_new_v1(p, N_1d, a_int, dk_real, Fstr)
        
    end subroutine new_1

    subroutine new_2(this, N_1d, a_int, dk_real, F_str)
        type(firstex_v2), pointer :: this
        integer :: a_int, N_1d, i
        real*8 :: dk_real
        character(len=*), intent(in) :: F_str

        type(C_PTR) :: p_a, p_dk, p_Fstr, p_1dptr
        p_a = C_LOC(this%a)
        p_dk = C_LOC(this%dk)
        p_Fstr = C_LOC(this%Fstr)
        p_1dptr = C_LOC(this%B)

        write(*,*) "In FirstMod.90: Passing B as:"
        do i = 1,N_1d
            write(*,*) "B(",i,") = ", this%B(i)
        end do

        call C_FirstMod_new_v2(p_a, p_dk, p_Fstr, p_1dptr, N_1d, a_int, dk_real, F_str)
        
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
