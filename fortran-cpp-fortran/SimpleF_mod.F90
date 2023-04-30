module SimpleF_mod

    use iso_c_binding
    implicit none

    type,bind(C) :: simp
        private
        type(C_ptr) :: object = C_NULL_ptr
    end type simp

    interface

        function C_SimpleF__new() result(this) bind(C,name="SimpleF__new")
            import
            type(C_ptr) :: this
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

    end interface
    
contains

    subroutine SimpleF__new(this)
        type(simp), intent(out) :: this
        this%object = C_SimpleF__new()
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

end module SimpleF_mod
