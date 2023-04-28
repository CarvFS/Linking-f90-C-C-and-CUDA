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
    handle = GetHandle(); 
  }

  ~SimpleF() 
  { 
    ReleaseHandle(handle); 
  }

  void SetA(int a) 
  { 
    cout << "Hello from SetA" << endl;
    ::SetA(handle, a); 
  }
  
  int QueryA()
  { 
    cout << "Hello from get A" << endl;
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
extern "C" void Set_A(SimpleF*, int a);
extern "C" int get_a(SimpleF*);

void Set_A(SimpleF* simp, int a){
  cout << "Trying to set A = " << a << endl;
  static_cast<SimpleF*>(simp)->SetA(a);
}

// int get_a(SimpleF* simp){
//   cout << "Trying to get A..." << endl;
//   static_cast<SimpleF*>(simp)->QueryA();
// }


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
