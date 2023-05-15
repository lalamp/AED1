// Declaração/interface para sacola
#include <cstring>
using namespace std;

#ifndef BAG_H
#define BAG_H
class Bag{ 
    public:
        Bag();
        void insert(int newEntry);
        int occurrence(int entry);
        void remove(int entry); //implementar
        bool full();
        int size();
        string toString();
  private:
        static const int CAPACITY = 20;
        int data[CAPACITY+1];
        int used;
};

#endif