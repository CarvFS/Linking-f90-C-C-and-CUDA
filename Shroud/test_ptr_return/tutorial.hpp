#ifndef CLASS1_HPP
#define CLASS1_HPP
#include <iostream>
#include<string.h>
using namespace std;

namespace tutorial {

    typedef struct str1 str1;

    class Class1
    {
    public:
      Class1();
      
      ~Class1();

      double *data;

      void test(float *val1, double *val2);

      void print_data(double* data);

      double* get_data(int start_index, int* len);

    };

}

#endif // CLASS1_HPP