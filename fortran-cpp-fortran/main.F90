program main_program
    use iso_c_binding
    use SimpleF_mod
    implicit none
    integer :: a
    type(simp) :: s
    a = 4321 
    write(*,*) "In main.90: creating object"
    call SimpleF__new(s)
    write(*,*) "In main.90: print value of a defined at Simple_mod.F90..."
    write(*,*) "a = ", SimpleF__getA(s)
    write(*,*) "In main.90: defining new value for a..."
    call SimpleF__setA(s, a)
    write(*,*) "In main.90: print new value for a..."
    write(*,*) "new a is... ", SimpleF__getA(s)
end program main_program
