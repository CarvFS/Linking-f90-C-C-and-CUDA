#ifndef CLASS1_HPP
#define CLASS1_HPP
// #include "struct.hpp"
#include <iostream>
using namespace std;

// struct str1{
//     int ivalue;
//     double dvalue;
// };
// typedef struct str1 str1;

namespace tutorial {
    
    static int vec[3] = {12,23,34};
    static char word[] = "pre-defined";

    struct str1{
        int ifield;
        double dfield;
    };
    typedef struct str1 str1;

    class Class1
    {
    public:
      Class1(int test1, double test2, bool TorF, int o_test = 1, double o_test2 = 0.5, bool o_TorF = true);
      ~Class1();
      
      // struct str1{
      //   int ivalue;
      //   double dvalue;
      // };
      // typedef struct str1 str1;

      void receive_str(str1 *arg);

      void test_struct();

    };

}

#endif // CLASS1_HPP