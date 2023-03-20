// Working along with .90 code
#include <stdio.h> // Not normally used in c++
#include "test.cuh"

extern "C" void say_hello_cpp(void); // it seems that this must be included to work using .cpp files
extern "C" void wrapperfunction(void);

void say_hello_cpp(void){
    printf("Hello from C++!\n");
}

void say_hello_cuda(void){
    void wrapperfunction();
}


/*Not working with .90 code

#include <iostream>
using namespace std;
extern "C" void say_hello_cpp(int the_answer);

void say_hello_cpp(int the_answer){
    cout << "Hello from C++!" << endl;
    cout << "The answer is: " << the_answer << endl;
}

*/