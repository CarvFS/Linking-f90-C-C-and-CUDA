program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr
    integer, pointer :: my_ptr(:)
    character(4) :: name
    integer :: nlen, i, j
    character(len = 4), pointer :: names_from_c(:)
    character(len = 4), pointer :: names_from_c2(:)

    type :: my_type
        integer :: ivalue
        real*8 :: dvalue
        integer, pointer :: intptr(:)
        character(len = 4), pointer :: name_list(:)
        logical :: ToF_f
        real*8, pointer :: arr_2d_f(:,:)
    end type

    type(str1) :: my_str
    type(my_type) :: test

    test%ivalue = 626262
    test%dvalue = 987.54d0

    allocate(my_ptr(2),test%name_list(2),test%arr_2d_f(2,2),names_from_c(2),&
             )

    test%name_list(1) = "Li"
    test%name_list(2) = "John"
    test%ToF_f = .true.

    my_ptr(1)=2
    my_ptr(2)=-11

    do i = 1,2
        do j = 1,2
            test%arr_2d_f(i,j) = 120 + i + (j-1)*2
        end do
    end do

    write(*,*) "In .F90: ", test%name_list(1), ", ",test%name_list(2), ", ", test%ToF_f, test%arr_2d_f

    test%intptr => my_ptr

    my_str%ifield = test%ivalue
    my_str%dfield = test%dvalue
    my_str%iptr = C_LOC(test%intptr)
    my_str%ToF = test%ToF_f
    ! my_str%names = C_LOC(test%name_list)

    my_str%arr_2d = C_LOC(test%arr_2d_f)

    ! write(*,*) "=============== Testing my type created in fortran ==============="
    ! write(*,*) my_str%ifield, my_str%dfield
    ! write(*,*) "=================================================================="

    !!!!! Create object
    cptr = Class1(123321,0.1234d0,.true.,123456,0.555d0,.false.) 
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    call class1_receive_str(cptr, my_str)
    call class1_set_names2(cptr, test%name_list)
    call class1_set_names(cptr, test%name_list)

    deallocate(test%arr_2d_f)
    deallocate(test%intptr)
    ! names_from_c2 = test%name_list
    deallocate(test%name_list)

    call class1_test_names2(cptr)
    call class1_test_struct(cptr)

    ! call class1_get_names2(cptr,test%name_list)
    ! write(*,*) test%name_list, "..."
    
    do i=1,2
        call class1_get_name(cptr, name, i-1)
        names_from_c(i) = name
    end do

    write(*,*) "String returned from C++: ", names_from_c(1), ", ", names_from_c(2)

    call class1_get_name2(cptr, names_from_c2)
    call test_receive_str(names_from_c2,2)

    call test_receive_obj(cptr)

    !!!!! Delete object
    call cptr%delete()
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
end program test_shroud

subroutine test_receive_str(names, names_size)
    integer :: names_size
    character(len = 4) :: names(names_size)
    write(*,*) "String returned from C++: ", trim(names(1)), ", ", trim(names(2))
end subroutine test_receive_str

subroutine test_receive_obj(this)
    use tutorial_tutorial_mod
    type(class1) this
    print*,"====================================================="
    print*, "On subroutine test_receive_obj"
    call class1_test_struct(this)
end subroutine test_receive_obj