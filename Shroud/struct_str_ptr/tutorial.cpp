#include <iostream>
#include "tutorial.hpp"
// #include "NewClass.hpp"
#include <sstream>

namespace tutorial {
    static str1 s;

    Class1 :: Class1(){
        cout << "Object is being created!" << endl;   
        s.iptr_size = 4;
        s.str_size = 4;

        s.iptr = new int[s.iptr_size];
        
        for(int i = 0; i < s.iptr_size; i++){
            s.iptr[i] = i+123;
        }

    }

    void Class1 :: set_strings(int char_len){
        s.names = new string[s.str_size];
        s.names[0] = "Lucy";
        s.names[1] = "Fe";
        s.names[2] = "Mih";
        s.names[3] = "Mina";

        // Fill names with less than 4 characters with spaces
        for(int i = 0; i < s.str_size; i++){
            s.names[i].insert(s.names[i].end(), char_len - s.names[i].size(), ' ');
        }
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
    void Class1 :: get_strs(char** strs, int* name_len, int char_len){
        cout << "====== In: get_strs =======" << endl;
        *name_len = s.str_size;
        char *buf = new char[s.str_size*char_len];
        for(int i = 0; i < *name_len; i++){
            if(i == 0){
                strcpy(buf,const_cast<char*>(s.names[i].c_str()));
            }
            else{
                strcat(buf,const_cast<char*>(s.names[i].c_str()));
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