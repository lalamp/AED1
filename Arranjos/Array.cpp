#include <iostream>
#include <sstream> 
#include "Array.h"
using namespace std;

Array::Array(ArrayEntry l1, ArrayEntry u1){
    ArrayEntry array[u1-l1+1];
}
Array::~Array(){
    cout << "Arranjo finalizado";
}

void Array::store(int index, ArrayEntry value){
    array[index] = value;
}
void Array::retrieve(int index, ArrayEntry &value){
    value = array[index];
}

int Array::size(){
    //return u1-l1+1;
}