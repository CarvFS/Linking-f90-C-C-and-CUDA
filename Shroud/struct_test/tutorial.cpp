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
        names2 = new const char*[2];
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
        cout << "In set_names: setting names..." << endl;
        name_len = 2;
        // solv.atomName = new string[numAtomType];

        for(int i=0; i<name_len; i++){
            // cout << "names2 = " << s.names2[i] << "..." << endl;
            s.names[i] = names[i];
            // cout << "String len:" << s.names[i].size() << endl;
            s.names[i].insert(s.names[i].end(), 4 - s.names[i].size(), ' ');
        }
    }    

    void Class1 :: set_names2(char** names, int name_len){
        cout << "in set_names2: setting names..." << endl;
        name_len = 2;
        // solv.atomName = new string[numAtomType];

        for(int i=0; i<name_len; i++){
            // cout << names[i] << "..." << endl;
            names2[i] = const_cast<char*>(s.names[i].c_str());
            cout << names2[i] << "..." << endl;
        }
        names2[0] = const_cast<char*>("Ruth");
        names2[1] = const_cast<char*>("Beth");
    }    

    void Class1 :: test_names2(){
        cout << "In: test_names2" << endl;
        for(int i=0; i<2; i++){
            cout << names2[i] << "..." << endl;
        }
    }

    void Class1 :: get_name(string *name_list, int idx){
        *name_list = s.names[idx];
    }

    void Class1 :: get_name2(char** names, int name_len){
        name_len = 2;
        cout << "In get_name2: " << name_len << endl;
        cout << **names << endl;
        char buf[name_len*4];
        for(int i = 0; i < name_len; i++){
            if(i == 0){
                strcpy(buf,const_cast<char*>(s.names[i].c_str()));
                // strcpy(buf,const_cast<char*>("Le\0"));
            }
            else{
                strcat(buf,const_cast<char*>(s.names[i].c_str()));
                // strcat(buf,const_cast<char*>("Mark"));
            }
        }
        *names = buf;
    }

    // void Class1 :: get_names2(string *names){
    //     cout << "get_names2" << endl;
    //     cout << names[0] << " and " << names[1] << endl;
    //     // names = const_cast<char**>(names2);
    //     // cout << "In get_names2" << endl;
    //     // cout << names[0] << endl;
    // }

    void Class1 :: test_struct(){
        cout << "getting struct values:" << endl;
        cout << s.ifield << " and " << s.dfield << endl;
        cout << s.iptr[0] << ", " << s.iptr[1] << endl;
        cout << "String is: " << s.names[0] << endl;
        cout << "String is: " << s.names[1] << endl;
        cout << "Char** is: " << names2[0] << endl;
        cout << "Char** is: " << names2[1] << endl;
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