#include "rism1d_c.h"
#include <iostream>
#include <cstring>
using namespace std;

rism1d :: rism1d() {}

void rism1d :: assign_char(){
    strcpy(savefile, "Hi");
}

rism1d *cplusplus_callback_function(rism1d *r1d){
    r1d -> extra_precision = 2;
    r1d -> Mdiis_vec = 1;
    r1d -> assign_char();
    return r1d;
}