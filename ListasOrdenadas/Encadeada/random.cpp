#include <iostream>
#include "OrderedList2.h"
using namespace std;

int OrderedList2::range(int min, int max){
    ListPointer p = head;
    int n = 0;

    while(p != sentinel){
        if(p->entry >= min && p->entry <= max){
            n++;
        } 
        p = p->nextNode;
    } 
    return n;
}