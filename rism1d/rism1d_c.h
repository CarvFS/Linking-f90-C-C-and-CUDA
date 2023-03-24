/* This header can be read by both C and C++ compilers */
#ifndef RISM1D_C_H
#define RISM1D_C_H

class rism1d{
  public:
    rism1d();
    int extra_precision;
};

extern "C" rism1d *cplusplus_callback_function(rism1d*);

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