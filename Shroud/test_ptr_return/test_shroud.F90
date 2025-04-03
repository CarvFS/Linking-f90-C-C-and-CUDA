program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr

    REAL, pointer :: f_val1
    REAL*8, pointer :: f_val2
    REAL*8, pointer :: data(:) 
    integer :: index

    allocate(f_val1, f_val2)

    f_val1 = 4.0d0/7.0d0
    f_val2 = 4.0d0/7.0d0

    print*, "float: ", f_val1
    print*, "double: ", f_val2
    
    !!!!! Create object
    cptr = Class1() 

    call class1_test(cptr,f_val1,f_val2)

    do index=1,2
        ! !! Testing get_data function on fortran side
        ! data => class1_get_data(cptr, index)
        ! print*, "In Fortran: Extracted data for index ", index
        ! print*, data 

        !! Calling print data while passing class1_get_data as argument
        call class1_print_data(cptr, class1_get_data(cptr, index))
    end do

    call cptr%delete()
end program test_shroud
