#include <iostream>
using namespace std;
 
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

typedef int ListEntry;
class OrderedList2{ 
    public:
        OrderedList2();
        void insert(ListEntry x);
        void remove(ListEntry x);
        bool empty();
        bool full();
        void clear();
        int size();
        int search(ListEntry x);
        void searchInsert(ListEntry x);
        int range(int min, int max); //random
    private:
        struct ListNode;
        typedef ListNode * ListPointer;
        
        struct ListNode{
            ListEntry entry;
            ListPointer nextNode;
            int freq;
        };

        int count;
        ListPointer head, sentinel;       
};

#endif