program main_program
    use iso_c_binding
    use SimpleF_mod
    implicit none
    integer :: a,bt,i,j,k,l
    integer :: new_a
    CHARACTER(256) :: Fstr = "Test for passing string F-Cpp-F"
    CHARACTER(256) :: Cstr, new_char, new_char_f
    type(C_ptr) :: cptr
    integer, pointer :: fptr(:),fptr2(:,:),fptr3(:,:,:),fptr_4(:,:,:,:),M(:,:),M2(:,:,:)
    integer, target :: b(2),b2(2),b3(2)
    integer, target :: c(2,2),c2(2,2)
    integer :: N, count
    logical :: logic
    integer :: arr(100000)
    integer, target :: matrix(100000,100000)
    type(simp) :: s

    !> Defining values for b vector 
    b(1) = 123
    b(2) = 543
    
    !> Defining values for c matrix
    c(1,1) = 1
    c(2,1) = 2
    c(1,2) = 3
    c(2,2) = 4

    !> Add a null character at the end of the string, so c++ can have a stop point
    call F2Cstring(Fstr,Cstr)

    !> Create object passing value for 'a' variable and 'Fstr' string
    write(*,*) "In main.90: !!!!! CREATING OBJECT !!!!!"
    write(*,*) "In main.90: defining Fstr as: ", Trim(Fstr), "..."
    call SimpleF__new(s,7654,Cstr)

    !> Getting values asigned during the object creation
    write(*,*) " "
    write(*,*) "In main.90: !!!!! GET PRE-DEFINED A from Simple_mod.F90 !!!!!"
    a = SimpleF__getA(s)
    write(*,*) "In main.90: a = ", a
    new_char = "Test"
    call F2Cstring(new_char,new_char)
    call SimpleF__getFstr(s,new_char)
    write(*,*) "In main.90: get string = ", Trim(new_char), "..."

    !> Changing value of 'a' variable and asigning values for 'b' vector and 'c' matrix
    ! Defining values
    write(*,*) " "
    write(*,*) "In main.90: !!!!! DEFINE AND GET NEW VARIABLES !!!!!"
    new_a = 4321 
    write(*,*) "In main.90: defining new value for a as ", new_a
    call SimpleF__setA(s, new_a)
    write(*,*) "In main.90: defining values for b as ", b
    call SimpleF__setB(s,2,b)
    write(*,*) "In main.90: defining values for C as ", c
    call SimpleF__setC(s,2,c)

    ! getting values
    write(*,*) " "
    write(*,*) "In main.90: get new value for a..."
    a = SimpleF__getA(s)
    write(*,*) "In main.90: new a is ", a

    write(*,*) "In main.90: get values for b..."
    call SimpleF__getB(s, 2, b3)
    write(*,*) "In main.90: Defined values of b are ", b3

    write(*,*) " "
    write(*,*) "In main.F90: getting b values with function/subroutine steps: ", SimpleF__funsubgetB(s,2,b2)

    write(*,*) " "
    c2 = SimpleF__funsubgetC(s,2,c2)
    write   (*,*) "In main.F90: getting C values with function/subroutine steps: ", c2

    do i=1,2
        do j=1,2
            write(*,*) "index i,j = ", i,j, " => ", c2(i,j)
        end do
    end do

    !> FROM HERE ALL FUNTIONS/SUBROUTINES ARE COMMUNICATING IN A F90 -> C++ PROCESS, 
    ! NOT IN F90 -> C++ -> F90 AS PREVIOUS CASES
    ! I WILL BE WORKING ON THIS IN FUTURE EXAMPLES

    !> Receiving arrays from c++
    N=2 ! size for either vector or matrix dimensions
    ! Receiving N*N array
    call getArray(N, arr)
    write(*,*) "In main.F90: Receiving array:"
    do i=1,N*N
        write(*,*) "i = ",i,"arr = ",arr(i)
    end do
    ! Turning it into a NxN matrix
    write(*,*) "In main.F90: Turning it into a NxN matrix:"
    do i = 1,N
        do j = 1,N
            matrix(i,j) = arr(N*(i-1) + j)
            write(*,*) "(i j) = ",i,j,"  mat(i,j) = ",matrix(i,j)
        end do
    end do

    !> Receiving pointers from c++
    !! 1D case
    call getPtr(N,cptr)
    call C_F_POINTER(cptr,fptr,[N])
    
    write(*,*) "In main.F90: the vector received through a pointer is: ", fptr

    !! 2D case
    call get2DPtr(N,cptr)
    call C_F_POINTER(cptr,fptr2,[N,N])

    write(*,*) "In main.F90: the matrix received through a pointer is:"
    do i=1,N
        do j=1,N
            write(*,*) "M[",i,",",j,"] = ", fptr2(i,j)
        end do
    end do

    !! 3D case
    call get3DPtr(N,cptr)
    call C_F_POINTER(cptr,fptr3,[N,N,N])

    write(*,*) "In main.F90: the tensor received through a pointer is:"
    count = 0
    do i=1,N
        do j=1,N
            do k=1,N
                count = count + 1
                write(*,*) "M[",i,",",j,",",k,"] = ", fptr3(i,j,k)! , " || test count = ", count
            end do
        end do
    end do

    !! 4D case    
    call get4DPtr(N,cptr)
    call C_F_POINTER(cptr,fptr_4,[N,N,N,N])

    write(*,*) "In main.F90: the tensor received through a pointer is:"
    count = 0
    do i=1,N
        do j=1,N
            do k=1,N
                do l=1,N
                    count = count + 1
                    write(*,*) "M[",i,",",j,",",k,"] = ", fptr_4(i,j,k,l)! , " || test count = ", count
                end do
            end do
        end do
    end do

    !> Receiving logical from c++
    logic = getLogic(1)
    write(*,*) "In main.F90: received boolean from c++ is ", logic


end program main_program

subroutine F2Cstring(Fstr,Cstr)
    CHARACTER(256) :: Fstr
    CHARACTER(256) :: Cstr
    Cstr = Trim(Fstr)//char(0)
end subroutine F2Cstring
