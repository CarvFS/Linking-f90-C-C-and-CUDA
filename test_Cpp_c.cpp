// Working along with .90 code
#include <stdio.h> // Not normally used in c++
extern "C" void say_hello_cpp(int the_answer); // it seems that this must be included to work using .cpp files

void say_hello_cpp(int the_answer){
    printf("Hello from C++!\n");
    printf("The answer is: %i\n", the_answer);
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