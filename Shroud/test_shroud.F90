program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    type(class1) cptr
    real(C_DOUBLE) result
    type(C_PTR) :: cptr_array
    type(C_PTR) :: cptr_array_2d
    integer, pointer :: f_1darray(:), val_ptr(:)
    integer, pointer :: f_2darray(:,:)
    real(C_DOUBLE) :: dk,dk2
    character(10) :: in(3) = [ &
     "dog       ", &
     "cat       ", &
     "monkey    "  ]
    character(len = 8), pointer :: closure_list(:) => NULL()
    character(len = 16), pointer :: word(:) => NULL()
    character :: test

    type(C_PTR) :: nsol_val
    integer, pointer :: nsol_val_ptr(:)
    integer, target :: val(3)

    integer :: i,j,N,M
    N=4
    M=2

    allocate(closure_list(3),val_ptr(3),word(1))

    closure_list(1) = "kh"
    closure_list(2) = "pse2"
    closure_list(3) = "pse3"

    ! write(*,*) closurelist

    !! Both ways will work to create the object
    cptr = Class1()
    ! cptr = Class1_new_default() 
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    call cptr%set_test(N)
    call cptr%set__two_darray(N,M)

    ! call cptr%accept_char_array_in(in)
    call cptr%accept_char_array_in(closure_list)
    
    f_1darray => cptr%get_test_ptr()

    f_2darray => cptr%get__two_darray_ptr()

    call cptr%accept_char_array_in(closure_list)

    write(*,*) "1D array is: "
    do i = 1,N
        write(*,*) "1Darray(",i,") = ", f_1darray(i)
    end do

    write(*,*) "2D array is: "
    do i = 1,N 
        do j = 1,M 
            write(*,*) "2Darray(",i,",",j,") = ", f_2darray(i,j)
        end do
    end do

    write(*,*) cptr%check(10)

    write(*,*) "::::::::::::::::::Calling method1::::::::::::::::::"
    val(1) = 120
    val(2) = 432
    val(3) = 1234

    val_ptr => val

    word(1) = "redefined"

    ! call cptr%method1()
    ! call cptr%method1(2)
    ! call cptr%method1(2, val_ptr)
    call cptr%method1(2, val_ptr, word(1))

    ! dk2 = class1_get_dk(cptr)
    dk2 = cptr%get_dk()

    write(*,*) "In test_shroud.F90: Retrieving dk from NewClass... dk = ", dk2

    call cptr%delete()
end program test_shroud