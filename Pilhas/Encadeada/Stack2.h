#include <iostream>
using namespace std;

#ifndef STACK2_H
#define STACK2_H

typedef int StackEntry;
class Stack2{
    public:
        Stack2();
        void push(StackEntry x);
        void pop(StackEntry &x);
        bool empty();
        bool full();
        void clear();
        int size();
        void getTop(StackEntry &x);
    private:
    struct StackNode; //declaração foward (?)
    typedef StackNode (*StackPointer);
        struct StackNode{
            StackEntry entry;
            StackPointer nextNode;
        };
        StackPointer top;    
};

#endif