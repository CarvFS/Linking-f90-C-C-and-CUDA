program main_test
use FirstMod

type(firstex_v1), pointer :: FTptr
type(firstex_v2), pointer :: FTptr2
type(firstex_v2), target :: FT2
type(firstex_v1), target :: FT
integer :: a = 123
real*8 :: dk = 0.25
character(len=256) :: Fstr = "Resturning from C++!"//char(0)

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

FTptr => FT

write(*,*) "In main.90: Values to initialize: a = ", a, "dk = ", dk, "Fstr = ", Fstr, "..."
write(*,*) " "
write(*,*) "In main.90: Printing object members before initialization:"
write(*,*) "a in mod = ", FT%a, "dk in mod = ", FT%dk

write(*,*) " "
write(*,*) "In main.90: INITIALIZING..."

call FirstMod_new_v1(FTptr, a, dk)

write(*,*) " "
write(*,*) "In main.90: Printing object members after initialization:"
write(*,*) "In main.90: a in mod = ", FT%a, "dk in mod = ", FT%dk

!!> USING DEFINED TYPE AS IN FORTRAN:
write(*,*) " "
write(*,*) " "
write(*,*) "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
write(*,*) "                USING DEFINED TYPE AS IN FORTRAN"
write(*,*) "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
write(*,*) " "
write(*,*) " "

FT2%a = 321
FT2%dk = 0.123
FT2%Fstr = "testing"//char(0)

FTptr2 => FT2

write(*,*) "In main.90: Printing object members before initialization:"
write(*,*) "In main.90: a in mod = ", FT2%a, "dk in mod = ", FT2%dk, "Fstr in mod = ", trim(FT2%Fstr), "..."

write(*,*) " "
write(*,*) "In main.90: INITIALIZING..."

call FirstMod_new_V2(FTptr2, a, dk, Fstr//char(0))

write(*,*) "In main.90: Printing object members after initialization:"
write(*,*) "In main.90: a in mod = ", FT2%a, "dk in mod = ", FT2%dk, "Fstr in mod = ", trim(FT2%Fstr), "..."

end program main_test
