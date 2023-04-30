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
extern "C" void QueryBData(void *handle, int *data);
extern "C" double add_a_dk(void* handle);

class SimpleF
{
private:
  void *handle;
public:
  SimpleF() 
  { 
    cout << "In main.cpp: Hello from SimpleF class constructor" << endl;
    handle = GetHandle(); 
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

  void SetB(const vector<int>& b)
  {
     ::SetB(handle, &b[0], b.size());
  }

  vector<int> QueryB()
  {
    // Get the data size, construct a suitable buffer, populate the buffer.
    int data_size;
    ::QueryBSize(handle, &data_size);
    if (data_size == 0) return vector<int>();

    vector<int> data(data_size);
    ::QueryBData(handle, &data[0]);
    return data;
  }

  double add_a_dk(){
    return ::add_a_dk(handle);
  }

};

// F -> C++
extern "C" {
  SimpleF* SimpleF__new(){
    cout << "In main.cpp: Hello from Simple__new in cpp" << endl;
    return new SimpleF();
  }
  
  void SimpleF__setA(SimpleF* obj, int a){
    cout << "In main.cpp's SimpleF_setA: receiving a = " << a << endl;
    obj -> SetA(a);
  }

  int SimpleF__getA(SimpleF* obj){
    return obj->QueryA();
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
