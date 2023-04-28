module interface_mod

    use iso_c_binding
    implicit none

    type,bind(C) :: simp
        integer(C_INT) :: a
    end type simp

    interface

        ! function set_get_a(a) bind(C, name="set_get_a")
        !     use iso_c_binding
        !     integer(C_INT), intent(in), value :: a
        !     integer(C_INT) :: set_get_a
            
        ! end function set_get_a

        subroutine Set_A(this, a) bind(C, name="Set_A")
            use iso_c_binding
            import :: simp
            integer(C_INT), intent(in), value :: a
            type(simp) :: this
        end subroutine Set_A

        function get_a(this) bind(C, name="get_a")
            use iso_c_binding
            import :: simp
            integer(C_INT) :: get_a
            type(simp) :: this
        end function get_a    

    end interface

end module interface_mod
