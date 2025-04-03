# the compiler: gcc for C program, define as g++ for C++
CC = g++
GF90 = gfortran
LDLIBS  = -lgfortran -lstdc++ 

# Targets for both double and float versions
all: main_double main_float

# Double precision executable
main_double: utilTutorial_double.o tutorial_double.o wraptutorial_Class1_double.o wrapfTutorial_tutorial_double.o test_shroud.F90
	$(GF90) utilTutorial_double.o tutorial_double.o wraptutorial_Class1_double.o wrapfTutorial_tutorial_double.o test_shroud.F90 -o main_double $(LDLIBS) -DPRECISION_DOUBLE

wrapfTutorial_tutorial_double.o: wraptutorial_Class1_double.o wrapfTutorial_tutorial.F90
	$(GF90) -c wrapfTutorial_tutorial.F90 -o wrapfTutorial_tutorial_double.o -DPRECISION_DOUBLE

wraptutorial_Class1_double.o: wraptutorial_Class1.cpp tutorial_double.o 
	$(CC) -c wraptutorial_Class1.cpp -o wraptutorial_Class1_double.o -DPRECISION_DOUBLE

tutorial_double.o: tutorial.cpp
	$(CC) -c tutorial.cpp -o tutorial_double.o -DPRECISION_DOUBLE

utilTutorial_double.o: utilTutorial.cpp
	$(CC) -c utilTutorial.cpp -o utilTutorial_double.o -DPRECISION_DOUBLE

# Float precision executable
main_float: utilTutorial_float.o tutorial_float.o wraptutorial_Class1_float.o wrapfTutorial_tutorial_float.o test_shroud.F90
	$(GF90) utilTutorial_float.o tutorial_float.o wraptutorial_Class1_float.o wrapfTutorial_tutorial_float.o test_shroud.F90 -o main_float $(LDLIBS)

wrapfTutorial_tutorial_float.o: wraptutorial_Class1_float.o wrapfTutorial_tutorial.F90
	$(GF90) -c wrapfTutorial_tutorial.F90 -o wrapfTutorial_tutorial_float.o 

wraptutorial_Class1_float.o: wraptutorial_Class1.cpp tutorial_float.o 
	$(CC) -c wraptutorial_Class1.cpp -o wraptutorial_Class1_float.o 

tutorial_float.o: tutorial.cpp
	$(CC) -c tutorial.cpp -o tutorial_float.o 

utilTutorial_float.o: utilTutorial.cpp
	$(CC) -c utilTutorial.cpp -o utilTutorial_float.o 

# Clean up compiled files
clean:
	rm -f *.o main_double main_float
