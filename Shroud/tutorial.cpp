#include <iostream>
#include "tutorial.hpp"
// #include "NewClass.hpp"
#include <sstream>

static int global_fixed_array[] = {12,23,34};

static int global_int2d[] = {12,45,23,56,34,67};

namespace tutorial {
    Class1 :: Class1(int test1, double test2, bool TorF, int o_test, double o_test2, bool o_TorF){
        cout << "Object is being created!" << endl;
        // print pre-defined/optional arguments
        cout << "o_test = " << o_test << endl;
        cout << "o_test2 = " << o_test2 << endl;
        cout << "o_TorF = " << o_TorF << endl;
    }
    
    Class1::~Class1(){
        cout << "Object is being deleted!" << endl;
    }

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

        int count = 10;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                count = count + 1;
                /* Fortran is column major, so here we must asign values as to the transpose
                of the matrix we want to get on fortran side */
                TwoDarray[N*j + i] = count;
                cout << "2D = [" << i << ", " << j << "] = " << TwoDarray[N*j + i] << endl;
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

    int* Class1 :: get_2d_new(int *N, int *M, int arg1, int arg2){
        *N = 1;
        *M = 1;
        arg1 = arg1 - 1;
        arg2 = arg2 - 1;
        return &TwoDarray[TwoDA_len1*arg2 + arg1];
    }

    int* Class1 :: get_2d_new(int *N, int *M, int arg){
        *N = TwoDA_len1;
        *M = 1;
        arg = arg - 1;
        int *temp = new int [TwoDA_len1];

        for(int i = 0; i < TwoDA_len1; i++){
            temp[i] = TwoDarray[TwoDA_len1*arg + i];
        }
        
        return temp;
    }

    void Class1 :: Method1(int* vec2d, int o_test, int* value, char* word2, bool o_bool){
        cout << "In tutorial.cpp: retrieving strings: " << endl;

        cout << "o_test = " << o_test << endl;

        cout << "Printing 1D array: (12,23,34) as standard" << endl;
        for(int i = 0; i < 3; i++){
            cout << "value[" << i << "] = " << value[i] << endl;
        }

        cout << "Receiving 2D array:" << endl;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << "value[" << i << "," << j << "] = " << vec2d[i*2+j] << endl;
            }
        }

        cout << "string is: " << word2 << "." << endl;

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

        cout << obj1.dk << endl;

        cout << "Boolen is: " << o_bool << endl;
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

    double Class1 :: get_dk(){
        return obj1.dk;
    }

    // int Class1 :: get_intvalue(){
    //     return 12;
    // }


}