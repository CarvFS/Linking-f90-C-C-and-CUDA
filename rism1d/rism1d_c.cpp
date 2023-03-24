#include "rism1d_c.h"
#include <iostream>
using namespace std;

rism1d :: rism1d() {}

rism1d *cplusplus_callback_function(rism1d *r1d){
    r1d -> extra_precision = 456;
    return r1d;
}