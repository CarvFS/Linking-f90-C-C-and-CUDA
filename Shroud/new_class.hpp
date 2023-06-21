#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
using namespace std;

class NewClass
{
    public:
        NewClass();
        ~NewClass();

        double dk;

        void print_message();
        double get_dk();
};

#endif // CLASSES_HPP