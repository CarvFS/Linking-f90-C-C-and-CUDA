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


double RISM1D :: getCompressibility(){
  cout << "getCompressibility" << endl;
  return 654.321;
}
double rism1d_getCompressibility(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getCompressibility();
}


double RISM1D :: getCompressibility_dT(){
  cout << "getCompressibility_dT" << endl;
  return 111.111;
}
double rism1d_getCompressibility_dT(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getCompressibility_dT();
}


double RISM1D :: get3DRISMbackground(){
  cout << "get3DRISMbackground" << endl;
  return 222.222;
}
double rism1d_get3DRISMbackground(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->get3DRISMbackground();
}


double RISM1D :: getDelHvLimit(){
  cout << "getDelHvLimit" << endl;
  return 333.333;
}
double rism1d_getDelHvLimit(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getDelHvLimit();
}


double RISM1D :: getDelHvLimit_dT(){
  cout << "getDelHvLimit_dT" << endl;
  return 444.444;
}
double rism1d_getDelHvLimit_dT(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getDelHvLimit_dT();
}


double RISM1D :: getSusceptibility(){
  cout << "getSusceptibility" << endl;
  return 555.555;
}
double rism1d_getSusceptibility(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getSusceptibility();
}


double RISM1D :: getSusceptibility_dT(){
  cout << "getSusceptibility_dT" << endl;
  return 666.666;
}
double rism1d_getSusceptibility_dT(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getSusceptibility_dT();
}


double RISM1D :: getExNumber(){
  cout << "getExNumber" << endl;
  return 777.777;
}
double rism1d_getExNumber(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getExNumber();
}


double RISM1D :: getStructFactor(){
  cout << "getStructFactor" << endl;
  return 888.888;
}
double rism1d_getStructFactor(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getStructFactor();
}


double RISM1D :: getRunExNumber(){
  cout << "getRunExNumber" << endl;
  return 999.999;
}
double rism1d_getRunExNumber(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getRunExNumber();
}


double RISM1D :: getRunNumber(){
  cout << "getRunNumber" << endl;
  return 121.212;
}
double rism1d_getRunNumber(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getRunNumber();
}


double RISM1D :: getPressureVirial(){
  cout << "getPressureVirial" << endl;
  return 212.121;
}
double rism1d_getPressureVirial(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getPressureVirial();
}


double RISM1D :: getPressureFE(){
  cout << "getPressureFE()" << endl;
  return 111.222;
}
double rism1d_getPressureFE(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getPressureFE();
}


double RISM1D :: getFreeEnergy(){
  cout << "getFreeEnergy" << endl;
  return 111.333;
}
double rism1d_getFreeEnergy(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getFreeEnergy();
}


double RISM1D :: getPMV(){
  cout << "getPMV" << endl;
  return 111.111;
}
double rism1d_getPMV(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getPMV();
}


//double RISM1D :: getExChem(int o_form, char *c_form){
double RISM1D :: getExChem(char *o_form){
  cout << "getExChem" << endl;
  cout << "o_form = " << o_form;
  return 101.010;
}
//double rism1d_getExChem(RISM1D* rism1d, int o_form, char *c_form){
double rism1d_getExChem(RISM1D* rism1d, char *o_form){
  return static_cast<RISM1D*>(rism1d)->getExChem(o_form);
}


double RISM1D :: getExChemIon(){
  cout << "getExChemIon" << endl;
  return 122.123;
}
double rism1d_getExChemIon(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getExChemIon();
}


double RISM1D :: getSolvene(){
  cout << "getSolvene" << endl;
  return 123.321;
}
double rism1d_getSolvene(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getSolvene();
}


double RISM1D :: bvv(){
  cout << "bvv" << endl;
  return 333.222;
}
double rism1d_bvv(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->bvv();
}










/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
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
