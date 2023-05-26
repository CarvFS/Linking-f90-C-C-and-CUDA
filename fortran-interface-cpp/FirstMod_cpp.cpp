#include <iostream>

using namespace std;

extern "C" struct  firstex {
    int* a; 
    double* dk;
};

extern "C"{
    void Initialize_firstex_v1(firstex* p, int a, double dk){
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Data on C++ side!" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Receiving values to set..." << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: a = " << a << ", dk = " << dk << endl;
        
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Printing pre-defined values:" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: a = " << *p->a << ", dk = " << *p->dk << endl;
        
        *p->a = a;
        *p->dk = dk;

        // **p_Fstr = *Fstr;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Printing new values:" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: a = " << *p->a << ", dk = " << *p->dk << endl;
    }

    void Initialize_firstex_v2(int** p_a, double** p_dk, char** p_Fstr, int a, double dk, char* Fstr){
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: Data on C++ side!" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: Receiving values to set..." << endl;
        cout << "FirstMod_cpp.cpp's Initialize_firstex_v2: a = " << a << ", dk = " << dk << ", Fstr = " << Fstr << "..." << endl;
        
        cout << "FirstMod_cpp.cpp's Initialize_firstex_v2: Printing pre-defined values:" << endl;
        cout << "FirstMod_cpp.cpp's Initialize_firstex_v2: a = " << **p_a << ", dk = " << **p_dk << ", Fstr = " << *p_Fstr << endl;
        
        **p_a = a;
        **p_dk = dk;

        int i = 0;
        while(Fstr[i] != '\0'){
            // cout << Fstr[i] << endl;
            p_Fstr[0][i] = Fstr[i];
            i++;
        }
        p_Fstr[0][i] = '\0';

        // **p_Fstr = *Fstr;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: Printing new values:" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: a = " << **p_a << ", dk = " << **p_dk << ", Fstr = " << *p_Fstr << "..." << endl;
    }
}
