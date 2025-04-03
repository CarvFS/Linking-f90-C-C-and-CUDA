#include <iostream>
#include "tutorial.hpp"
using namespace std;
#include <iomanip>

namespace tutorial {

    Class1 :: Class1(){
        data = new double[6];
        for (int i = 0; i < 6; i++) {
            data[i] = static_cast<double>(i);
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
    }

    void Class1 :: print_data(double* data){
        cout << "In cpp:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << data[i] << endl;
        }
    }

    double* Class1 ::  get_data(int start_index, int* len){
        *len = 3;
        return data + (start_index - 1)*3;
    }


}