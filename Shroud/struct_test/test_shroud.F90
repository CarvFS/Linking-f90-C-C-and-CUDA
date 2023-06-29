program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr
    integer, pointer :: my_ptr(:)

    type :: my_type
        integer :: ivalue
        real*8 :: dvalue
        integer, pointer :: intptr(:)
    end type

    type(str1) :: my_str
    type(my_type) :: test

    test%ivalue = 626262
    test%dvalue = 987.54d0

    allocate(my_ptr(3))

    my_ptr(1)=1222
    my_ptr(2)=2333
    my_ptr(3)=3444

    test%intptr => my_ptr

    my_str%ifield = test%ivalue
    my_str%dfield = test%dvalue
    my_str%iptr = C_LOC(test%intptr)


    write(*,*) "=============== Testing my type created in fortran ==============="
    write(*,*) my_str%ifield, my_str%dfield
    write(*,*) "=================================================================="

    !!!!! Create object
    cptr = Class1(123321,0.1234d0,.true.,123456,0.555d0,.false.) 
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    call class1_receive_str(cptr, my_str)
    call class1_test_struct(cptr)

    !!!!! Delete object
    call cptr%delete()
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
end program test_shroud