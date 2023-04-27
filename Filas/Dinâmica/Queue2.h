#include <iostream>
using namespace std;

typedef int QueueEntry;

class Queue2{ 
    public:
        Queue2();
        void append(QueueEntry x);
        void serve(QueueEntry &x);
        bool empty();
        bool full();
        void clear();
        int size();
        void getFront(QueueEntry &x);
        void getRear(QueueEntry &x);
    
    private:
        struct QueueNode; // declaracao forward
        typedef QueueNode (* QueuePointer); //ponteiro para uma estrutura QueueNode
        struct QueueNode{ 
            QueueEntry entry; 
            QueuePointer nextNode; 
        };

        QueuePointer head, tail;
};