#include <iostream>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

typedef int ArrayEntry;
class Array{
    public:
        Array(ArrayEntry l1, ArrayEntry u1);
        ~Array();
        void store(int index, ArrayEntry value);
        void retrieve(int index, ArrayEntry &value);
        int size();
        
    private:
        static const int MAX = 100;
        ArrayEntry array[MAX + 1];
};

#endif