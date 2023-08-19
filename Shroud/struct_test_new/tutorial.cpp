#include <iostream>
#include "tutorial.hpp"
// #include "NewClass.hpp"
#include <sstream>

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

void Class1 :: receive_struct(str1 *arg){
    cout << "========= Receiving struct data..." << endl;
    s = *arg;
}

void Class1 :: test_struct(){
    cout << "getting struct values:" << endl;
    cout << s.ifield << " and " << s.dfield << endl;
    cout << "Boolean is: " << s.ToF << endl;
}

Class1::~Class1(){
    cout << "Object is being deleted!" << endl;
}
