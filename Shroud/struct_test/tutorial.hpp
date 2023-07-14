#ifndef CLASS1_HPP
#define CLASS1_HPP
#include "struct.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include<string.h>
using namespace std;

namespace tutorial {
    
    static int vec[3] = {12,23,34};
    static char word[] = "pre-defined";

    class Class1
    {
    public:
      Class1(int test1, double test2, bool TorF, int o_test = 1, double o_test2 = 0.5, bool o_TorF = true);
      ~Class1();

      
      const char **names2;

      void receive_str(str1 *arg);
      void set_names(char** names, int name_len);
      void set_names2(char** names, int name_len);
      void test_names2();

      // Maybe here (https://github.com/LLNL/shroud/blob/develop/regression/input/strings.yaml) one 
      // can find a way to retrieve string *names on fortran side
      // Take a look on: acceptStringPointer
      void get_name(string *name_list, int idx);

      // void get_names2(string *names);

      void test_struct();

    };

}

#endif // CLASS1_HPP