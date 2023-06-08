// wraptutorial_Class1.cpp
// This file is generated by Shroud 0.12.1. Do not edit.
#include "wraptutorial_Class1.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include "tutorial.hpp"

// splicer begin namespace.tutorial.class.Class1.CXX_definitions
// splicer end namespace.tutorial.class.Class1.CXX_definitions

extern "C" {


// helper ShroudLenTrim
// Returns the length of character string src with length nsrc,
// ignoring any trailing blanks.
static int ShroudLenTrim(const char *src, int nsrc) {
    int i;

    for (i = nsrc - 1; i >= 0; i--) {
        if (src[i] != ' ') {
            break;
        }
    }

    return i + 1;
}


// helper ShroudStrArrayAlloc
// Copy src into new memory and null terminate.
// char **src +size(nsrc) +len(len)
// CHARACTER(len) src(nsrc)
static char **ShroudStrArrayAlloc(const char *src, int nsrc, int len)
{
   char **rv = static_cast<char **>(std::malloc(sizeof(char *) * nsrc));
   const char *src0 = src;
   for(int i=0; i < nsrc; ++i) {
      int ntrim = ShroudLenTrim(src0, len);
      char *tgt = static_cast<char *>(std::malloc(ntrim+1));
      std::memcpy(tgt, src0, ntrim);
      tgt[ntrim] = '\0';
      rv[i] = tgt;
      src0 += len;
   }
   return rv;
}

// helper ShroudStrArrayFree
// Release memory allocated by ShroudStrArrayAlloc
static void ShroudStrArrayFree(char **src, int nsrc)
{
   for(int i=0; i < nsrc; ++i) {
       std::free(src[i]);
   }
   std::free(src);
}
// splicer begin namespace.tutorial.class.Class1.C_definitions
// splicer end namespace.tutorial.class.Class1.C_definitions

TUT_tutorial_Class1 * TUT_tutorial_Class1_new_default(
    TUT_tutorial_Class1 * SHC_rv)
{
    // splicer begin namespace.tutorial.class.Class1.method.new_default
    tutorial::Class1 *SHCXX_rv = new tutorial::Class1();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.new_default
}

int * TUT_tutorial_Class1_get_test_ptr(TUT_tutorial_Class1 * self,
    int * len)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.get_test_ptr
    int * SHC_rv = SH_this->get_test_ptr(len);
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.get_test_ptr
}

int * TUT_tutorial_Class1_get__two_darray_ptr(
    TUT_tutorial_Class1 * self, int * len1, int * len2)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.get__two_darray_ptr
    int * SHC_rv = SH_this->get_TwoDarray_ptr(len1, len2);
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.get__two_darray_ptr
}

void TUT_tutorial_Class1_set_test(TUT_tutorial_Class1 * self, int N)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.set_test
    SH_this->set_test(N);
    // splicer end namespace.tutorial.class.Class1.method.set_test
}

void TUT_tutorial_Class1_set__two_darray(TUT_tutorial_Class1 * self,
    int N, int M)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.set__two_darray
    SH_this->set_TwoDarray(N, M);
    // splicer end namespace.tutorial.class.Class1.method.set__two_darray
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

void TUT_tutorial_Class1_method1(TUT_tutorial_Class1 * self)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.method1
    SH_this->Method1();
    // splicer end namespace.tutorial.class.Class1.method.method1
}

void TUT_tutorial_Class1_accept_char_array_in(
    TUT_tutorial_Class1 * self, char **names, int clsize)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.accept_char_array_in
    SH_this->acceptCharArrayIn(names, clsize);
    // splicer end namespace.tutorial.class.Class1.method.accept_char_array_in
}

void TUT_tutorial_Class1_accept_char_array_in_bufferify(
    TUT_tutorial_Class1 * self, char *names, long Snames, int Nnames,
    int clsize)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.accept_char_array_in_bufferify
    char **SHCXX_names = ShroudStrArrayAlloc(names, Snames, Nnames);
    SH_this->acceptCharArrayIn(SHCXX_names, clsize);
    ShroudStrArrayFree(SHCXX_names, Snames);
    // splicer end namespace.tutorial.class.Class1.method.accept_char_array_in_bufferify
}

bool TUT_tutorial_Class1_check(TUT_tutorial_Class1 * self, int N)
{
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    // splicer begin namespace.tutorial.class.Class1.method.check
    bool SHC_rv = SH_this->check(N);
    return SHC_rv;
    // splicer end namespace.tutorial.class.Class1.method.check
}

}  // extern "C"
