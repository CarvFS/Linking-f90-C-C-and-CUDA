// wraptutorial_Class1.h
// This file is generated by Shroud 0.12.1. Do not edit.
/**
 * \file wraptutorial_Class1.h
 * \brief Shroud generated wrapper for Class1 class
 */
// For C users and C++ implementation

#ifndef WRAPTUTORIAL_CLASS1_H
#define WRAPTUTORIAL_CLASS1_H

#include "typesTutorial.h"

// splicer begin namespace.tutorial.class.Class1.CXX_declarations
// splicer end namespace.tutorial.class.Class1.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin namespace.tutorial.class.Class1.C_declarations
// splicer end namespace.tutorial.class.Class1.C_declarations

TUT_tutorial_Class1 * TUT_tutorial_Class1_new(
    TUT_tutorial_Class1 * SHC_rv);

void TUT_tutorial_Class1_set_strings(TUT_tutorial_Class1 * self,
    int char_len);

void TUT_tutorial_Class1_printvalues(TUT_tutorial_Class1 * self);

int * TUT_tutorial_Class1_get_int_ptr(TUT_tutorial_Class1 * self,
    int * len);

int * TUT_tutorial_Class1_get_int_ptr_bufferify(
    TUT_tutorial_Class1 * self, TUT_SHROUD_array *DSHC_rv, int * len);

void TUT_tutorial_Class1_get_strs(TUT_tutorial_Class1 * self,
    char * * strs, int * name_len, int char_len);

void TUT_tutorial_Class1_get_strs_bufferify(TUT_tutorial_Class1 * self,
    char * * strs, int * name_len, int char_len);

void TUT_tutorial_Class1_delete(TUT_tutorial_Class1 * self);

#ifdef __cplusplus
}
#endif

#endif  // WRAPTUTORIAL_CLASS1_H
