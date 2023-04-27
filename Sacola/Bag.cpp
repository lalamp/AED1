#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream> 
#include "Bag.h"
using namespace std;

Bag::Bag(){ 
    used = 0;
}
// pré-condição: nenhuma
// pós-condição: a sacola é criada vazia (sem elementos)

void Bag::insert(int newEntry){ 
    if(full()){ 
        cout << "Sacola cheia" << endl;
        abort();
    }
    used++;
    data[used] = newEntry;
}
// pré-condição: bag não está cheia
// pós-condição: uma nova cópia de NewEntry é adicionada na bag 

int Bag::occurrence(int entry){ 
    int i, total=0;
    for(i = 1; i <= used; i++){
        if(data[i] == entry)
            total++;
    }
    return total;  
}
// pré-condição: nenhuma
// pós-condição: retorna o número de ocorrências do elemento entry na Bag

/*void Bag::remove(int entry){ 
    ... implementar ...
}*/
// pré-condição: nenhuma
// pós-condição: remove uma ocorrência do elemento entry na bag - se o elemento não existir, a bag permanece inalterada.

bool Bag::full(){ 
    return (used == CAPACITY);
}
// pré-condição: nenhuma
// pós-condição: retorna true se a sacola está cheia, false caso contrário

int Bag::size(){
    return used;
}
// pré-condição: nenhuma
// pós-condição: retorna o número de elementos na sacola

string Bag::toString(){ 
    int i;
    stringstream ss;

    ss << "[";
    for(i = 1; i <= used; i++){  
        ss << data[i];
        if(i != used)
            ss << ",";
    }
    ss << "]";
    return ss.str();
}
// pré-condição: nenhuma
// pós-condição: retorna bag no formato de string. Por exemplo, bag contendo elementos 8, 10 e 8 -> retorna [8,10,8]