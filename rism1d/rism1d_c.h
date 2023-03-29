/* This header can be read by both C and C++ compilers */
#ifndef RISM1D_C_H
#define RISM1D_C_H

#include <iostream>
#include <cstring>
using namespace std;

extern "C" struct MDL{
  int test;
  double test2;
};

extern "C" struct mdiis{
  int test;
  double test2;
};

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
    void addSpecies(MDL* mdl, int density); // "done"

    double rism1d_solve();
    double rism1d_dt_solve();

    void self_test();

    double getInvDebyeLen(); // "done"
    double getCompressibility(); // "done"
    double getCompressibility_dT(); // "done"
    double get3DRISMbackground(); // "done"
    double getDelHvLimit(); // "done"
    double getDelHvLimit_dT(); // "done"
    double getSusceptibility(); // "done"
    double getSusceptibility_dT(); // "done"
    double getExNumber(); // "done"
    double getStructFactor(); // "done"
    double getRunExNumber(); // "done"
    double getRunNumber(); // "done"
    double getPressureVirial(); // "done"
    double getPressureFE(); // "done"
    double getFreeEnergy(); // "done"
    double getPMV(); // "done"
    double getExChem(char *o_form); // "done"
    double getExChemIon(); // "done"
    double getSolvene(); // "done"
    double bvv(); // "done"

    void rism1d_destroy();

    double solve3DRISM_dT(int ksave, int progress, int maxstep, double tolerance); // "done"

    void single3DRISMsolution_dT(double *xvv, double residual, double tolerance, bool start, bool converged, mdiis* mdiis_o);
    void rism1d_readNBFix();
    void rism1d_readNBFixtsf();

};
// based on https://stackoverflow.com/questions/14815274/how-to-call-a-c-method-from-c
extern "C" {
void rism1d_addSpecies(RISM1D*, MDL* mdl, int density);
void rism1d_single3DRISMsolution_dT(RISM1D*, double *xvv, double residual, double tolerance, bool start, bool converged, mdiis* mdiis_o);

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

double rism1d_solve3DRISM_dT(RISM1D*, int ksave, int progress, int maxstep, double tolerance);
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
