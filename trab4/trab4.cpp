#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "AVLTree.h"
#include "AVLTree.cpp"

using namespace std;

int main(){ 
    BinarySearchTree bst;
    AVLTree avl;
    string word;
    ifstream theInput("C:/Users/lal4mp/Documents/codes/C++/c++usp/aed1/trab4/arquivos/mam.txt");

    //ler cada palavra do arquivo e inserir na ABB e na AVL
    while(theInput >> word){ 
        bst.searchInsert(word);
        avl.searchInsert(word);
    }
    theInput.close();

    bst.write();
    avl.write();
    
    return 0;
}
