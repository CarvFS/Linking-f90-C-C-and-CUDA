program test_shroud
    use iso_c_binding
    use tutorial_tutorial_mod
    ! implicit none
    type(class1) cptr
    integer, pointer :: f_1darray(:), val_ptr(:)
    integer, pointer :: f_2darray(:,:), vec2d(:,:)
    real(C_DOUBLE) :: dk2
    character(len = 8), pointer :: closure_list(:) => NULL()
    character(len = 16), pointer :: word => NULL()
    integer, target :: val(3)
    integer :: i,j,N,M

    N=4
    M=2

    allocate(closure_list(3),val_ptr(3),word, vec2d(2,2))

    vec2d(1,1) = 123
    vec2d(1,2) = 234
    vec2d(2,1) = 321
    vec2d(2,2) = 432

    closure_list(1) = "kh"
    closure_list(2) = "pse2"
    closure_list(3) = "pse3"

    ! write(*,*) closurelist

    !!!!! Create object
    cptr = Class1(1,0.1d0,.true.,123456,0.555d0,.false.) 
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    call cptr%set_test(N)
    call cptr%set__two_darray(N,M)

    ! call cptr%accept_char_array_in(in)
    call cptr%accept_char_array_in(closure_list)
    
    f_1darray => cptr%get_test_ptr()

    ! f_2darray => cptr%get__two_darray_ptr()
    ! f_2darray => class1_get_2d_new(cptr)

    call cptr%accept_char_array_in(closure_list)

    write(*,*) "1D array is: "
    write(*,*) cptr%get_test_ptr()
    ! do i = 1,N
    !     write(*,*) "1Darray(",i,") = ", f_1darray(i)
    ! end do

    write(*,*) "2D array (:,arg) is: "
    write(*,*) cptr%get_2d_new(2)

    write(*,*) "2D array (arg1,arg2) is: "
    write(*,*) cptr%get_2d_new(3,2)

    ! call test_on_F(class1_get_2d_new(cptr),N,M)

    ! do i = 1,N 
    !     do j = 1,M 
    !         write(*,*) "2Darray(",i,",",j,") = ", f_2darray(i,j)
    !     end do
    ! end do

    write(*,*) cptr%check(10)

    write(*,*) "::::::::::::::::::Calling method1::::::::::::::::::"
    val(1) = 120
    val(2) = 432
    val(3) = 1234

    val_ptr => val

    word = "redefined"

    ! call cptr%method1(vec2d)
    ! call cptr%method1(vec2d, 2)
    ! call cptr%method1(vec2d, 2, val_ptr)
    call cptr%method1(vec2d, 2, val_ptr, word)
    ! call class1_method1(cptr, vec2d, 2, val_ptr, word, .false.)
    
    write(*,*) "::::::::::::::::::::::::::::::::::::::::::::::::::"
    ! dk2 = class1_get_dk(cptr) !! also works this way
    dk2 = cptr%get_dk()

    write(*,*) "In test_shroud.F90: Retrieving dk from NewClass... dk = ", dk2

    ! write(*,*) "In test_shroud.F90: Retrieving intValue: ", class1_get_intvalue(cptr)

    ! write(*,*) "test pure", test_pure(cptr)

    call cptr%delete()

    contains 
        subroutine test_on_F(f_arr,N,M)
            integer, intent(in) :: N
            integer, intent(in) :: M
            integer :: f_arr(N,M)
            write(*,*) "========================== On test_on_F =========================="
            do i = 1,N 
                do j = 1,M 
                    write(*,*) "array(",i,",",j,") = ", f_arr(i,j)
                end do
            end do
            write(*,*) "=================================================================="
        end subroutine test_on_F

        ! function test_pure(obj) result(array)
        !     type(class1) :: obj
        !     ! integer, intent(in) :: value
        !     integer :: array(obj%get_intvalue()),i
            
        !     do i=1,obj%get_intvalue()
        !         array(i) = 1+i
        !     end do
        ! end function test_pure
end program test_shroud
