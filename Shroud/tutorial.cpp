#include <iostream>
#include "tutorial.hpp"
#include <sstream>

static int global_fixed_array[] = {12,23,34};

static int global_int2d[] = {12,45,23,56,34,67};

namespace tutorial {

    Class1::Class1() {cout << "Object is being created!" << endl;}
    Class1::~Class1() {cout << "Object is being deleted!" << endl;}

    void Class1 :: acceptCharArrayIn(char **names, int N)
    {
        cl_size = N;
        closurelist = new string[N];

        cout << "Words received are: " << endl;
        for(int i = 0; i < N; i++){
            cout << names[i] << endl;
            closurelist[i] = names[i];
        }
    }

    void Class1 :: set_test(int N){
        cout << "N = " << N << endl;
        test_len = N;
        test = new int [N];
        // test = (int *) &global_fixed_array;
        for(int i = 0; i < N; i++){
            test[i] = i+1;
        }

        cout << "Ok... so far, so good" << endl;
    }

    void Class1 :: set_TwoDarray(int N, int M){
        cout << "N = " << N << ", M = " << M << endl;
        cout << "So far, so good..." << endl;
        TwoDA_len1 = N;
        TwoDA_len2 = M;
        TwoDarray = new int [N*M];

        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                count = count + 1;
                /* Fortran is column major, so here we must asign values as to the transpose
                of the matrix we want to get on fortran side */
                TwoDarray[N*j + i] = count;
            }
        }

    }

    int* Class1 :: get_test_ptr(int *N){
        cout << "Size of pointer array: " << test_len << endl;
        *N = test_len;
        return test;
    }

    int* Class1 :: get_TwoDarray_ptr(int *N, int *M){
        cout << "Sizes of pointer array: " << TwoDA_len1 << " and " << TwoDA_len2 << endl;
        *N = TwoDA_len1;
        *M = TwoDA_len2;
        cout << "So far, so good..." << endl;
        return TwoDarray;
    }

    void Class1 :: Method1(){
        cout << "In tutorial.cpp: retrieving strings: " << endl;
        for(int i = 0; i < cl_size; i++){
            cout << closurelist[i] << endl;
        }

        cout << "In tutorial.cpp: retrieving 1D array: " << endl;
        for(int i = 0; i < test_len; i++){
            cout << "1Darray[" << i << "] = " << test[i] << endl;
        }

        cout << "In tutorial.cpp: retrieving 2D array: " << endl;
        for(int i = 0; i < TwoDA_len1; i++){
            for(int j = 0; j < TwoDA_len2; j++){
                cout << "2Darray[" << i << ", " << j << "] = " << TwoDarray[TwoDA_len1*j + i] << endl;
            }
        }

    }

    bool Class1 :: check(int N){
        cout << "So far, so good..." << endl;
        if(N < 10){
            return true;
        }
        else{
            return false;
        }
    }


}