#include <iostream>
#include "tutorial.hpp"
using namespace std;
#include <iomanip>

namespace tutorial {

    Class1 :: Class1(){
        data = new vartype[6];
        for (int i = 0; i < 6; i++) {
            data[i] = static_cast<vartype>(i);
        }
    }

    Class1 :: ~Class1(){
        
    }

    void Class1 :: test(float *val1, double *val2){
        // int start_index = 2;

        // double* local_data = get_data(start_index);
        // for (int i = 0; i < 6-start_index; i++) {
        //     cout << local_data[i] << endl;
        // }
#ifdef PRECISION_DOUBLE
        cout << "using double" << endl;
#else
        cout << "using single" << endl;
#endif
    }

    void Class1 :: print_data(vartype* data){
        cout << "In cpp:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << data[i] << endl;
        }
    }

    vartype* Class1 ::  get_data(int start_index, int* len){
        *len = 3;
        return data + (start_index - 1)*3;
    }


}