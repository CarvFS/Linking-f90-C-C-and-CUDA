program main

! Calling from C
    use iso_c_binding

    interface
        subroutine say_hello_c() bind( C, name = "say_hello_c")
!            use iso_c_binding, only : c_int
!            integer(c_int), value :: the_answer
        end subroutine say_hello_c

        subroutine say_hello_cpp() bind( C, name = "say_hello_cpp")
!            use iso_c_binding, only : c_int
!            integer(c_int), value :: the_answer
        end subroutine say_hello_cpp

        subroutine say_hello_cuda() bind(C, name = "calling_cuda")
!
        end subroutine say_hello_cuda

    end interface

!    integer ( c_int ), parameter :: the_answer = 3

    call say_hello_c()

    call say_hello_cpp()

    call say_hello_cuda()

end program