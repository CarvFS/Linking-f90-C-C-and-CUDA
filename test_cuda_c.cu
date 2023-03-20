#include <stdio.h>

__global__ void test(){
    printf("Hello from thread %d at block %d!\n", threadIdx.x, blockIdx.x);
}

void say_hello_cuda(){
    // your code for initialization, copying data to device memory,
    test<<<2,2>>>(); //kernel call
    cudaDeviceSynchronize();
    //your code for copying back the result to host memory & return
 }