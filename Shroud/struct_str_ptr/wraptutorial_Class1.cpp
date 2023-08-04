// wraptutorial_Class1.cpp
// This file is generated by Shroud 0.12.1. Do not edit.
#include "wraptutorial_Class1.h"
#include <cstddef>
#include "tutorial.hpp"

// splicer begin namespace.tutorial.class.Class1.CXX_definitions
// splicer end namespace.tutorial.class.Class1.CXX_definitions

extern "C" {

// splicer begin namespace.tutorial.class.Class1.C_definitions
// splicer end namespace.tutorial.class.Class1.C_definitions

TUT_tutorial_Class1 * TUT_tutorial_Class1_new(
    TUT_tutorial_Class1 * SHC_rv)
{
    // splicer begin namespace.tutorial.class.Class1.method.new
    tutorial::Class1 *SHCXX_rv = new tutorial::Class1();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.new
}

void TUT_tutorial_Class1_set_strings(TUT_tutorial_Class1 * self,
    int char_len)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.set_strings
    SH_this->set_strings(char_len);
    // splicer end namespace.tutorial.class.Class1.method.set_strings
}

void TUT_tutorial_Class1_printvalues(TUT_tutorial_Class1 * self)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.printvalues
    SH_this->printvalues();
    // splicer end namespace.tutorial.class.Class1.method.printvalues
}

int * TUT_tutorial_Class1_get_int_ptr(TUT_tutorial_Class1 * self,
    int * len)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.get_int_ptr
    int * SHC_rv = SH_this->get_int_ptr(len);
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.get_int_ptr
}

int * TUT_tutorial_Class1_get_int_ptr_bufferify(
    TUT_tutorial_Class1 * self, TUT_SHROUD_array *DSHC_rv, int * len)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.get_int_ptr_bufferify
    int * SHC_rv = SH_this->get_int_ptr(len);
    DSHC_rv->cxx.addr  = SHC_rv;
    DSHC_rv->cxx.idtor = 0;
    DSHC_rv->addr.base = SHC_rv;
    DSHC_rv->type = SH_TYPE_INT;
    DSHC_rv->elem_len = sizeof(int);
    DSHC_rv->rank = 1;
    DSHC_rv->shape[0] = *len;
    DSHC_rv->size = DSHC_rv->shape[0];
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.get_int_ptr_bufferify
}

void TUT_tutorial_Class1_get_strs(TUT_tutorial_Class1 * self,
    char * * strs, int * name_len, int char_len)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.get_strs
    SH_this->get_strs(strs, name_len, char_len);
    // splicer end namespace.tutorial.class.Class1.method.get_strs
}

void TUT_tutorial_Class1_get_strs_bufferify(TUT_tutorial_Class1 * self,
    char * * strs, int * name_len, int char_len)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.get_strs_bufferify
    SH_this->get_strs(strs, name_len, char_len);
    // splicer end namespace.tutorial.class.Class1.method.get_strs_bufferify
}

void TUT_tutorial_Class1_delete(TUT_tutorial_Class1 * self)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.delete
    delete SH_this;
    self->addr = nullptr;
    // splicer end namespace.tutorial.class.Class1.method.delete
}

}  // extern "C"