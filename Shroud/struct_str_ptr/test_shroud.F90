program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr
    character(len = 4), pointer :: names(:)
    allocate(names(2))

    !!!!! Create object
    cptr = Class1() 
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    call class1_set_strings(cptr)
    call class1_printvalues(cptr)

    !!> Getting int* data from C++
    !!> Print
    ! write(*,*) class1_get_int_ptr(cptr)

    call class1_get_strs(cptr,names)
    write(*,*) "String returned from C++: ", names(1), ", ", names(2)
    ! call test_receive_str(names,2)

    !!!!! Delete object
    call cptr%delete()
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
end program test_shroud

subroutine test_receive_str(fstrs, names_size)
    integer :: names_size
    character(len = 4) :: fstrs(names_size)
    do i = 1,names_size
        write(*,*) "in subroutine: String returned from C++: ", fstrs(i)
    end do
end subroutine test_receive_str