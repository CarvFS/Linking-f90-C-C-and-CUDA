program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr
    character(len = 4), pointer :: names(:)

    !!!!! Create object
    cptr = Class1() 

    call class1_set_strings(cptr)
    call class1_printvalues(cptr)

    !!> Getting int* data from C++
        !!> Print 1D array
    write(*,*) class1_get_int_ptr(cptr)

        !!> Get array of strings
    call class1_get_strs(cptr,names)

        !!> Verify the values retrieved from C++
    call test_receive_str(names,4)

    !!!!! Delete object
    call cptr%delete()
end program test_shroud

subroutine test_receive_str(fstrs, names_size)
    integer :: names_size
    character(len = 4) :: fstrs(names_size)
    do i = 1,names_size
        write(*,*) "in subroutine: String returned from C++: ", fstrs(i)
    end do
end subroutine test_receive_str