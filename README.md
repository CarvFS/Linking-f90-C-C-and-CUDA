# First steps in linking FORTRAN code with C++ and CUDA

## Calling function from c++ class from fortran

To do:

- [ ] access class variables from fortran

- [ ] modify class variables from fortran

This procedure involves the files `rism1d.F90` and `rism1d_c.cpp`. Give the following commands:

- g++ -c rism1d_c.cpp
- gfortran -o testrism1d rism1d.F90 rism1d_c.o -lstdc++

By running `./testrism1d` one must get the following output:

  ```
  kh
  ```

## Calling fortran function and subrouting (located in a module) from C++

This procedure involves the files `test_module.F90`, `test_module_func.F90` and `main_test_module.cpp`. Give the following commands:

- gfortran -c test_module.F90
- gfortran -c test_module_func.F90
- g++ -o main main_test_module.cpp test_module.o test_module_func.o -lgfortran

By running `./main` one must get the following output:

  ```
  Calling fortran function from C++!
  3
  Calling fortran subroutine from C++
     3.0000000000000000
  ```

## Running .cpp program taht calls CUDA

This procedure involves the files `cpp_caller.cpp` and `test_cuda_c.cu`. Give the following commands:

- nvcc -c test_cuda_c.cu
- g++ -o cppcall -L/usr/local/cuda/lib64 -lcuda -lcudart cpp_caller.cpp  test_cuda_c.o

By running `./cppcall` one must get the following output:

  ```
  Hello from C++!
  Hello from thread 0 at block 0!
  Hello from thread 1 at block 0!
  Hello from thread 0 at block 1!
  Hello from thread 1 at block 1!
  The end...
  ```

## Running .f90 program that calls C++, which calls CUDA

This procedure involves the files `test_Cpp_c.cpp`, `test_C_c.c`, `test_cuda_c.cu` and `test.f90`. Give the following commands:

- nvcc -c test_cuda_c.cu
- g++ -c test_Cpp_c.cpp
- gcc -c test_C_c.c
- gfortran -o test -L/usr/local/cuda/lib64 -lcuda -lcudart test.f90 test_C_c.o test_Cpp_c.o test_cuda_c.o -lstdc++

By running `./test` one must get the following output:

  ```
  Hello from C!
  Hello from C++!
  Hello from thread 0 at block 0!
  Hello from thread 1 at block 0!
  Hello from thread 0 at block 1!
  Hello from thread 1 at block 1!
  ```
