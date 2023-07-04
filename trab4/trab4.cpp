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

    //menu com as opções de escolha de qual texto será analisado
    int i;
    cout << "\n\n           MENU" << endl;
    cout << "[1] mam \n[2] exame \n[3] biblia" << endl;
    cout << "Qual texto voce deseja analisar? ";
    cin >> i;

    string file;
    if(i == 1){
        file = "C:/Users/lal4mp/Documents/codes/C++/c++usp/aed1/trab4/arquivos/mam-na-np-lo.txt";
    }
    else if(i == 2){
        file = "C:/Users/lal4mp/Documents/codes/C++/c++usp/aed1/trab4/arquivos/exame_10000-na-np-lo.txt";
    }
    else if(i == 3){
        file = "C:/Users/lal4mp/Documents/codes/C++/c++usp/aed1/trab4/arquivos/biblia-na-np-lo.txt";
    }
    else{
        cout << "\nValor invalido\n" << endl;
        return -1;
    }
    
    ifstream theInput(file);
    string word;
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
