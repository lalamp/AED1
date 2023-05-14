#include <iostream>
#include <sstream> 
#include "Stack.h"
using namespace std;

Stack::Stack(){
    top = 0;
}
/*
construtor
pré-condição: nenhuma 
pós-condição: pilha é criada e iniciada como vazia
*/

Stack::~Stack(){
    cout << "Pilha finalizada" << endl;
}
/*
pré-condição: nenhuma 
pós-condição: pilha é finalizada, deixando de ocupar espaço na memória
*/

bool Stack::empty(){
    return (top == 0);
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a pilha está vazia, false caso contrário
*/
bool Stack::full(){
    return (top == MAX);
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a pilha está cheia, false caso contrário
*/


void Stack::push(StackEntry x){
    if(full()){
        cout << "Pilha cheia" << endl;
        abort();
    }

    top++;
    dados[top] = x;
}
/*
pré-condição: pilha não está cheia 
pós-condição: o item x é armazenado no topo da pilha
*/

void Stack::pop(StackEntry &x){
    if(empty()){
        cout << "Pilha vazia" << endl;
        abort();
    }

    x = dados[top];
    top--;
}
/*
pré-condição: pilha não está vazia 
pós-condição: o item no topo da pilha é removido e seu valor é retornado na variável x
*/

void Stack::clear(){
    int x;
    while(! empty()){
        pop(x);
    }
}
/*
void Stack::clear(){
    top = 0;
}
*/
/*
pré-condição : nenhuma 
pós-condição: todos os itens da pilha são descartados e ela torna-se uma pilha vazia
*/

int Stack::size(){
    return top;
}
/*
pré-condição : nenhuma 
pós-condição: a função retorna o número de itens na pilha
*/

void Stack::getTop(StackEntry &x){
    if(top == 0){ 
        cout << "Pilha vazia";
        abort();
    }
    x = dados[top];
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
/*
pré-condição: pilha não está vazia 
pós-condição: a variável x recebe uma cópia do item no topo da pilha e a pilha permanece inalterada
*/

string Stack::toString(){ 
    int i;
    stringstream ss;

    ss << "[";
    for(i = 1; i <= top; i++){ 
        ss << dados[i];
        
        if(i != top)
            ss << ",";
    }

    ss << "]";
    return ss.str();
}
/*
pré-condição: nenhuma
pós-condição: retorna pilha no formato de string. Por exemplo, pilha contendo elementos 8, 10 e 8 -> retorna [8,10,8]
*/

StackEntry Stack::get(int i){
    if (i < 1 || i > top){ 
        cout << "Índice inválido" << endl;
        abort();
    }
    return dados[i];
}
/*
pré-condição: 1 <= i <= top
pós-condição: retorna o valor do i-ésimo elemento da pilha
*/

void Stack::change(int i, StackEntry x){
    if (i < 1 || i > top){ 
        cout << "Índice inválido" << endl;
        abort();
    }
    dados[i] = x;
}
/*
pré-condição: 1 <= i <= top
pós-condição: o i-ésimo elemento da pilha recebe o valor x
*/
