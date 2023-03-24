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

    char savefile[16];
    char closureID[8];

    void assign_char();
    void assign_values();

    void rism1d_addSpecies();

    double rism1d_solve(); // will need to be changed...
    double rism1d_dt_solve();

    void self_test();

    double getInvDebyeLen();
    double rism1d_getCompressibility();
    double rism1d_getCompressibility_dT();
    double rism1d_get3DRISMbackground();
    double rism1d_getDelHvLimit();
    double rism1d_getDelHvLimit_dT();
    double rism1d_getSusceptibility();
    double rism1d_getSusceptibility_dT();
    double rism1d_getExNumber();
    double rism1d_getStructFactor();
    double rism1d_getRunExNumber();
    double rism1d_getRunNumber();
    double rism1d_getPressureVirial();
    double rism1d_getPressureFE();
    double rism1d_getFreeEnergy();
    double rism1d_getPMV();
    double rism1d_getExChem();
    double rism1d_getExChemIon();
    double rism1d_getSolvene();
    double rism1d_bvv();

    void rism1d_destroy();

    double solve3DRISM_dT();

    void single3DRISMsolution_dT();
    void rism1d_readNBFix();
    void rism1d_readNBFixtsf();

};
// based on https://stackoverflow.com/questions/14815274/how-to-call-a-c-method-from-c
extern "C" double rism1d_getInvDebyeLen(RISM1D*);

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
