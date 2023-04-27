#include <iostream>
#include "List2.h"
using namespace std;

List2::List2(){
    head = NULL;
    count = 0;
}

List2::~List2(){
    clear();
}
/*
List2::~List(){ 
    ListPointer q;
    while(head != NULL) 
        q = head;
        head = head->nextNode;
        delete q;
    }
}
*/

bool List2::empty(){
    return (head == NULL);
}

bool List2::full(){
    return false;
}

void List2::setPosition(int p, ListPointer &current){
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }
    current = head;
    for(int i = 2; i <= p; i++){
        current = current->nextNode;
    }
}
/*
pré-condição: p é uma posição válida na lista
pós-condição: o ponteiro current aponta para o nó na lista com posição p
*/

void List2::insert(int p, ListEntry x){
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    ListPointer newNode, current;
    newNode = new ListNode;
    newNode->entry = x;

    if(p == 1){
        newNode->nextNode = head;
        head = newNode;
    }
    else{
        setPosition(p-1, current);
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    count++;
}


void List2::remove(int p, ListEntry &x){
    if(empty()){
        cout << "Lista vazia" << endl;
        abort();
    }
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    ListPointer oldNode, current;

    if(p == 1){
        oldNode = head;
        head = oldNode->nextNode;
        delete oldNode;
    }
    else{
        setPosition(p-1, current);
        oldNode = current->nextNode;
        current->nextNode = oldNode->nextNode;
    }

    x = oldNode->entry;
    delete oldNode;
    count--;
}

void List2::retrieve(int p, ListEntry &x){
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    ListPointer current;
    setPosition(p, current);
    x = current->entry;
}

void List2::replace(int p, ListEntry x){
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    ListPointer current;
    setPosition(p, current);
    current->entry = x;
}


void List2::clear(){
    ListPointer q;
    while(head != NULL){ 
        q = head;
        head = head->nextNode;
        delete q;
    }
}

int List2::size(){
    return count;
}

int List2::search(ListEntry x){
    ListPointer p;
    p = head;
    int i = 1;

    while(p != NULL && p->entry != x){
        p = p->nextNode;
        i++;
    }

    return(p == NULL ? 0 : i);
}
