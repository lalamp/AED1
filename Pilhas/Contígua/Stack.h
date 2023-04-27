#include <iostream>
using namespace std;

typedef int StackEntry;

class Stack{
    public:
        Stack();
        void push(StackEntry x);
        void pop(StackEntry &x);
        bool empty();
        bool full();
        void clear();
        int size();
        void getTop(StackEntry &x);
    private:
        static const int MAX = 100;
        StackEntry dados[MAX + 1];
        int top;
};