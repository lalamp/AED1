#include <iostream>
#include "Queue2.h"
using namespace std;

Queue2::Queue2(){
    head = tail = NULL; 
}

Queue2::~Queue2(){
    QueuePointer p;
    while(head != NULL){
        p = head;
        head = head->nextNode;
        delete p;
    }
}
/*
Queue::~Queue(){
    clear();
}
*/

bool Queue2::empty(){
    return (head == NULL);
}

bool Queue2::full(){
    return false;
}

void Queue2::append(QueueEntry x){ 
    QueuePointer p;
    p = new QueueNode;

    if(p == NULL){ 
        cout << "Memória insuficiente";
        abort();
    }
    p->entry = x;
    
    if(empty())
        head = tail = p;
    else{ 
        tail->nextNode = p;
        tail = p;
    }
    p->nextNode = NULL; //tail->nextNode = NULL
}

void Queue2::serve(QueueEntry &x){ 
    QueuePointer p;

    if(empty()){ 
        cout << "Fila vazia";
        abort();
    }

    x = head->entry;
    p = head;
    head = head->nextNode;
    delete p;

    if(head = NULL){
        tail = NULL;
    }
}

void Queue2::clear(){
    int x;
    while(!empty()){
        serve(x);
    }
}
/*
void Queue2::clear(){
    QueuePointer p;
    while(head != NULL){
        p = head;
        head = head->nextNode;
        delete p;
    }
    tail = NULL;
}
*/

int Queue2::size(){
    int s = 0;
    QueuePointer p;
    p = head;
    
    while(p != NULL){ 
        s++;
        p = p->nextNode;
    }
    return s;
}

void Queue2::getFront(QueueEntry &x){
    if(empty()){
        cout << "Fila vazia" << endl;
        abort();
    }
    x = head->entry;
}

void Queue2::getRear(QueueEntry &x){
    if(empty()){
        cout << "Fila vazia" << endl;
        abort();
    }
    x = tail->entry;
}