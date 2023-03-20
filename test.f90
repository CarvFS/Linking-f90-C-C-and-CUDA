program main

! Setting up C types
    use iso_c_binding

! Creating interface to call from C/C++
    interface
        subroutine say_hello_c() bind( C, name = "say_hello_c")
!            
        end subroutine say_hello_c

        subroutine say_hello_cpp() bind( C, name = "say_hello_cpp")
!            
        end subroutine say_hello_cpp

        subroutine say_hello_cuda() bind(C, name = "calling_cuda")
!
        end subroutine say_hello_cuda

    end interface

! Calling subroutines to test if it is working
    call say_hello_c()

    call say_hello_cpp()

    call say_hello_cuda()

end program