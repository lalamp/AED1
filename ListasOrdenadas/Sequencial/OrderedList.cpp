#include <iostream>
#include "OrderedList.h"
using namespace std;

OrderedList::OrderedList(){
    count = 0;
}

OrderedList::~OrderedList(){
    cout << "Lista destruída" << endl;
}

bool OrderedList::empty(){
    return (count == 0);
}


bool OrderedList::full(){
    return (count == MaxList);
}

void OrderedList::insert(ListEntry x){
    if(full()){
        cout << "Lista cheia" << endl;
        abort();
    }

    int i = 1;
    while(entry[i] < x){
        i++;
    }


    for(int j = count; j >= i; j--){  
        entry[j+1] = entry[j];
    }

    entry[i] = x;
    count++;
}

void OrderedList::remove(ListEntry x){
    if(empty()){
        cout << "Lista vazia" << endl;
        abort();
    }

    int i = 1;
    while(entry[i] != x){
        i++;
    }

    for(int j = i; j < count; j++){   
        entry[j] = entry[j+1];
    }

    count--;
}

void OrderedList::clear(){
    count = 0;
}

int OrderedList::size(){
    return count;
}

int OrderedList::search(ListEntry x){
    int i = 1;
    while(entry[i] != x){
        i++;
    }
    return (i > count ? 0 : i);
}
