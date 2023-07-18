// wrapClass1.cpp
// This file is generated by Shroud 0.12.1. Do not edit.
#include "wrapClass1.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include "tutorial.hpp"

// splicer begin class.Class1.CXX_definitions
// splicer end class.Class1.CXX_definitions

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

// helper ShroudStrCopy
// Copy src into dest, blank fill to ndest characters
// Truncate if dest is too short.
// dest will not be NULL terminated.
static void ShroudStrCopy(char *dest, int ndest, const char *src, int nsrc)
{
   if (src == NULL) {
     std::memset(dest,' ',ndest); // convert NULL pointer to blank filled string
   } else {
     if (nsrc < 0) nsrc = std::strlen(src);
     int nm = nsrc < ndest ? nsrc : ndest;
     std::memcpy(dest,src,nm);
     if(ndest > nm) std::memset(dest+nm,' ',ndest-nm); // blank fill
   }
}
// splicer begin class.Class1.C_definitions
// splicer end class.Class1.C_definitions

TUT_Class1 * TUT_Class1_new_0(int test1, double test2, bool TorF,
    TUT_Class1 * SHC_rv)
{
    // splicer begin class.Class1.method.new_0
    Class1 *SHCXX_rv = new Class1(test1, test2, TorF);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end class.Class1.method.new_0
}

TUT_Class1 * TUT_Class1_new_1(int test1, double test2, bool TorF,
    int o_test, TUT_Class1 * SHC_rv)
{
    // splicer begin class.Class1.method.new_1
    Class1 *SHCXX_rv = new Class1(test1, test2, TorF, o_test);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end class.Class1.method.new_1
}

TUT_Class1 * TUT_Class1_new_2(int test1, double test2, bool TorF,
    int o_test, double o_test2, TUT_Class1 * SHC_rv)
{
    // splicer begin class.Class1.method.new_2
    Class1 *SHCXX_rv = new Class1(test1, test2, TorF, o_test, o_test2);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end class.Class1.method.new_2
}

TUT_Class1 * TUT_Class1_new_3(int test1, double test2, bool TorF,
    int o_test, double o_test2, bool o_TorF, TUT_Class1 * SHC_rv)
{
    // splicer begin class.Class1.method.new_3
    Class1 *SHCXX_rv = new Class1(test1, test2, TorF, o_test, o_test2,
        o_TorF);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end class.Class1.method.new_3
}

void TUT_Class1_delete(TUT_Class1 * self)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.delete
    delete SH_this;
    self->addr = nullptr;
    // splicer end class.Class1.method.delete
}

void TUT_Class1_receive_str(TUT_Class1 * self, TUT_str1 * arg)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.receive_str
    str1 * SHCXX_arg = static_cast<str1 *>(static_cast<void *>(arg));
    SH_this->receive_str(SHCXX_arg);
    // splicer end class.Class1.method.receive_str
}

void TUT_Class1_set_names(TUT_Class1 * self, char **names, int name_len)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.set_names
    SH_this->set_names(names, name_len);
    // splicer end class.Class1.method.set_names
}

void TUT_Class1_set_names_bufferify(TUT_Class1 * self, char *names,
    long Snames, int Nnames, int name_len)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.set_names_bufferify
    char **SHCXX_names = ShroudStrArrayAlloc(names, Snames, Nnames);
    SH_this->set_names(SHCXX_names, name_len);
    ShroudStrArrayFree(SHCXX_names, Snames);
    // splicer end class.Class1.method.set_names_bufferify
}

void TUT_Class1_set_names2(TUT_Class1 * self, char **names,
    int name_len)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.set_names2
    SH_this->set_names2(names, name_len);
    // splicer end class.Class1.method.set_names2
}

void TUT_Class1_set_names2_bufferify(TUT_Class1 * self, char *names,
    long Snames, int Nnames, int name_len)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.set_names2_bufferify
    char **SHCXX_names = ShroudStrArrayAlloc(names, Snames, Nnames);
    SH_this->set_names2(SHCXX_names, name_len);
    ShroudStrArrayFree(SHCXX_names, Snames);
    // splicer end class.Class1.method.set_names2_bufferify
}

void TUT_Class1_test_names2(TUT_Class1 * self)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.test_names2
    SH_this->test_names2();
    // splicer end class.Class1.method.test_names2
}

void TUT_Class1_get_name(TUT_Class1 * self, char * name_list, int idx)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.get_name
    std::string SHCXX_name_list;
    SH_this->get_name(&SHCXX_name_list, idx);
    strcpy(name_list, SHCXX_name_list.c_str());
    // splicer end class.Class1.method.get_name
}

void TUT_Class1_get_name_bufferify(TUT_Class1 * self, char * name_list,
    int Nname_list, int idx)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.get_name_bufferify
    std::string SHCXX_name_list;
    SH_this->get_name(&SHCXX_name_list, idx);
    ShroudStrCopy(name_list, Nname_list, SHCXX_name_list.data(),
        SHCXX_name_list.size());
    // splicer end class.Class1.method.get_name_bufferify
}

void TUT_Class1_test_struct(TUT_Class1 * self)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.test_struct
    SH_this->test_struct();
    // splicer end class.Class1.method.test_struct
}

}  // extern "C"