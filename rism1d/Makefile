# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lgfortran -lstdc++ 

# comment below to: cpp accessing F90
main: main.F90 simple_mod.o simple2_mod.o SimpleF_mod.o main.o
	$(GF90) simple_mod.o simple2_mod.o SimpleF_mod.o main.o main.F90 -o main $(LDLIBS)

simple_mod.o: simple_mod.F90
	$(GF90) -c simple_mod.F90

main.o: main.cpp 
	$(CC) -c main.cpp

SimpleF_mod.o: SimpleF_mod.F90
	$(GF90) -c SimpleF_mod.F90
	
simple2_mod.o: simple2_mod.F90
	$(GF90) -c simple2_mod.F90 

# uncomment below to: cpp accessing F90
# main: main.cpp simple_mod.o simple2_mod.o
# 	$(GF90) simple_mod.o simple2_mod.o main.cpp -o main $(LDLIBS)

# simple_mod.o: simple_mod.F90
# 	$(GF90) -c simple_mod.F90

# simple2_mod.o: simple2_mod.F90
# 	$(GF90) -c simple2_mod.F90 
