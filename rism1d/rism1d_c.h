/* This header can be read by both C and C++ compilers */
#ifndef RISM1D_C_H
#define RISM1D_C_H

#include <iostream>
#include <cstring>
using namespace std;

class RISM1D{
// uncomment here will cause strange behavior
  private:
    void new_();
    
    void sanity_check();

    double solve3DRISM();

    void single3DRISMsolution();
    
//    int charlen = 8;
//    int maxep0 = 4;

  public:
    RISM1D();
    int extra_precision;
    int Mdiis_vec;
    int mdiis_method;

    char savefile[256];
    char closureID[256];

    void assign_char();
    void assign_values();

    ////////////////////////////////////////////////////////
    void addSpecies(void* mdl, int density);

    double rism1d_solve();
    double rism1d_dt_solve();

    void self_test();

    double getInvDebyeLen();
    double getCompressibility();
    double getCompressibility_dT();
    double get3DRISMbackground();
    double getDelHvLimit();
    double getDelHvLimit_dT();
    double getSusceptibility();
    double getSusceptibility_dT();
    double getExNumber();
    double getStructFactor();
    double getRunExNumber();
    double getRunNumber();
    double getPressureVirial();
    double getPressureFE();
    double getFreeEnergy();
    double getPMV();
    double getExChem(char *o_form);
    double getExChemIon();
    double getSolvene();
    double bvv();

    void rism1d_destroy();

    double solve3DRISM_dT();

    void single3DRISMsolution_dT();
    void rism1d_readNBFix();
    void rism1d_readNBFixtsf();

};
// based on https://stackoverflow.com/questions/14815274/how-to-call-a-c-method-from-c
extern "C" {
void rism1d_addSpecies(RISM1D*, void* mdl, int density);

double rism1d_getInvDebyeLen(RISM1D*);
double rism1d_getCompressibility(RISM1D*);
double rism1d_getCompressibility_dT(RISM1D*);
double rism1d_get3DRISMbackground(RISM1D*);
double rism1d_getDelHvLimit(RISM1D*);
double rism1d_getDelHvLimit_dT(RISM1D*);
double rism1d_getSusceptibility(RISM1D*);
double rism1d_getSusceptibility_dT(RISM1D*);
double rism1d_getExNumber(RISM1D*);
double rism1d_getStructFactor(RISM1D*);
double rism1d_getRunExNumber(RISM1D*);
double rism1d_getRunNumber(RISM1D*);
double rism1d_getPressureVirial(RISM1D*);
double rism1d_getPressureFE(RISM1D*);
double rism1d_getFreeEnergy(RISM1D*);
double rism1d_getPMV(RISM1D*);
double rism1d_getExChem(RISM1D*, char *o_form);
double rism1d_getExChemIon(RISM1D*);
double rism1d_getSolvene(RISM1D*);
double rism1d_bvv(RISM1D*);
}


extern "C" RISM1D *cplusplus_callback_function(RISM1D*);


//extern "C" void assign_char;

/*
#ifdef __cplusplus
  class RISM1D{
    public:
        RISM1D();
        int extra_precision;
    };
#else
  typedef
    struct RISM1D {
      int extra_precision;
    }
      RISM1D;
#endif
#ifdef __cplusplus

extern "C" {
#endif
#if defined(__STDC__) || defined(__cplusplus)
  extern RISM1D *cplusplus_callback_function(RISM1D*);
#else
  extern RISM1D *cplusplus_callback_function();
#endif
#ifdef __cplusplus
}
#endif
*/
#endif /*RISM1D_C_H*/
