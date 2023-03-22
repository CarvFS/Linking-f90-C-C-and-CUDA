program rism1d_main

    use iso_c_binding
    implicit none 

    interface

        subroutine print_closure() bind(C, name = "print_closure_from_c")

        end subroutine print_closure

    end interface

    call print_closure()

end program rism1d_main