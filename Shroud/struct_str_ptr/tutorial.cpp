#include <iostream>
#include "tutorial.hpp"
// #include "NewClass.hpp"
#include <sstream>

namespace tutorial {
    static str1 s;

    Class1 :: Class1(){
        cout << "Object is being created!" << endl;   
        s.iptr_size = 4;
        s.str_size = 2;

        s.iptr = new int[s.iptr_size];
        
        for(int i = 0; i < s.iptr_size; i++){
            s.iptr[i] = i+123;
        }

    }

    void Class1 :: set_strings(){
        s.names = new string[s.str_size];
        s.names[0] = "Lucy";
        s.names[1] = "Mina";
    }

    void Class1 :: printvalues(){
        cout << "From printvalues:" << endl;
        for(int i = 0; i < s.iptr_size; i++){
            cout << "   iptr[" << i << "] = " << s.iptr[i] << endl;
        }

        for(int i = 0; i < s.str_size; i++){
            cout << "   names[" << i << "] = " << s.names[i] << endl;
        }
    }

    int* Class1 :: get_int_ptr(int *len){
        *len = s.iptr_size;
        return s.iptr;
    }

    //////////////// Modify here ////////////////
    void Class1 :: get_strs(char** strs, int name_len){
        cout << "====== In: get_strs =======" << endl;
        name_len = s.str_size;
        char *buf = new char[s.str_size*4];
        for(int i = 0; i < name_len; i++){
            if(i == 0){
                strcpy(buf,const_cast<char*>(s.names[i].c_str()));
                // strcpy(buf,const_cast<char*>("test"));
            }
            else{
                strcat(buf,const_cast<char*>(s.names[i].c_str()));
                // strcat(buf,const_cast<char*>("tset"));
            }
        }
        *strs = buf;
        cout << "====== Out: get_strs =======" << endl;
    }
    ////////////////////////////////////////////

    Class1 :: ~Class1(){
        cout << "Object is being deleted!" << endl;
    }


}