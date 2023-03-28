#include "rism1d_c.h"
#include <iostream>
#include <cstring>
using namespace std;

RISM1D :: RISM1D() {}

void RISM1D :: addSpecies(void* mdl, int density){
  cout << "Seems to be working... " << "Density is: " << density << endl;
  cout << mdl << endl; // must print values defined at mdl in fortran... need to figure out how
}
void rism1d_addSpecies(RISM1D* rism1d, void* mdl, int density){
  static_cast<RISM1D*>(rism1d)->addSpecies(mdl, density);
}

double RISM1D :: getInvDebyeLen(){
  cout << "getInvDebyeLen" << endl;
  return 1.0;
}
double rism1d_getInvDebyeLen(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getInvDebyeLen();
}


double RISM1D :: getCompressibility(){
  cout << "getCompressibility" << endl;
  return 2.0;
}
double rism1d_getCompressibility(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getCompressibility();
}


double RISM1D :: getCompressibility_dT(){
  cout << "getCompressibility_dT" << endl;
  return 3.0;
}
double rism1d_getCompressibility_dT(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getCompressibility_dT();
}


double RISM1D :: get3DRISMbackground(){
  cout << "get3DRISMbackground" << endl;
  return 4.0;
}
double rism1d_get3DRISMbackground(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->get3DRISMbackground();
}


double RISM1D :: getDelHvLimit(){
  cout << "getDelHvLimit" << endl;
  return 5.0;
}
double rism1d_getDelHvLimit(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getDelHvLimit();
}


double RISM1D :: getDelHvLimit_dT(){
  cout << "getDelHvLimit_dT" << endl;
  return 6.0;
}
double rism1d_getDelHvLimit_dT(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getDelHvLimit_dT();
}


double RISM1D :: getSusceptibility(){
  cout << "getSusceptibility" << endl;
  return 7.0;
}
double rism1d_getSusceptibility(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getSusceptibility();
}


double RISM1D :: getSusceptibility_dT(){
  cout << "getSusceptibility_dT" << endl;
  return 8.0;
}
double rism1d_getSusceptibility_dT(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getSusceptibility_dT();
}


double RISM1D :: getExNumber(){
  cout << "getExNumber" << endl;
  return 9.0;
}
double rism1d_getExNumber(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getExNumber();
}


double RISM1D :: getStructFactor(){
  cout << "getStructFactor" << endl;
  return 10.0;
}
double rism1d_getStructFactor(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getStructFactor();
}


double RISM1D :: getRunExNumber(){
  cout << "getRunExNumber" << endl;
  return 11.0;
}
double rism1d_getRunExNumber(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getRunExNumber();
}


double RISM1D :: getRunNumber(){
  cout << "getRunNumber" << endl;
  return 12.0;
}
double rism1d_getRunNumber(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getRunNumber();
}


double RISM1D :: getPressureVirial(){
  cout << "getPressureVirial" << endl;
  return 13.0;
}
double rism1d_getPressureVirial(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getPressureVirial();
}


double RISM1D :: getPressureFE(){
  cout << "getPressureFE()" << endl;
  return 14.0;
}
double rism1d_getPressureFE(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getPressureFE();
}


double RISM1D :: getFreeEnergy(){
  cout << "getFreeEnergy" << endl;
  return 15.0;
}
double rism1d_getFreeEnergy(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getFreeEnergy();
}


double RISM1D :: getPMV(){
  cout << "getPMV" << endl;
  return 16.0;
}
double rism1d_getPMV(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getPMV();
}

//double RISM1D :: getExChem(int o_form, char *c_form){
double RISM1D :: getExChem(char *o_form){
  cout << "getExChem" << endl;
  cout << "o_form = " << o_form << "... end";
  return 17.0;
}
//double rism1d_getExChem(RISM1D* rism1d, int o_form, char *c_form){
double rism1d_getExChem(RISM1D* rism1d, char *o_form){
  return static_cast<RISM1D*>(rism1d)->getExChem(o_form);
}


double RISM1D :: getExChemIon(){
  cout << "getExChemIon" << endl;
  return 18.0;
}
double rism1d_getExChemIon(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getExChemIon();
}


double RISM1D :: getSolvene(){
  cout << "getSolvene" << endl;
  return 19.0;
}
double rism1d_getSolvene(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->getSolvene();
}


double RISM1D :: bvv(){
  cout << "bvv" << endl;
  return 20.0;
}
double rism1d_bvv(RISM1D* rism1d){
  return static_cast<RISM1D*>(rism1d)->bvv();
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
void RISM1D :: assign_char(){
    strcpy(savefile, "rism.sav");
    strcpy(closureID, " ");
    // Filling vector with spaces...
    for(int i = strlen(savefile); i < 256; i++){
      savefile[i] = ' ';
    }

    for(int i = strlen(closureID); i < 256; i++){
      closureID[i] = ' ';
    }
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
