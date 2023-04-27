#include <iostream>
#include "Bag.h"
using namespace std;

int main(){ 
    Bag b;

    cout << "Inserindo um 4 na sacola..." << endl;
    b.insert(4); 
    cout << "Há " << b.occurrence(4) << " número(s) 4 na sacola" << endl;
    cout << b.toString() << endl;

    cout << "Inserindo um 8 na sacola..." << endl;
    b.insert(8); 
    cout << "Ha " << b.occurrence(8) << " numero(s) 8 na sacola" << endl;

    cout << "Inserindo um outro 4 na sacola..." << endl;
    b.insert(4); 
    cout << "Ha " << b.occurrence(4) << " numero(s) 4 na sacola" << endl;

    cout << "Sacola está cheia? " << b.full() << endl; 
    
    /*cout << "Removendo um 4 da sacola..." << endl;
    b.remove(4); 
    cout << "Ha " << b.occurrence(4) << " numero(s) 4 na sacola" << endl;

    cout << "Sacola está cheia? " << boolalpha << b.full() << endl;*/

    /*cout << "Ha " << b.occurrence(10) << " numero(s) 10 na sacola" << endl;
    cout << "Removendo um 10 da sacola..." << endl;
    b.remove(10); 
    cout << "Ha " << b.occurrence(10) << " numero(s) 10 na sacola" << endl;*/

    cout << "Sacola está cheia? " << noboolalpha << b.full() << endl; 
    cout << "Estado final da sacola: " << b.toString() << endl;

    return 0;
}