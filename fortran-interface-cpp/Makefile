# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lgfortran -lstdc++ 

main: FirstMod_cpp.o FirstMod.o main.F90
	$(GF90) FirstMod_cpp.o FirstMod.o main.F90 -o main $(LDLIBS)

FirstMod.o: FirstMod.F90 FirstMod_cpp.o
	$(GF90) -c FirstMod.F90

FirstMod_cpp.o: FirstMod_cpp.cpp 
	$(CC) -c FirstMod_cpp.cpp
