program main
! Setting up C types
    use iso_c_binding
    implicit none 

    type, bind(C) :: Fred
    end type Fred
    
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

        subroutine c_function(fred_o) bind(C, name = "c_function")
          import :: Fred
          type(Fred) :: fred_o
        end subroutine c_function
        
        function cplusplus_callback_function(fred_o) bind(C, name="cplusplus_callback_function")
          import :: Fred
          type(Fred) :: fred_o
          type(Fred) :: cplusplus_callback_function
        end function cplusplus_callback_function
    end interface

    type(Fred) :: fred_o
    
! Calling subroutines to test if it is working
    call say_hello_c()

    call say_hello_cpp()

    call say_hello_cuda()

    call c_function(fred_o)

    fred_o = cplusplus_callback_function(fred_o)
    
end program
