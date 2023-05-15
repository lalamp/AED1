#include <iostream>
using namespace std;

#ifndef LIST2_H
#define LIST2_H

typedef int ListEntry;
class List2{ 
    public:
        List2();
        void insert(int p, ListEntry x);
        void remove(int p, ListEntry &x);
        void retrieve(int p, ListEntry &x);
        void replace(int p, ListEntry x);
        bool empty();
        bool full();
        void clear();
        int size();
        int search(ListEntry x);
    private:
        struct ListNode;
        typedef ListNode * ListPointer;
        
        struct ListNode{
            ListEntry entry;
            ListPointer nextNode;
        };

        int count;
        ListPointer head;

        void setPosition(int p, ListPointer &x);        
};

#endif