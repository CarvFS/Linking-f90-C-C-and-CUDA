module SimpleF_mod

    use iso_c_binding
    implicit none

    type,bind(C) :: simp
        private
        type(C_ptr) :: object = C_NULL_ptr
    end type simp

    interface

        function C_SimpleF__new(a, Fstr) result(this) bind(C,name="SimpleF__new")
            import
            type(C_ptr) :: this
            integer(C_INT), value :: a
            character(C_char), optional,  dimension(*) :: Fstr
        end function C_SimpleF__new

        subroutine C_SimpleF__setA(this, a) bind(C,name="SimpleF__setA")
            import
            integer(C_INT), value :: a
            type(C_ptr), value :: this
        end subroutine C_SimpleF__setA

        function C_SimpleF__getA(this) result(a) bind(C,name="SimpleF__getA")
            import
            integer(C_int) :: a
            type(C_ptr), value :: this
        end function C_SimpleF__getA

        subroutine C_SimpleF__getFstr(this, Fstr) bind(C,name="SimpleF__getFstr")
            import
            type(C_ptr), intent(in) :: this
            character(C_char),  dimension(256) :: Fstr
            ! character(1) :: Fstr
            ! type(C_ptr) :: Fstr
        end subroutine C_SimpleF__getFstr

        subroutine C_SimpleF__setB(this, n, b) bind(C,name="SimpleF__setB")
            import
            integer(C_INT), value :: n
            integer(C_INT) :: b(n)
            type(C_ptr), value :: this
        end subroutine C_SimpleF__setB

        subroutine C_SimpleF__setC(this, n, b) bind(C,name="SimpleF__setC")
            import
            integer(C_INT), value :: n
            integer(C_INT) :: b(n,n)
            type(C_ptr), value :: this
        end subroutine C_SimpleF__setC

        subroutine C_SimpleF__getB(this, n, b2) bind(C,name="SimpleF__getB")
            import
            integer(C_int), value :: n
            integer(C_INT) :: b2(n)
            type(C_ptr), value :: this
        end subroutine C_SimpleF__getB

        subroutine C_SimpleF__getC(this, n, b2) bind(C,name="SimpleF__getC")
            import
            integer(C_int), value :: n
            integer(C_INT) :: b2(n,n)
            type(C_ptr), value :: this
        end subroutine C_SimpleF__getC

        subroutine C_SimpleF__passFptr(this, N, d) bind(C,name="SimpleF__passFptr")
            import
            integer(C_INT), value :: N
            type(C_ptr), value :: this
            ! integer(C_int), pointer :: d(:,:,:)
            type(C_ptr) :: d
        end subroutine C_SimpleF__passFptr

        subroutine C_SimpleF__passFptr2D(this, N, d) bind(C,name="SimpleF__passFptr2D")
            import
            integer(C_INT), value :: N
            type(C_ptr), value :: this
            ! integer(C_int), pointer :: d(:,:,:)
            type(C_ptr) :: d
        end subroutine C_SimpleF__passFptr2D

        subroutine C_SimpleF__passFptr3D(this, N, d) bind(C,name="SimpleF__passFptr3D")
            import
            integer(C_INT), value :: N
            type(C_ptr), value :: this
            ! integer(C_int), pointer :: d(:,:,:)
            type(C_ptr) :: d
        end subroutine C_SimpleF__passFptr3D

        ! function C_SimpleF__vecgetB(this) result(b) bind(C,name="SimpleF__vecgetB")
        !     import
        !     type(C_ptr) :: b
        !     type(C_ptr), value :: this
        ! end function C_SimpleF__vecgetB

        subroutine getArray(N, arr) bind(C, name="getArray")
            import
            integer(c_int), value :: N
            integer(C_int) :: arr(N*N)
        end subroutine getArray

        subroutine getPtr(N,p) bind(C,name="getPtr")
            import
            integer(C_int), value :: N
            type(C_ptr) :: p
        end subroutine getPtr

        subroutine get2DPtr(N,p) bind(C,name="get2DPtr")
            import
            integer(C_int), value :: N
            type(C_ptr) :: p
        end subroutine get2DPtr

        subroutine get3DPtr(N,p) bind(C,name="get3DPtr")
            import
            integer(C_int), value :: N
            type(C_ptr) :: p
        end subroutine get3DPtr

        subroutine get4DPtr(N,p) bind(C,name="get4DPtr")
            import
            integer(C_int), value :: N
            type(C_ptr) :: p
        end subroutine get4DPtr

        function getLogic(R) result(logic) bind(C, name="getLogic")
            import
            integer(C_int), value :: R
            logical(C_bool) :: logic
        end function getLogic
        

    end interface
    
contains

    subroutine SimpleF__new(this, a, Fstr)
        type(simp), intent(out) :: this
        integer(C_INT), value :: a
        ! character(C_char),  dimension(*), intent(in) :: Fstr
        ! character(C_char), intent(in) :: Fstr
        character(256,C_char) :: Fstr
        write(*,*) "In SimpleF_mod.F90: creating object"
        this%object = C_SimpleF__new(a,Fstr)
    end subroutine SimpleF__new

    subroutine SimpleF__setA(this, a)
        type(simp) :: this
        integer, value :: a
        write(*,*) "In SimpleF_mod.F90: passing a =", a
        call C_SimpleF__setA(this%object,a)
    end subroutine SimpleF__setA

    function SimpleF__getA(this) result(a)
        type(simp), intent(in) :: this
        integer :: a
        a = C_SimpleF__getA(this%object)
    end function SimpleF__getA

    ! function SimpleF__getFstr(this) result(Fstr)
    !     type(simp), intent(in) :: this
    !     character(256) :: Fstr
    !     ! type(C_ptr) :: Fstr
    !     ! Fstr = C_SimpleF__getFstr(this%object)
    !     call C_SimpleF__getFstr(this%object, Fstr)
    ! end function SimpleF__getFstr
    subroutine SimpleF__getFstr(this, Fstr)
        type(simp), intent(in) :: this
        character(256) :: Fstr
        write(*,*) "In SimpleF_mod.F90: passing test string as: ", Fstr
        ! type(C_ptr) :: Fstr
        ! Fstr = C_SimpleF__getFstr(this%object)
        call C_SimpleF__getFstr(this%object, Fstr)
        ! call C2Fstring(Fstr)
    end subroutine SimpleF__getFstr

    subroutine SimpleF__setB(this, n, b)
        type(simp) :: this
        integer :: n
        integer :: b(n)
        write(*,*) "In SimpleF_mod.F90: passing n and b =", n, b
        call C_SimpleF__setB(this%object,n,b)
    end subroutine SimpleF__setB

    subroutine SimpleF__setC(this, n, b)
        type(simp) :: this
        integer :: n
        integer :: b(n,n)
        write(*,*) "In SimpleF_mod.F90: passing n = ", n," and C =", b
        call C_SimpleF__setC(this%object,n,b)
    end subroutine SimpleF__setC

    subroutine SimpleF__getB(this, n, b2)
        type(simp), intent(in) :: this
        integer, value :: n
        integer :: b2(n)
        ! b = C_SimpleF__getB(this%object, n)
        write(*,*) "In SimpleF_mod.F90: passing b junk values as ", b2
        call C_SimpleF__getB(this%object, n, b2)
    end subroutine SimpleF__getB

    subroutine SimpleF__passFptr(this, n, d)
        use iso_c_binding
        type(simp), intent(in) :: this
        integer, pointer :: d(:)
        integer, value :: n
        type(C_PTR) :: p
        write(*,*) "In SimpleF_mod.F90' SimpleF_passFptr: passing d values as ", d
        ! call C_F_POINTER(p,d,[n])
        p = C_LOC(d(:))
        call C_SimpleF__passFptr(this%object, n, p)
    end subroutine SimpleF__passFptr

    subroutine SimpleF__passFptr2D(this, n, d)
        use iso_c_binding
        type(simp), intent(in) :: this
        integer, pointer :: d(:,:)
        integer, value :: n
        type(C_PTR) :: p
        write(*,*) "In SimpleF_mod.F90' SimpleF_passFptr2D: passing d values as ", d
        ! call C_F_POINTER(p,d,[n])
        p = C_LOC(d(:,:))
        call C_SimpleF__passFptr2D(this%object, n, p)
    end subroutine SimpleF__passFptr2D

    subroutine SimpleF__passFptr3D(this, n, d)
        use iso_c_binding
        type(simp), intent(in) :: this
        integer, pointer :: d(:,:,:)
        integer, value :: n
        type(C_PTR) :: p
        write(*,*) "In SimpleF_mod.F90' SimpleF_passFptr3D: passing d values as ", d
        ! call C_F_POINTER(p,d,[n])
        p = C_LOC(d(:,:,:))
        call C_SimpleF__passFptr3D(this%object, n, p)
    end subroutine SimpleF__passFptr3D

    function SimpleF__funsubgetB(this,n,b2) result(b)
        implicit none
        integer :: n
        type(simp), intent(in) :: this
        integer, pointer :: b(:)
        integer, target :: b2(:)
        call C_SimpleF__getB(this%object, n, b2)
        b => b2
        ! write(*,*) "In SimpleF_mod.F90: junk b values are"
    end function SimpleF__funsubgetB

    function SimpleF__funsubgetC(this,n,b2) result(b)
        implicit none
        integer :: n
        type(simp), intent(in) :: this
        integer, pointer :: b(:,:)
        integer, target :: b2(:,:)
        write(*,*) "In SimpleF_mod.F90: receiving junk values of C: ", b2
        call C_SimpleF__getC(this%object, n, b2)
        b => b2
        ! write(*,*) "In SimpleF_mod.F90: junk b values are"
    end function SimpleF__funsubgetC

    ! function SimpleF__ptrgetB(this) result(b)
    !     type(simp), intent(in) :: this
    !     type(c_ptr) :: b
    !     b = C_SimpleF__vecgetB(this%object)        
    ! end function SimpleF__ptrgetB


end module SimpleF_mod
