# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lgfortran -lstdc++ 

test_shroud: tutorial.o wraptutorial_Class1.o wrapfTutorial_tutorial.o test_shroud.F90
	$(GF90) tutorial.o wraptutorial_Class1.o wrapfTutorial_tutorial.o test_shroud.F90 -o main $(LDLIBS)

wrapfTutorial_tutorial.o: wraptutorial_Class1.o wrapfTutorial_tutorial.F90
	$(GF90) -c wrapfTutorial_tutorial.F90

wraptutorial_Class1.o: wraptutorial_Class1.cpp tutorial.o
	$(CC) -c wraptutorial_Class1.cpp

tutorial.o: tutorial.cpp
	$(CC) -c tutorial.cpp