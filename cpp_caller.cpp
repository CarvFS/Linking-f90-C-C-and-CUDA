#include <stdio.h> // Not normally used in c++

extern void say_hello_cuda();

void say_hello_cpp(){
    printf("Hello from C++!\n");
}

void calling_cuda(){
    say_hello_cuda();
}

int main(){
    
    say_hello_cpp();
    calling_cuda();

    printf("The end...\n");

    return 0;
}