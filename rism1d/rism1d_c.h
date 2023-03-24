/* This header can be read by both C and C++ compilers */
#ifndef RISM1D_C_H
#define RISM1D_C_H

#include <iostream>
#include <cstring>
using namespace std;

class rism1d{
  public:
    rism1d();
    int extra_precision;
    int Mdiis_vec;
    char savefile[3];

    void assign_char();
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