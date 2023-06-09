#include "rism1d_c.h"
#include <iostream>
#include <cstring>
using namespace std;

RISM1D :: RISM1D() {}
///////////// Provate

void RISM1D :: sanity_check(){
  cout << "Hello from private sanity_check!" << endl;
}

void RISM1D :: single3DRISMsolution(double residual, double tolerance, bool start, bool converged, mdiis mdiis_o){
  cout << "so far, so good at single3DRISMsolution" << endl;
  cout << "print mdiis test: " << mdiis_o.test << endl;
  cout << "print mdiis test2: " << mdiis_o.test2 << endl;
  cout << "Probably both structure and type mdiis will need to be defined equaly on .F90 and .h" << endl;
}

double RISM1D :: solve3DRISM(int ksave, int progress, int maxstep, double tolerance){
  cout << "///////////" << endl;
  cout << "solve3DRISM here..." << endl;
  cout << "///////////" << endl;

  bool converged = false;
  bool start = true;
  double residual = 1e-2;
  cout << "///////////" << endl;
  cout << "Calling single3DRISMsolution here..." << endl;
  mdiis mdiis_o;
  single3DRISMsolution(residual, tolerance, start, converged, mdiis_o);
  cout << "///////////" << endl;
  return 24.0;
}

///////////// Public

void RISM1D :: destroy(){
  cout << "so far, so good" << endl;
  cout << "calling sanity_check just as a test here: " << endl;
  sanity_check();
}
void rism1d_destroy(RISM1D* rism1d){
  static_cast<RISM1D*>(rism1d)->destroy();
}

void RISM1D :: readNBFixtsf(char *nbfix){
  cout << nbfix << "(end string)" << endl;
}
void rism1d_readNBFixtsf(RISM1D* rism1d, char *nbfix){
  static_cast<RISM1D*>(rism1d)->readNBFixtsf(nbfix);
}

void RISM1D :: readNBFix(char *nbfix){
  cout << nbfix << "(end string)" << endl;
}
void rism1d_readNBFix(RISM1D* rism1d, char *nbfix){
  static_cast<RISM1D*>(rism1d)->readNBFix(nbfix);
}

void RISM1D :: self_test(char *filename, bool o_all){
  cout << "o_all = " << o_all << endl;
  cout << "Name is: " << filename << "(end filename)" << endl;
  cout << "Just a test... print class member 'extra_precision': " << extra_precision << endl;
  cout << "Need to call 'cplusplus_callback_function' to assign values!" << endl;
}
void rism1d_selftest(RISM1D* rism1d,char *filename, bool o_all){
  static_cast<RISM1D*>(rism1d)->self_test(filename, o_all);
}

void RISM1D :: addSpecies(MDL* mdl, int density){
  cout << "Density is: " << density << endl;
  cout << "Accessing members of mdl... (no pointers or allocatables, but enough to test)" << endl;
  cout << "Print mdl test: " << mdl->test << endl;
  cout << "Print mdl test2: " << mdl->test2 << endl;
}
void rism1d_addSpecies(RISM1D* rism1d, MDL* mdl, int density){
  static_cast<RISM1D*>(rism1d)->addSpecies(mdl, density);
}

void RISM1D :: single3DRISMsolution_dT(double xvv[][3][3], double residual, double tolerance, bool start, bool converged, mdiis* mdiis_o){
  cout << "residual = "<< residual << endl;
  cout << "tolerance = " << tolerance << endl;
  cout << "start: " << start << endl;
  cout << "converged: " << converged << endl;
  cout << "Print mdiis test: " << mdiis_o->test << endl;
  cout << "Print mdiis test2: " << mdiis_o->test2 << endl;
//  cout <<  xvv[1][1][1] << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        cout << "vec(" << i << j << k << ") = " << xvv[i][j][k] << endl;
      }
    }
  }
  cout << "Working, but need to specify the 3D-array's 2nd and 3rd dimensions" << endl;

}
void rism1d_single3DRISMsolution_dT(RISM1D* rism1d, double xvv[][3][3], double residual, double tolerance, bool start, bool converged, mdiis* mdiis_o){
  static_cast<RISM1D*>(rism1d)->single3DRISMsolution_dT(xvv, residual, tolerance, start, converged, mdiis_o);
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
  cout << "Accessing char argument..." << endl;
  cout << "o_form = " << o_form << "... end" << endl;
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

double RISM1D :: solve3DRISM_dT(int ksave, int progress, int maxstep, double tolerance){
  cout << "ksave = " << ksave << endl;
  cout << "progress = " << progress << endl;
  cout << "maxstep = " << maxstep << endl;
  cout << "tolerance = " << tolerance << endl;
  return 21.0;
}
double rism1d_solve3DRISM_dT(RISM1D* rism1d, int ksave, int progress, int maxstep, double tolerance){
  return static_cast<RISM1D*>(rism1d)->solve3DRISM_dT(ksave, progress, maxstep, tolerance);
}

double RISM1D :: solve(int ksave, int progress, int maxstep, double tolerance){
  cout << "ksave = " << ksave << endl;
  cout << "progress = " << progress << endl;
  cout << "maxstep = " << maxstep << endl;
  cout << "tolerance = " << tolerance << endl;
  cout << solve3DRISM(ksave, progress, maxstep, tolerance) << endl;
  return 22.0;
}
double rism1d_solve(RISM1D* rism1d, int ksave, int progress, int maxstep, double tolerance){
  return static_cast<RISM1D*>(rism1d)->solve(ksave, progress, maxstep, tolerance);
}

double RISM1D :: dt_solve(int ksave, int progress, int maxstep, double tolerance){
  cout << "ksave = " << ksave << endl;
  cout << "progress = " << progress << endl;
  cout << "maxstep = " << maxstep << endl;
  cout << "tolerance = " << tolerance << endl;
  return 23.0;
}
double rism1d_dt_solve(RISM1D* rism1d, int ksave, int progress, int maxstep, double tolerance){
  return static_cast<RISM1D*>(rism1d)->dt_solve(ksave, progress, maxstep, tolerance);
}

/////////////////////////////////////////////////////////////////
///////////////////////// Assing values /////////////////////////
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
    extra_precision = 12345678;
    Mdiis_vec = 1;
    mdiis_method = 2;
}

RISM1D *cplusplus_callback_function(RISM1D *r1d){
    r1d -> assign_char();
    r1d -> assign_values();
    
    return r1d;
  }
