// typesTutorial.h
// This file is generated by Shroud 0.12.1. Do not edit.
// For C users and C++ implementation

#ifndef TYPESTUTORIAL_H
#define TYPESTUTORIAL_H


#ifdef __cplusplus
extern "C" {
#endif

// helper capsule_TUT_Class1
struct s_TUT_Class1 {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_TUT_Class1 TUT_Class1;

// helper capsule_data_helper
struct s_TUT_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_TUT_SHROUD_capsule_data TUT_SHROUD_capsule_data;

void TUT_SHROUD_memory_destructor(TUT_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESTUTORIAL_H
