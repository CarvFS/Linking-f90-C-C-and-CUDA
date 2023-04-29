program main_program
    use iso_c_binding
    use SimpleF_mod
    implicit none
    integer :: a
    type(simp) :: s
    a = 123    
    call SimpleF__new(s)
    write(*,*) "a = ", SimpleF__getA(s)
    ! call C_SimpleF__setA(s, a)
    ! write(*,*) SimpleF__getA(s)
end program main_program
