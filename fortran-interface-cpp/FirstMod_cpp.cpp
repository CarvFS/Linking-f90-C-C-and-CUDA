#include <iostream>

using namespace std;

extern "C" struct  firstex {
    int* a; 
    double* dk;
    char* Fstr;
    int* B;
    int* B2;
};

extern "C"{
    void Initialize_firstex_v1(firstex* p, int n, int a, double dk, char* Fstr){
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Data on C++ side!" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Receiving values to set..." << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: a = " << a << ", dk = " << dk << ", Fstr = " << Fstr << endl;
        
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Printing pre-defined values:" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: a = " << *p->a << ", dk = " << *p->dk << endl; 
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Fstr is: ";
        int i = 0;
        while(p->Fstr[i] != '\0'){
            cout << p->Fstr[i];
            i++;
        }
        cout << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: N_1d = " << n << ". Pre-defined values for B are:" << endl;
        for(int i = 0; i < n; i++){
            cout << "i = " << i << ", B = " << p->B[i] << endl;
        }

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: N_1d = " << n << ". Pre-defined values for B_2D are:" << endl;
        for(int i = 0; i < n*n; i++){
            cout << "i = " << i << ", B = " << p->B2[i] << endl;
        }

        // Setting new values for "a" and "dk"
        *p->a = a;
        *p->dk = dk;

        // Setting new value for Fstr
        i = 0;
        while(Fstr[i] != '\0'){
            p->Fstr[i] = Fstr[i];
            i++;
        }
        p->Fstr[i] = '\0';

        // Setting new values for B 1D
        for(int i = 0; i < n; i++){
            p->B[i] = 123+i;
        }

        // Setting new values for B 2D
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                p->B2[i+n*j] = 321+n*i+j;
            }
        }

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Printing new values:" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: a = " << *p->a << ", dk = " << *p->dk << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: Fstr = ";
        i=0;
        while(p->Fstr[i] != '\0'){
            cout << p->Fstr[i];
            i++;
        }
        cout << endl;

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: New values for B: " << endl;
        for(int i = 0; i < n; i++){
            cout << "i = " << i << ", B = " << p->B[i] << endl;
        }

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v1: New values for B2: " << endl;
        for(int i = 0; i < n*n; i++){
            cout << "i = " << i << ", B2 = " << p->B2[i] << endl;
        }
    }

    void Initialize_firstex_v2(int** p_a, double** p_dk, char** p_Fstr, int** p_1dptr, int** p_2dptr, int N, int a, double dk, char* Fstr){
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: Data on C++ side!" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: Receiving values to set..." << endl;
        cout << "FirstMod_cpp.cpp's Initialize_firstex_v2: a = " << a << ", dk = " << dk << ", Fstr = " << Fstr << "..." << endl;
        
        cout << "FirstMod_cpp.cpp's Initialize_firstex_v2: Printing pre-defined values:" << endl;
        cout << "FirstMod_cpp.cpp's Initialize_firstex_v2: a = " << **p_a << ", dk = " << **p_dk << ", Fstr = " << *p_Fstr << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: B = " << p_1dptr[0][0] << ", " << p_1dptr[0][1] << ", " << p_1dptr[0][2] << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: B2: " << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << "B2 = " << p_2dptr[0][i+N*j] << endl;
            }
        }

        // Setting new values for and "a" and "dk"
        **p_a = a;
        **p_dk = dk;

        // Setting new value for Fstr
        int i = 0;
        while(Fstr[i] != '\0'){
            p_Fstr[0][i] = Fstr[i];
            i++;
        }
        p_Fstr[0][i] = '\0';

        // Setting new values for 1D array
        for(int i = 0; i < N; i++){
            p_1dptr[0][i] = i+123;
        }

        // Setting new values for 2D array
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                p_2dptr[0][i+N*j] = 321 + N*i + j;
            }
        }

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: Printing new values:" << endl;
        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: a = " << **p_a << ", dk = " << **p_dk << ", Fstr = " << *p_Fstr << "..." << endl;

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: receiving N = " << N << endl;

        cout << "In FirstMod_cpp.cpp's Initialize_firstex_v2: B = " << p_1dptr[0][0] << ", " << p_1dptr[0][1] << ", " << p_1dptr[0][2] << endl;
    }
}
