#ifndef struc_HPP
#define struc_HPP
// #include "secondClass.hpp"
#include <iostream>
using namespace std;

// namespace tutorial{
struct str1{
    int ifield;
    double dfield;
    int *iptr;
    string *names;
    bool ToF;
    double *arr_2d;
};
typedef struct str1 str1;
// }

#endif // struc_HPP