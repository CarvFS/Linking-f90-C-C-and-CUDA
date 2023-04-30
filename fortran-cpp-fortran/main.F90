program main_program
    use iso_c_binding
    use SimpleF_mod
    implicit none
    integer :: a
    integer :: new_a
    type(simp) :: s
    new_a = 4321 
    write(*,*) "In main.90: creating object"
    call SimpleF__new(s)
    write(*,*) "In main.90: get value of a defined at Simple_mod.F90..."
    a = SimpleF__getA(s)
    write(*,*) "In main.90: a = ", a
    write(*,*) "In main.90: defining new value for a as ", new_a
    call SimpleF__setA(s, new_a)
    write(*,*) "In main.90: get new value for a..."
    a = SimpleF__getA(s)
    write(*,*) "In main.90: new a is ", a
end program main_program
