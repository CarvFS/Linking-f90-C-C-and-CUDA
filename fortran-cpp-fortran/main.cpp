#include <vector>
#include <iostream>

using namespace std;

// C++ -> F
extern "C" void* GetHandle();
extern "C" void ReleaseHandle(void* handle);
extern "C" void SetA(void* handle, int a);
extern "C" int QueryA(void* handle);
extern "C" void Setdk(void* handle, double dk);
extern "C" double Getdk(void* handle);
extern "C" void SetB(void* handle, const int* data, int data_size);
extern "C" void QueryBSize(void* handle, int* data_size);
// extern "C" void QueryBData(void *handle, int *data);
extern "C" void QueryBData(void *handle, int data[2]);
extern "C" double add_a_dk(void* handle);

class SimpleF
{
private:
  void *handle;
public:
  SimpleF(int a) 
  { 
    cout << "In main.cpp: Hello from SimpleF class constructor" << endl;
    cout << "receiving a = " << a << endl;
    handle = GetHandle(); 
    ::SetA(handle, a);
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

  // vector<int> QueryB()
  // {
  //   // Get the data size, construct a suitable buffer, populate the buffer.
  //   int data_size;
  //   ::QueryBSize(handle, &data_size);
  //   if (data_size == 0) return vector<int>();

  //   vector<int> data(data_size);
  //   ::QueryBData(handle, &data[0]);
  //   return data;
  // }

  void QueryB(int n, int b[]){
    cout << "In main.cpp: Hello from get B" << endl;
    ::QueryBData(handle,b);
  }

  double add_a_dk(){
    return ::add_a_dk(handle);
  }

};

// F -> C++
extern "C" {
  SimpleF* SimpleF__new(int a){
    cout << "In main.cpp: Hello from Simple__new in cpp" << endl;
    return new SimpleF(a);
  }
  
  void SimpleF__setA(SimpleF* obj, int a){
    cout << "In main.cpp's SimpleF_setA: receiving a = " << a << endl;
    obj -> SetA(a);
  }

  int SimpleF__getA(SimpleF* obj){
    return obj->QueryA();
  }

  void SimpleF__setB(SimpleF* obj, int n, int b[]){
    cout << "In main.cpp's SimpleF_setB: receiving b[0] = " << b[0] << "; b[1] = " << b[1] << endl;
    obj -> SetB(n,b);
  }

  // vector<int> SimpleF__getB(SimpleF* obj, int n){
  //   cout << "receiving n = " << n << endl;
  //   return obj->QueryB();
  // }
  void SimpleF__getB(SimpleF* obj, int n, int b[2]){
    cout << "In main.cpp: receiving n = " << n << endl;
    cout << "In main.cpp: receiving b junk values as " << b[0] << " and " << b[1] << endl;
    // return obj->QueryB();
    obj -> QueryB(n,b);
    cout << "In main.cpp: Returning previously defined values of b as " << b[0] << " and " << b[1] << endl;
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
