program main_test
use FirstMod
use iso_c_binding

type(firstex_v1), pointer :: FTptr
type(firstex_v2), pointer :: FTptr2
type(firstex_v2), target :: FT2
type(firstex_v1), target :: FT
integer :: a = 123, N_1d, i
integer, pointer :: Bptr(:), B2Dptr(:,:)
integer, target :: B_arr(3), B_2Darr(3,3)
real*8 :: dk = 0.25
character(len=256) :: Fstr = "Returning from C++!!!"//char(0)
character(len=256), pointer :: Fstr_ptr
character(len=256), target :: Fstr_test = "Testing"//char(0)

allocate(FTptr,FTptr2,Fstr_ptr)

!!> USING DEFINED TYPE WITH BIND(C):
write(*,*) " "
write(*,*) " "
write(*,*) "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
write(*,*) "                  USING DEFINED TYPE WITH BIND(C)"
write(*,*) "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
write(*,*) " "
write(*,*) " "

FT%a = 321
FT%dk = 0.123
Fstr_ptr => Fstr_test
FT%Fstr = C_LOC(Fstr_ptr)

N_1d = 3
Allocate(Bptr(N_1d),B2Dptr(N_1d,N_1d))

do i=1,N_1d
    B_arr(i) = 320+i
    do j=1,N_1d
        B_2Darr(i,j) = 210+N_1d*i+j
        ! write(*,*) "i,j,B2D = ", i,j,B_2Darr(i,j) !print and check values
    end do
end do

Bptr => B_arr
B2Dptr => B_2Darr
FT%B = C_LOC(Bptr)
FT%B2 = C_LOC(B_2Darr)

FTptr => FT

write(*,*) "In main.90: Values to initialize: a = ", a, "dk = ", dk, "Fstr = ", trim(Fstr), "..."
write(*,*) " "
write(*,*) "In main.90: Printing object members before initialization:"
write(*,*) "a in mod = ", FT%a, "dk in mod = ", FT%dk, "Fptr in mod = ", trim(Fstr_ptr), "...", ", B = ", Bptr, ", B 2D =", B2Dptr

write(*,*) " "
write(*,*) "In main.90: INITIALIZING..."

call FirstMod_new_v1(FTptr, N_1d, a, dk, Fstr)

write(*,*) " "
write(*,*) "In main.90: Printing object members after initialization:"

write(*,*) "In main.90: a in mod = ", FT%a, "dk in mod = ", FT%dk, "Fstr = ", trim(Fstr_ptr), "...", ", B = ", Bptr
write(*,*) "B2 = "
do i=1,N_1d
    do j=1,N_1d
        write(*,*) "B2(",i,",",j,") = ", B2Dptr(i,j)
    end do
end do

!!> USING DEFINED TYPE AS IN FORTRAN:
! write(*,*) " "
! write(*,*) " "
! write(*,*) "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
! write(*,*) "                USING DEFINED TYPE AS IN FORTRAN"
! write(*,*) "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
! write(*,*) " "
! write(*,*) " "

! FT2%a = 321
! FT2%dk = 0.123
! FT2%Fstr = "testing"//char(0)

! FTptr2 => FT2

! write(*,*) "In main.90: Printing object members before initialization:"
! write(*,*) "In main.90: a in mod = ", FT2%a, "dk in mod = ", FT2%dk, "Fstr in mod = ", trim(FT2%Fstr), "..."

! write(*,*) " "
! write(*,*) "In main.90: INITIALIZING..."

! N_1d = 3
! B_arr(1) = 321
! B_arr(2) = 321
! B_arr(3) = 321

! FT2%B => B_arr

! call FirstMod_new_V2(FTptr2, N_1d, a, dk, Fstr//char(0))

! write(*,*) "In main.90: Printing object members after initialization:"
! write(*,*) "In main.90: a in mod = ", FT2%a, "dk in mod = ", FT2%dk, "Fstr in mod = ", trim(FT2%Fstr), "..."
! write(*,*) "In main.90: B in mod:"
! do i = 1,N_1d
!     write(*,*) "B(",i,") = ", FT2%B(i)
! end do

end program main_test
