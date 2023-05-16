#include <iostream>
using namespace std;

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

typedef int ListEntry;
class OrderedList{ 
    public:
        OrderedList();
        void insert(ListEntry x);
        void remove(ListEntry x);
        bool empty();
        bool full();
        void clear();
        int size();
        int search(ListEntry x);
    private:
        static const int MaxList = 100;
        int count;
        ListEntry entry[MaxList+1]; 
};

#endif