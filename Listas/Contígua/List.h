#include <iostream>
using namespace std;
 
typedef int ListEntry;

class List{ 
    public:
        List();
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
        static const int MaxList = 100;
        int count;
        ListEntry entry[MaxList+1]; 
};