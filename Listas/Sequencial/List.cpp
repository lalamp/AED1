#include <iostream>
#include "List.h"
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
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a list está vazia; false caso contrário
*/

bool OrderedList::full(){
    return (count == MaxList);
}
/*
pré-condição: nenhuma 
pós-condição: função retorna true se a list está cheia; false caso contrário
*/

void OrderedList::insert(int p, ListEntry x){
    if(full()){
        cout << "Lista cheia" << endl;
        abort();
    }
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    for(int i = count; i >= p; i--){
        entry[i+1] = entry[i];
    }
    /*for(int i = p+1; i <= count+1; i++){  
        entry[i] = entry[i-1];
    }*/
    entry[p] = x;
    count++;
}
/*
pré-condição: list não está cheia e 1 <= p <= n+1, onde n é o número de elementos na list
pós-condição: o item x é armazenado na posição p da list e todas as entradas seguintes (desde que p <= n) têm suas posições incrementadas em uma unidade
*/

void OrderedList::remove(int p, ListEntry &x){
    if(empty()){
        cout << "Lista vazia" << endl;
        abort();
    }
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    x = entry[p];

    for(int i = p; i < count; i++){   
        entry[i] = entry[i+1];
    }

    count--;
}
/*
pré-condição: list não está cheia e 1 <= p <= n+1, onde n é o número de elementos na list
pós-condição: o item da posição p é removido da list e retornado na variável x, todas as entradas seguintes (desde que p <= n) têm suas posições decrementadas em uma unidade
*/

void OrderedList::retrieve(int p, ListEntry &x){
    if(empty()){
        cout << "Lista vazia" << endl;
        abort();
    }
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    x = entry[p];
}
/*
pré-condição: list não está vazia e 1 <= p <= n, onde n é o número de entradas na list
pós-condição: a entrada da posição p da list é retornada na variável x; a list permanece inalterada
*/

void OrderedList::replace(int p, ListEntry x){
     if(empty()){
        cout << "Lista vazia" << endl;
        abort();
    }
    if(p < 1 || p > count+1){
        cout << "Posição inválida" << endl;
        abort();
    }

    entry[p] = x;
}
/*
pré-condição: list não está vazia e 1 <= p <= n, onde n é o número de entradas na lista 
pós-condição: a entrada da posição p da list é substituída por x; as demais entradas da lista mantêm-se inalteradas
*/

void OrderedList::clear(){
    count = 0;
}
/*
pré-condição : nenhuma 
pós-condição: todos os itens da list são descartados e ela torna-se uma list vazia
*/

int OrderedList::size(){
    return count;
}
/*
pré-condição : nenhuma 
pós-condição: a função retorna o número de itens na list
*/

int OrderedList::search(ListEntry x){
    int p = 1;
    while(p <= count && entry[p] != x){
        p++;
    }
    return (p > count ? 0 : p);
}
/*
pré-condição: lista criada 
pós-condição: retorna a posição que o elemento x encontra-se na lista - caso exista mais de um x na lista, retorna o primeiro encontrado - caso não encontre, retorna zero
*/