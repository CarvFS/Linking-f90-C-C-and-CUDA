#ifndef CLASS1_HPP
#define CLASS1_HPP
#include "struct.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include<string.h>
using namespace std;

class Class1
{
public:
  Class1(int test1, double test2, bool TorF, int o_test = 1, double o_test2 = 0.5, bool o_TorF = true);
  ~Class1();

  void receive_struct(str1 *arg);
  void test_struct();

};


#endif // CLASS1_HPP