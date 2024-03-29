#ifndef CLASS1_HPP
#define CLASS1_HPP
#include <iostream>
#include<string.h>
using namespace std;

namespace tutorial {

    struct str1{
        int *iptr;
        string *names;
        int str_size;
        int iptr_size;
    };
    typedef struct str1 str1;

    class Class1
    {
    public:
      Class1();

      // void set_strings(int char_len);
      void set_strings(char **names);

      void printvalues();

      int* get_int_ptr(int *len);

      //////////////// Modify here ////////////////
      // const string* get_str_ptr();
      // void get_strs(char** strs, int* name_len, int char_len);
      void get_strs2(string **strs, int* name_len);
      ////////////////////////////////////////////

      ~Class1();

    };

}

#endif // CLASS1_HPP