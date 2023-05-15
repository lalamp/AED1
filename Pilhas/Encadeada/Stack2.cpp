#include <iostream>
#include <sstream> 
#include "Stack2.h"
using namespace std;

Stack2::Stack2(){
    top = NULL;
}

Stack2::~Stack2(){
    clear();
}

bool Stack2::empty(){
    return (top == NULL);
}
bool Stack2::full(){
    return false;
}

void Stack2::push(StackEntry x){
    StackPointer p;
    p = new StackNode;
    if(p == NULL){
        cout << "Memória Insuficiente" << endl;
        abort();
    }

    p->entry = x;
    p->nextNode = top;
    top = p;
}

void Stack2::pop(StackEntry &x){
    if(empty()){
        cout << "Pilha vazia" << endl;
        abort();
    }

    StackPointer p;
    p = top;
    x = top->entry;
    top = top->nextNode;
    delete p;
}

void Stack2::clear(){
    int x;
    while(! empty()){
        pop(x);
    }
}
/*
void Stack::clear(){
    StackPointer p;
    while(top != NULL){
        p = top;
        top = top->nextNode;
        delete p; 
    }
}
*/

int Stack2::size(){ 
    StackPointer p;   
    p = top;
    int s = 0;
    
    while(p != NULL){
        s++;
        p = p->nextNode;
    }
    return s;
}

void Stack2::getTop(StackEntry &x){
    if(top == NULL){ 
        cout << "Pilha vazia";
        abort();
    }
    x = top->entry;
}
/*
void Stack::getTop(StackEntry &x){
    if(empty()){
        cout << “Pilha vazia”;
        abort();
    }
    pop(x);
    push(x);
}
*/