#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

typedef int StackEntry;
class Stack{
    public:
        Stack();
        ~Stack();
        void push(StackEntry x);
        void pop(StackEntry &x);
        bool empty();
        bool full();
        void clear();
        int size();
        void getTop(StackEntry &x);
        string toString();
        StackEntry get(int i);
        void change(int i, StackEntry x);
        
    private:
        static const int MAX = 100;
        StackEntry dados[MAX + 1];
        int top;
};

#endif