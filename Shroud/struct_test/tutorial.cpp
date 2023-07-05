#include <iostream>
#include "tutorial.hpp"
// #include "NewClass.hpp"
#include <sstream>

static int global_fixed_array[] = {12,23,34};

static int global_int2d[] = {12,45,23,56,34,67};

namespace tutorial {
    static str1 s;

    Class1 :: Class1(int test1, double test2, 
    bool TorF, int o_test, double o_test2, bool o_TorF){
        cout << "Object is being created!" << endl;
        // print pre-defined/optional arguments
        cout << "o_test = " << o_test << endl;
        cout << "o_test2 = " << o_test2 << endl;
        cout << "o_TorF = " << o_TorF << endl;

        s.ifield = 123456789;
        s.dfield = 12.3456;
        cout << s.ifield << " and " << s.dfield << endl;
    }

    void Class1 :: receive_str(str1 *arg){
        cout << "========= Receiving struct data..." << endl;
        s = *arg;

        // Allocating memory for pointers...
        // Copy data from pointers on fortran side to C++ side
        // This way, one can deallocate the pointers on Fortran 
        // and still access the values getting them from C++ side
        s.names = new string[2];
        s.iptr = new int[2];

        for(int i = 0; i < 3; i++){
            s.iptr[i] = arg->iptr[i];
        }

        // If the size of an array will be defined based on some value
        // found in another array, one must copy the values first.
        int value = *max_element(s.iptr, s.iptr + 2);
        s.arr_2d = new double[value*value];

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                s.arr_2d[i*2+j] = arg -> arr_2d[i*2+j];
            }
        }

    }

    void Class1 :: set_names(char** names, int name_len){
        cout << "setting names..." << endl;
        name_len = 2;
        // solv.atomName = new string[numAtomType];

        for(int i=0; i<name_len; i++){
            cout << names[i] << "..." << endl;
            s.names[i] = names[i];
        }
    }    

    void Class1 :: get_name(string *name_list){
        *name_list = s.names[1];
    }

    void Class1 :: test_struct(){
        cout << "getting struct values:" << endl;
        cout << s.ifield << " and " << s.dfield << endl;
        cout << s.iptr[0] << ", " << s.iptr[1] << endl;
        cout << "String is: " << s.names[0] << endl;
        cout << "String is: " << s.names[1] << endl;
        cout << "Boolean is: " << s.ToF << endl;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << "arr_2d[" << i << ", " << j << "] = " << s.arr_2d[i*2+j] << endl;
            }
        }
    }
    
    Class1::~Class1(){
        cout << "Object is being deleted!" << endl;
    }


}