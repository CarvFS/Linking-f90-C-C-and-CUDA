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

        s.ifield = 123456;
        s.dfield = 12.34;
        cout << s.ifield << " and " << s.dfield << endl;
    }

    void Class1 :: receive_str(str1 *arg){
        cout << "So far, so good" << endl;
        // cout << arg->ifield << " and " << arg->dfield << endl;
        s = *arg;
        // cout << s.ifield << " and " << s.dfield << endl;
    }

    void Class1 :: test_struct(){
        cout << "getting struct values:" << endl;
        cout << s.ifield << " and " << s.dfield << endl;
    }
    
    Class1::~Class1(){
        cout << "Object is being deleted!" << endl;
    }


}