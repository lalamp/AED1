#include <iostream>
using namespace std;

typedef int QueueEntry;

class Queue{ 
    public:
        Queue(); 
        void append(QueueEntry x);
        void serve(QueueEntry &x);
        bool empty();
        bool full();
        void clear();
        int size();
        void getFront(QueueEntry &x);
        void getRear(QueueEntry &x);

    private:
        static const int MaxQueue = 100;
        int head;
        int tail; 
        int count; 
        QueueEntry entry[MaxQueue+1]; 
};