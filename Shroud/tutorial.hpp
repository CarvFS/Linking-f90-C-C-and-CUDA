#ifndef CLASS1_HPP
#define CLASS1_HPP
#include "NewClass.hpp"
#include <iostream>
using namespace std;

namespace tutorial {
    
    static int vec[3] = {12,23,34};
    static char word[] = "pre-defined";

    class Class1
    {
    public:
      Class1(int test1, double test2, bool TorF, int o_test = 1, double o_test2 = 0.5, bool o_TorF = true);
      ~Class1();

      NewClass obj1;

      // attributes not passed to .yaml file
      int *test; // pointer to a 1D array
      int test_len; // size of 1D array

      int *TwoDarray; // pointer to a 2D array
      int TwoDA_len1, TwoDA_len2; // sizes of 2D array

      string *closurelist; // pointer to a list
      int cl_size;
      ////////////////////////////////////////

      void Method1(int* vec2d, int o_test = 1, int* value = vec, char* word2 = word, bool o_bool = true); // routine to print class atributes and see it they are correctly set.

      void acceptCharArrayIn(char **names, int N); // define routine which will receive string array
                                                   // from Fortran and copy it into `string closurelist`

      int *get_test_ptr(int *N); // Get 1D array
      int *get_TwoDarray_ptr(int *N, int *M); // Get 2D array
      
      void set_test(int N); // Set 1D array
      void set_TwoDarray(int N, int M); // Set 2D array

      bool check(int N);

      double get_dk();

    };

}

#endif // CLASS1_HPP