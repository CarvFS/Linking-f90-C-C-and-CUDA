program main

! Calling from C
    use iso_c_binding, only : c_int

    interface
        subroutine say_hello_c(the_answer) bind( C, name = "say_hello_c")
                use iso_c_binding, only : c_int
                integer(c_int), value :: the_answer
        end subroutine say_hello_c

        subroutine say_hello_cpp(the_answer) bind( C, name = "say_hello_cpp")
             use iso_c_binding, only : c_int
            integer(c_int), value :: the_answer
        end subroutine say_hello_cpp
    end interface

    integer ( c_int ), parameter :: the_answer = 3

    call say_hello_c(the_answer)

    call say_hello_cpp(the_answer)

end program