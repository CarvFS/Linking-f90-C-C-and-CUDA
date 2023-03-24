# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lstdc++

rism1d: rism1d_c.o rism1d.F90
	$(GF90) rism1d_c.o rism1d.F90 -o rism1d $(LDLIBS)

rism1d_c.o: rism1d_c.cpp
	$(CC) -c rism1d_c.cpp


rism1d_c.cpp: rism1d_c.h
