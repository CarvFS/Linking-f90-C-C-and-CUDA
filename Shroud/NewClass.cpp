#include <iostream>
#include "NewClass.hpp"
#include <sstream>
#include <iostream>
using namespace std;

NewClass :: NewClass(){
    cout << "Object from NewClass is being created!" << endl;
    dk = 0.025;
}

NewClass :: ~NewClass(){
    cout << "Object from NewClass is being deleted!" << endl;
}

void NewClass :: print_message(){
    cout << "Hello from NewClass! dk = " << dk << endl;
}

// double NewClass :: get_dk(){
//     return dk;
// }