program main_program
    use iso_c_binding
    use SimpleF_mod
    implicit none
    integer :: a
    integer :: new_a
    CHARACTER(256) :: Fstr = "Test for passing string F-Cpp-F"
    CHARACTER(256) :: Cstr, new_char, new_char_f
    integer :: b(2), b2(2)
    type(simp) :: s
    b(1) = 123
    b(2) = 543
    ! write(*,*) "b = ", b
    
    call F2Cstring(Fstr,Cstr)

    write(*,*) "In main.90: !!!!! CREATING OBJECT !!!!!"
    write(*,*) "In main.90: defining Fstr as: ", Trim(Fstr), "..."
    call SimpleF__new(s,7654,Cstr)

    write(*,*) " "
    write(*,*) "In main.90: !!!!! GET PRE-DEFINED A from Simple_mod.F90 !!!!!"
    a = SimpleF__getA(s)
    write(*,*) "In main.90: a = ", a
    new_char = "Test"
    call F2Cstring(new_char,new_char)
    call SimpleF__getFstr(s,new_char)
    ! new_char = SimpleF__getFstr(s)
    write(*,*) "In main.90: get string = ", Trim(new_char), "..."

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

subroutine F2Cstring(Fstr,Cstr)
    CHARACTER(256) :: Fstr
    CHARACTER(256) :: Cstr
    Cstr = Trim(Fstr)//char(0)
end subroutine F2Cstring
