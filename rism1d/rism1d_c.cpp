#include "rism1d_c.h"
#include <iostream>
#include <cstring>
using namespace std;

rism1d :: rism1d() {}

void rism1d :: assign_char(){
    strcpy(savefile, "rism.sav");
    strcpy(closureID, "");
}

void rism1d :: assign_values(){
    extra_precision = 2;
    Mdiis_vec = 1;
    mdiis_method = 2;
}

rism1d *cplusplus_callback_function(rism1d *r1d){
    r1d -> assign_char();
    r1d -> assign_values();
    
    return r1d;
}