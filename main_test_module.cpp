#include <iostream>
using namespace std;

extern "C"{
    extern double __test_module_func_MOD_add(double* a, double* b);
    extern void __test_module_MOD_add_ab();
}   


int main(){
    double a = 1.0;
    double b = 2.0;

    cout << "Calling fortran function from C++!" << endl;
    cout << __test_module_func_MOD_add(&a, &b) << endl;

    cout << "Calling fortran subroutine from C++" << endl;
    __test_module_MOD_add_ab();
    
    return 0;
}