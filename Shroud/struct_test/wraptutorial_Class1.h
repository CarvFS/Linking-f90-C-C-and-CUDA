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
#ifndef __cplusplus
#include <stdbool.h>
#endif

// splicer begin namespace.tutorial.class.Class1.CXX_declarations
#include "wrapTutorial_tutorial.h"
// splicer end namespace.tutorial.class.Class1.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin namespace.tutorial.class.Class1.C_declarations
// splicer end namespace.tutorial.class.Class1.C_declarations

TUT_tutorial_Class1 * TUT_tutorial_Class1_new_0(int test1, double test2,
    bool TorF, TUT_tutorial_Class1 * SHC_rv);

TUT_tutorial_Class1 * TUT_tutorial_Class1_new_1(int test1, double test2,
    bool TorF, int o_test, TUT_tutorial_Class1 * SHC_rv);

TUT_tutorial_Class1 * TUT_tutorial_Class1_new_2(int test1, double test2,
    bool TorF, int o_test, double o_test2,
    TUT_tutorial_Class1 * SHC_rv);

TUT_tutorial_Class1 * TUT_tutorial_Class1_new_3(int test1, double test2,
    bool TorF, int o_test, double o_test2, bool o_TorF,
    TUT_tutorial_Class1 * SHC_rv);

void TUT_tutorial_Class1_delete(TUT_tutorial_Class1 * self);

void TUT_tutorial_Class1_receive_str(TUT_tutorial_Class1 * self,
    TUT_str1 * arg);

void TUT_tutorial_Class1_set_names(TUT_tutorial_Class1 * self,
    char **names, int name_len);

void TUT_tutorial_Class1_set_names_bufferify(TUT_tutorial_Class1 * self,
    char *names, long Snames, int Nnames, int name_len);

void TUT_tutorial_Class1_set_names2(TUT_tutorial_Class1 * self,
    char **names, int name_len);

void TUT_tutorial_Class1_set_names2_bufferify(
    TUT_tutorial_Class1 * self, char *names, long Snames, int Nnames,
    int name_len);

void TUT_tutorial_Class1_test_names2(TUT_tutorial_Class1 * self);

void TUT_tutorial_Class1_get_name(TUT_tutorial_Class1 * self,
    char * name_list, int idx);

void TUT_tutorial_Class1_get_name_bufferify(TUT_tutorial_Class1 * self,
    char * name_list, int Nname_list, int idx);

void TUT_tutorial_Class1_test_struct(TUT_tutorial_Class1 * self);

#ifdef __cplusplus
}
#endif

#endif  // WRAPTUTORIAL_CLASS1_H
