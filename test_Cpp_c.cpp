// Working along with .90 code
// #include <stdio.h> // Not normally used in c++, but it is working

// extern "C" void say_hello_cpp(); // Let FORTRAN know about this function
// extern "C" void calling_cuda(); // Let FORTRAN know about this function
// extern void say_hello_cuda(); // Let FORTRAN and C++ know about this function

// void say_hello_cpp(){
//     printf("Hello from C++!\n");
// }

// void calling_cuda(){
//     say_hello_cuda();
// }


// Not working with .90 code

#include <iostream>
using namespace std;
extern "C" void say_hello_cpp();
extern "C" void calling_cuda(); // Let FORTRAN know about this function
extern void say_hello_cuda(); // Let FORTRAN and C++ know about this functi
void say_hello_cpp(){
    cout << "Hello from C++!" << endl;
    // cout << "The answer is: " << the_answer << endl;
}

void calling_cuda(){
    say_hello_cuda();
}
