program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr
    character(len=4), pointer :: str(:)
    character(len=4) :: names(10)
    ! character(len=:), allocatable :: names(:)
    integer :: char_len

    !!!!! Create object
    cptr = Class1() 

    ! char_len = len(names)
    ! char_len = 4

    allocate(str(3))
    str(1) = "Na+"
    str(2) = "K+"
    str(3) = "Cl-"

    call class1_set_strings(cptr,str)
    ! call class1_printvalues(cptr)

    ! !!> Getting int* data from C++
    !     !!> Print 1D array
    ! write(*,*) class1_get_int_ptr(cptr)

    !     !!> Get array of strings

    call Class1_get_strs2(cptr,names)
    print*,names

        !!> Verify the values retrieved from C++
    ! call test_receive_str(names,char_len)

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