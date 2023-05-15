#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue(){
    count = 0;
    head = 1;
    tail = MaxQueue;
}
/*
contrutor
pré-condição: nenhuma 
pós-condição: fila é criada e iniciada como vazia
*/

Queue::~Queue(){
    cout << "Fila distruída" << endl;
}
/*
pré-condição: nenhuma 
pós-condição: fila é finalizada, deixando de ocupar espaço na memória
*/

bool Queue::empty(){
    return (count == 0);
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a fila está vazia; false caso contrário
*/
bool Queue::full(){
    return (count == MaxQueue);
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a fila está cheia; false caso contrário
*/

void Queue::append(QueueEntry x){ 
    if(full()){ 
        cout << "Fila cheia";
        abort();
    }

    count++;
    tail = (tail % MaxQueue)+1;
    entry[tail] = x;
}
/*
pré-condição: fila não está cheia 
pós-condição: o item x é armazenado no final da fila
*/

void Queue::serve(QueueEntry &x){ 
    if(empty()){ 
        cout << "Fila vazia";
        abort();
    }

    count--;
    x = entry[head];
    head = (head % MaxQueue)+1;
}
/*
pré-condição: fila não está vazia 
pós-condição: o item no início da fila é removido e seu valor é retornado na variável x
*/

void Queue::clear(){
    int x;
    while(!empty()){
        serve(x);
    }
}
/*
void Queue::clear(){
    count = 0;
    head = 1;
    tail = MaxQueue;
}
*/
/*
pré-condição : nenhuma 
pós-condição: todos os itens da fila são descartados e ela torna-se uma fila vazia
*/

int Queue::size(){
    return count;
}
/*
pré-condição : nenhuma 
pós-condição: a função retorna o número de itens na fila
*/

void Queue::getFront(QueueEntry &x){
    if(empty()){
        cout << "Fila vazia" << endl;
        abort();
    }
    x = entry[head];
}
/*
pré-condição: fila não está vazia 
pós-condição: a variável x recebe uma cópia do item que se encontra no início da fila e a fila permanece inalterada
*/

void Queue::getRear(QueueEntry &x){
    if(empty()){
        cout << "Fila vazia" << endl;
        abort();
    }
    x = entry[tail];
}
/*
pré-condição: fila não está vazia 
pós-condição: a variável x recebe uma cópia do item que se encontra no final da fila e a fila permanece inalterada
*/