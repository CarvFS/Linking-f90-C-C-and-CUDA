module test_module

    implicit none 

    type my_type

        double precision :: a
        double precision :: b

    end type my_type

    contains

    subroutine add_ab()

        type(my_type) var
        var%a = 1.0
        var%b = 2.0

        print *, var%a + var%b

    end subroutine add_ab

end module test_module