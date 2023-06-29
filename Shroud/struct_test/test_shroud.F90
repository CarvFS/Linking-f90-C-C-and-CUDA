program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr

    type :: test_str
        integer :: int_value
        real*8 :: re_value
    end type

    type(str1) :: my_str
    my_str%ifield = 626262
    my_str%dfield = 987.54d0

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