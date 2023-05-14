#include <iostream>
#include "OrderedList2.h"
using namespace std;

OrderedList2::OrderedList2(){
    sentinel = new ListNode;
    head = sentinel;
    count = 0;
}

OrderedList2::~OrderedList2(){
    clear();
    delete sentinel;
}
/*
List2::~List(){ 
    ListPointer q;
    while(head != sentinel) 
        q = head;
        head = head->nextNode;
        delete q;
    }
    delete sentinel;
}
*/

bool OrderedList2::empty(){
    return (head == sentinel);
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a list está vazia; false caso contrário
*/

bool OrderedList2::full(){
    return false;
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a list está cheia; false caso contrário
*/

void OrderedList2::insert(ListEntry x){
    ListPointer p, q;

    sentinel->entry = x;
    p = head;
    while(p->entry < x){
        p = p->nextNode;
    }

    q = new ListNode;
    if(q = NULL){
        cout << "Memória Insuficiente";
        abort();
    }

    if(p == sentinel){
        p->nextNode = q;
        sentinel = q;
    }
    else{
        *q = *p;
        p->entry = x;
        p->nextNode = q;
    }
    count++;
}
/*
pré-condição: lista não está cheia
pós-condição: o item x é armazenado em ordem na list
*/


void OrderedList2::remove(ListEntry x){
    ListPointer p = NULL, q = head;

    sentinel->entry = x;
    while(q->entry < x){
        p = q;
        q = q->nextNode;
    }

    if(q->entry != x || q == sentinel){
        return;
    }
    if(q == head){
        head = q->nextNode;
    }
    else{
        p->nextNode = q->nextNode;
    }

    delete q;
    count--;
}
/*
pré-condição: nenhuma
pós-condição: o item x é removido da list (caso exista), mantendo-a ordenada
*/

void OrderedList2::clear(){
    ListPointer q;
    while(head != sentinel){ 
        q = head;
        head = head->nextNode;
        delete q;
    }
    count = 0;
}
/*
pré-condição : nenhuma 
pós-condição: todos os itens da list são descartados e ela torna-se uma list vazia, mantém o sentinela
*/

int OrderedList2::size(){
    return count;
}
/*
pré-condição : nenhuma 
pós-condição: a função retorna o número de itens na list
*/

int OrderedList2::search(ListEntry x){
    ListPointer p = head;
    int i = 1;

    sentinel->entry = x;
    
    while(p->entry < x){
        p = p->nextNode;
        i++;
    }

    if(p != sentinel || p->entry != x){
        return 0;
    }
    else{
        return i;
    }
}
/*
pré-condição: lista criada 
pós-condição: retorna a posição que o elemento x encontra-se na lista - caso exista mais de um x na lista, retorna o primeiro encontrado - caso não encontre, retorna zero
*/
