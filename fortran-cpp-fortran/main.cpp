#include <vector>
#include <iostream>

using namespace std;

// C++ -> F
extern "C" void* GetHandle(int a, char* Fstr);
extern "C" void ReleaseHandle(void* handle);

extern "C" void SetA(void* handle, int a);
extern "C" void Setdk(void* handle, double dk);
extern "C" void SetB(void* handle, const int* data, int data_size);
extern "C" void SetC(void* handle, int data[][2], int data_size);

extern "C" int QueryA(void* handle);
extern "C" double Getdk(void* handle);
extern "C" void QueryBSize(void* handle, int* data_size);
// extern "C" void QueryBData(void *handle, int *data);
extern "C" void QueryBData(void *handle, int data[2]);
extern "C" void QueryCData(void *handle, int data[][2], int n);
extern "C" double add_a_dk(void* handle);

extern "C" void getFstr(void* handle, char* Fstr);

class SimpleF
{
private:
  void *handle;
public:
  SimpleF(int a, char* Fstr) 
  { 
    cout << "In main.cpp: Hello from SimpleF class constructor" << endl;
    cout << "In main.cpp: receiving a = " << a << endl;
    cout << "In main.cpp: receiving Fstr = " << Fstr << "..."<< endl;
    handle = GetHandle(a, Fstr);
    cout << "In main.cpp: done..." << endl ;
    // ::SetA(handle, a);
  }

  ~SimpleF() 
  { 
    ReleaseHandle(handle); 
  }

  void SetA(int a) 
  { 
    cout << "In main.cpp: Hello from SetA" << endl;
    ::SetA(handle, a);
  }
  
  int QueryA()
  { 
    cout << "In main.cpp: Hello from get A" << endl;
    return ::QueryA(handle); 
  }

  void getFstr(char* Fstr){
    cout <<  "In main.cpp's getFstr: Hello from GetFstr" << endl;
    cout <<  "In main.cpp's getFstr: Receiving test string as: " << Fstr << "..." << endl;
    ::getFstr(handle, Fstr);
    cout << "In main.cpp's getFstr: returning string " << Fstr << "..." << endl;
  }

  void Setdk(double dk){
    ::Setdk(handle, dk);
  }

  double Getdk(){
    return ::Getdk(handle);
  }

  // void SetB(const vector<int>& b)
  // {
  //    ::SetB(handle, &b[0], b.size());
  // }
  void SetB(int n, int b[])
  {
     ::SetB(handle, b, n);
  }

  void SetC(int n, int b[][2])
  {
    cout << "In main.cpp's SetC: receiving b[0,0] = " << b[0][0] << "; b[0][1] = " << b[0][1] << endl;
    cout << "In main.cpp's SetC: receiving b[1,0] = " << b[1][0] << "; b[1][1] = " << b[1][1] << endl;
    ::SetC(handle, b, n);
  }

  // vector<int> QueryB2()
  // {
  //   // Get the data size, construct a suitable buffer, populate the buffer.
  //   cout << "In main.cpp: Hello from QuerryB2" << endl;
  //   int data_size = 1;
  //   cout << "In main.cpp: data_size = " << data_size << endl;
  //   ::QueryBSize(handle, &data_size);
  //   if (data_size == 0) return vector<int>();

  //   vector<int> data(data_size);
  //   // ::QueryBData(handle, &data[0]);

  //   // cout << "In main.cpp: data = " << data[0] << endl;

  //   return data;
  // }

  void QueryB(int n, int b[]){
    cout << "In main.cpp: Hello from get B" << endl;
    ::QueryBData(handle,b);
  }

  void QueryC(int n, int b[][2]){
    cout << "In main.cpp: Hello from get C" << endl;
    cout << "n = " << n << endl;
    ::QueryCData(handle,b,n);
  }


  double add_a_dk(){
    return ::add_a_dk(handle);
  }

};

// F -> C++
extern "C" {
  SimpleF* SimpleF__new(int a, char* Fstr){
    cout << "In main.cpp: Hello from Simple__new in cpp" << endl;
    return new SimpleF(a,Fstr);
  }
  
  void SimpleF__setA(SimpleF* obj, int a){
    cout << "In main.cpp's SimpleF_setA: receiving a = " << a << endl;
    obj -> SetA(a);
  }

  int SimpleF__getA(SimpleF* obj){
    return obj->QueryA();
  }

  void SimpleF__getFstr(SimpleF* obj, char* Fstr){
    cout << "In main.cpp's SimpleF__getFstr: receiving string " << Fstr << "..." << endl;
    obj->getFstr(Fstr);
    cout << "In main.cpp's SimpleF__getFstr: returning string " << Fstr << "..." << endl;
  }

  void SimpleF__setB(SimpleF* obj, int n, int b[]){
    cout << "In main.cpp's SimpleF_setB: receiving b[0] = " << b[0] << "; b[1] = " << b[1] << endl;
    obj -> SetB(n,b);
  }

  void SimpleF__setC(SimpleF* obj, int n, int b[][2]){
    cout << "In main.cpp's SimpleF_setB: receiving b[0,0] = " << b[0][0] << "; b[0][1] = " << b[0][1] << endl;
    cout << "In main.cpp's SimpleF_setB: receiving b[1,0] = " << b[1][0] << "; b[1][1] = " << b[1][1] << endl;
    obj -> SetC(n,b);
  }

  void SimpleF__getB(SimpleF* obj, int n, int b[2]){
    cout << "In main.cpp: receiving n = " << n << endl;
    cout << "In main.cpp: receiving b junk values as " << b[0] << " and " << b[1] << endl;
    // return obj->QueryB();
    obj -> QueryB(n,b);
    cout << "In main.cpp: Returning previously defined values of b as " << b[0] << " and " << b[1] << endl;
  }

  void SimpleF__getC(SimpleF* obj, int n, int b[][2]){
    cout << "In main.cpp: receiving n = " << n << endl;
    cout << "In main.cpp's SimpleF_setB: receiving junk... b[0,0] = " << b[0][0] << "; b[0][1] = " << b[0][1] << endl;
    cout << "In main.cpp's SimpleF_setB: receiving junk... b[1,0] = " << b[1][0] << "; b[1][1] = " << b[1][1] << endl;
    // return obj->QueryB();
    obj -> QueryC(n,b);
    cout << "In main.cpp's SimpleF_setB: returning b[0,0] = " << b[0][0] << "; b[0][1] = " << b[0][1] << endl;
    cout << "In main.cpp's SimpleF_setB: returning b[1,0] = " << b[1][0] << "; b[1][1] = " << b[1][1] << endl;
  }
  
}


// int main()
// {
//   SimpleF x; // create object...
//   //x.SetA(99);
//   cout << x.QueryA() << endl;

//   vector<int> testvector(2,100);
//   x.SetB(testvector);
//   cout << x.QueryB()[0] << ' ' << x.QueryB()[1] << endl;

//   x.Setdk(0.015);
//   cout << "dk = " << x.Getdk() << endl;

//   cout << x.add_a_dk() << endl;

//   return 0;
// }
