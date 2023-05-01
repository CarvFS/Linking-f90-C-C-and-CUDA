program main_program
    use iso_c_binding
    use SimpleF_mod
    implicit none
    integer :: a
    integer :: new_a
    integer :: b(2), b2(2)
    type(simp) :: s
    b(1) = 12345
    b(2) = 54321
    write(*,*) "b = ", b
    
    write(*,*) "In main.90: !!!!! CREATING OBJECT !!!!!"
    call SimpleF__new(s,765)

    write(*,*) " "
    write(*,*) "In main.90: !!!!! GET PRE-DEFINED A from Simple_mod.F90 !!!!!"
    a = SimpleF__getA(s)
    write(*,*) "In main.90: a = ", a

    write(*,*) " "
    write(*,*) "In main.90: !!!!! DEFINE AND GET NEW VARIABLES !!!!!"
    new_a = 4321 
    write(*,*) "In main.90: defining new value for a as ", new_a
    call SimpleF__setA(s, new_a)
    write(*,*) "In main.90: defining values for b as ", b
    call SimpleF__setB(s,2,b)

    write(*,*) " "
    write(*,*) "In main.90: get new value for a..."
    a = SimpleF__getA(s)
    write(*,*) "In main.90: new a is ", a

    write(*,*) "In main.90: get values for b..."
    call SimpleF__getB(s, 2, b2)
    ! b2 = SimpleF__getB(s,2,b)
    write(*,*) "In main.90: Defined values of b are ", b2
end program main_program
