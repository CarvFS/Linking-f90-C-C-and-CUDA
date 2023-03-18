program main

! Calling from C
!    use iso_c_binding, only : c_int
!
!    interface
!        subroutine say_hello(the_answer) bind( C, name = "say_hello_c")
!            use iso_c_binding, only : c_int
!            integer(c_int), value :: the_answer
!            end subroutine
!    end interface
!
!    integer ( c_int ), parameter :: the_answer = 3
!
!    call say_hello(the_answer)
       
! Calling from C++
    use iso_c_binding, only : c_int

    interface
        subroutine say_hello(the_answer) bind( C, name = "say_hello_cpp")
            use iso_c_binding, only : c_int
            integer(c_int), value :: the_answer
            end subroutine say_hello
    end interface

    integer ( c_int ), parameter :: the_answer = 5

    call say_hello(the_answer)

! (to do) Calling from c++ which calls CUDA kernel

end program