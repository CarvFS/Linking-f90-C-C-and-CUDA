# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lgfortran -lstdc++ 

test_shroud: tutorial.o wrapClass1.o wrapftutorial.o test_shroud.F90
	$(GF90) tutorial.o wrapClass1.o wrapftutorial.o test_shroud.F90 -o main $(LDLIBS)

wrapftutorial.o: wrapClass1.o wrapftutorial.F90
	$(GF90) -c wrapftutorial.F90

wrapClass1.o: wrapClass1.cpp tutorial.o
	$(CC) -c wrapClass1.cpp

tutorial.o: tutorial.cpp
	$(CC) -c tutorial.cpp
