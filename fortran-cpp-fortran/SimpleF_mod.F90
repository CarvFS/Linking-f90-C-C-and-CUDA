module SimpleF_mod

    use iso_c_binding
    implicit none

    type,bind(C) :: simp
        private
        type(C_ptr) :: object = C_NULL_ptr
    end type simp

    interface

        function C_SimpleF__new(a) result(this) bind(C,name="SimpleF__new")
            import
            type(C_ptr) :: this
            integer(C_INT), value :: a
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

        subroutine C_SimpleF__setB(this, n, b) bind(C,name="SimpleF__setB")
            import
            integer(C_INT), value :: n
            integer(C_INT) :: b(n)
            type(C_ptr), value :: this
        end subroutine C_SimpleF__setB

        subroutine C_SimpleF__getB(this, n, b2) bind(C,name="SimpleF__getB")
            import
            integer(C_int), value :: n
            integer(C_INT) :: b2(n)
            type(C_ptr), value :: this
        end subroutine C_SimpleF__getB

    end interface
    
contains

    subroutine SimpleF__new(this, a)
        type(simp), intent(out) :: this
        integer(C_INT), value :: a
        write(*,*) "In SimpleF_mod.F90: creating object"
        this%object = C_SimpleF__new(a)
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

    subroutine SimpleF__setB(this, n, b)
        type(simp) :: this
        integer :: n
        integer :: b(n)
        write(*,*) "In SimpleF_mod.F90: passing n and b =", n, b
        call C_SimpleF__setB(this%object,n,b)
    end subroutine SimpleF__setB

    subroutine SimpleF__getB(this, n, b2)
        type(simp), intent(in) :: this
        integer, value :: n
        integer :: b2(n)
        ! b = C_SimpleF__getB(this%object, n)
        write(*,*) "In SimpleF_mod.F90: passing b junk values as ", b2
        call C_SimpleF__getB(this%object, n, b2)
    end subroutine SimpleF__getB

    ! function SimpleF__getB(this, n, b2) result(b)
    !     type(simp), intent(in) :: this
    !     integer, value :: n
    !     integer :: b2(n),b(n)
    !     ! b = C_SimpleF__getB(this%object, n)
    !     write(*,*) "In SimpleF_mod.F90: passing b values as ", b2
    !     call C_SimpleF__getB(this%object, n, b2)
    !     b = b2
    ! end function SimpleF__getB

end module SimpleF_mod
