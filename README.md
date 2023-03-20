# First steps in linking FORTRAN code with C++ and CUDA

## Running .f90 program that calls C++, which calls CUDA

Give the following commands:

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
