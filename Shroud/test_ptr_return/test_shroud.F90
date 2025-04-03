program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr

    integer :: index
    
    !!!!! Create object
    cptr = Class1() 

    do index=1,2
        !! Calling print data while passing class1_get_data as argument
        call class1_print_data(cptr, class1_get_data(cptr, index))
    end do

    call cptr%delete()
end program test_shroud
