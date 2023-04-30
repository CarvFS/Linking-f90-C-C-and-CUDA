# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lstdc++

rism1d: rism1d_c.o rism1d.F90 rism1d_mod
	$(GF90) rism1d_c.o rism1d.F90 -o rism1d $(LDLIBS)

rism1d_mod: rism1d_mod.F90
	$(GF90) -c rism1d_mod.F90

# Had to modify here, so changes made only on .h would triger this line
rism1d_c.o: rism1d_c.cpp rism1d_c.h
	$(CC) -c rism1d_c.cpp

# rism1d_c.cpp: rism1d_c.h
