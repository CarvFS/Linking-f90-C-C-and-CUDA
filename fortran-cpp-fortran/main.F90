program main_program
    use iso_c_binding
    use interface_mod
    implicit none
    integer :: a
    type(simp) :: s
    a = 123    
    call Set_A(s,a)
    !write(*,*) get_a(s)
end program main_program
