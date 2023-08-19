program test_shroud
    use iso_c_binding
    ! use tutorial_tutorial_mod
    use tutorial_mod
    type(class1) cptr

    type :: my_type
        integer :: ivalue
        real*8 :: dvalue
        logical :: ToF_f
    end type

    type(str1) :: my_str
    type(my_type) :: test

    test%ivalue = 6262
    test%dvalue = 987.54d0
    test%ToF_f = .true.

    my_str%ifield = test%ivalue
    my_str%dfield = test%dvalue
    my_str%ToF = test%ToF_f

    !!!!! Create object
    cptr = Class1(123321,0.1234d0,.true.,123456,0.555d0,.false.) 
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    call class1_receive_struct(cptr, my_str)

    call class1_test_struct(cptr)

    ! call class1_get_names2(cptr,test%name_list)
    ! write(*,*) test%name_list, "..."
    
    !!!!! Delete object
    call cptr%delete()
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
end program test_shroud