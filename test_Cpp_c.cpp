// Working along with .90 code
#include <stdio.h> // Not normally used in c++
#include "test.cuh"

extern "C" void say_hello_cpp(void); // it seems that this must be included to work using .cpp files
extern "C" void calling_cuda();
extern void say_hello_cuda();

void say_hello_cpp(void){
    printf("Hello from C++!\n");
}

void calling_cuda(){
    say_hello_cuda();
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