#include "rism1d_c.h"
#include <iostream>
#include <cstring>
using namespace std;

RISM1D :: RISM1D() {}

double RISM1D :: getInvDebyeLen(){
  cout << "getInvDebyeLen" << endl;
  return 123.456;
}

double rism1d_getInvDebyeLen(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getInvDebyeLen();
}

void RISM1D :: assign_char(){
    strcpy(savefile, "rism.sav");
    strcpy(closureID, "");
}

void RISM1D :: assign_values(){
    extra_precision = 2;
    Mdiis_vec = 1;
    mdiis_method = 2;
}

RISM1D *cplusplus_callback_function(RISM1D *r1d){
    r1d -> assign_char();
    r1d -> assign_values();
    
    return r1d;
}
