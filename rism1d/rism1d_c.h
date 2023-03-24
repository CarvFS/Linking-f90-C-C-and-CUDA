/* This header can be read by both C and C++ compilers */
#ifndef RISM1D_C_H
#define RISM1D_C_H

#include <iostream>
#include <cstring>
using namespace std;

class rism1d{
// uncomment here will cause strange behavior
  private:
    void new_();
    
    void sanity_check();

    double solve3DRISM();

    void single3DRISMsolution();
    
//    int charlen = 8;
//    int maxep0 = 4;

  public:
    rism1d();
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

    double rism1d_getInvDebyeLen();
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

extern "C" rism1d *cplusplus_callback_function(rism1d*);
//extern "C" void assign_char;

/*
#ifdef __cplusplus
  class rism1d{
    public:
        rism1d();
        int extra_precision;
    };
#else
  typedef
    struct rism1d {
      int extra_precision;
    }
      rism1d;
#endif
#ifdef __cplusplus

extern "C" {
#endif
#if defined(__STDC__) || defined(__cplusplus)
  extern rism1d *cplusplus_callback_function(rism1d*);
#else
  extern rism1d *cplusplus_callback_function();
#endif
#ifdef __cplusplus
}
#endif
*/
#endif /*RISM1D_C_H*/