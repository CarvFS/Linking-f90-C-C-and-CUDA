#ifndef CLASS1_HPP
#define CLASS1_HPP
#include <iostream>
#include "vartype.hpp"
using namespace std;

namespace tutorial {

    typedef struct str1 str1;

    class Class1
    {
    public:
      Class1();
      
      ~Class1();

      vartype *data;

      void print_data(vartype* data);

      vartype* get_data(int start_index, int* len);

    };

}

#endif // CLASS1_HPP