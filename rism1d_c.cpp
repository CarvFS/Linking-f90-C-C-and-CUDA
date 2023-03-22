#include <iostream>
using namespace std;

class rism1d{
    private:
        int charlen = 8;
        int maxep0 = 4;

    public:
        string closureID = "kh";
        string savefile = "rism.sav";

        int extra_precision = 1;
        int Mdiis_nvec = 0;
        int mdiis_method = 2;

        void print_closure(){
            cout << closureID << endl;
        }
};

extern "C"{

    void print_closure_from_c(){ 
        rism1d obj;
        obj.print_closure();
    }

}