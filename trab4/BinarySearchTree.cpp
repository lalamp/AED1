#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>

#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
    num_nodes = palavras_distintas = 0;
    palavras_total = 0;
    comparacoes = 0;
    i = 1;
}

//busca com inserção 
void BinarySearchTree::searchInsert(TreeEntry x){ 
    searchInsert(x, root);
}
void BinarySearchTree::searchInsert(TreeEntry x, TreePointer &t){ 
    if(t == NULL){ //x não encontrado, então é inserido
        t = new TreeNode;
        t->entry = x;
        t->freq = 1;
        t->leftNode = t->rightNode = NULL;

        palavras_distintas++;
        num_nodes++;
        palavras_total++;
    }
    else{
        comparacoes++;
        if(x == t->entry){
            t->freq++;
            palavras_total++;
        }
        else{
            comparacoes++;
            if(x < t->entry){ //procurar x na subárvore esquerda
                searchInsert(x, t->leftNode);
            }
            else{ //procurar x na subárvore direita
                searchInsert(x, t->rightNode);
            }
        }
    }
}

//altura da árvore
int BinarySearchTree::altura(){ 
    return altura(root);
}
int BinarySearchTree::altura(TreePointer &t){
    if(t == NULL)
        return -1;
    else{ 
        int L,R;
        L = altura(t->leftNode);
        R = altura(t->rightNode);
        
        if(L > R) 
            return L+1; 
        else 
            return R+1;
    }
}

//número de folhas
int BinarySearchTree::folhas(){ 
    return folhas(root);
}
int BinarySearchTree::folhas(TreePointer &t){ 
    if(t == NULL)
        return 0;
    else
        if(t->leftNode == NULL && t->rightNode == NULL)
            return 1;
        else
            return folhas(t->leftNode) + folhas(t->rightNode);
}

//escrever os dados ABB
void BinarySearchTree::write(){
    write(root); //passar as palavras e suas frequências para um vetor
    
    cout << setprecision(2) << fixed;
    cout << "\n                   ABB" << endl;
    cout << "\nA) palavras distintas = " << palavras_distintas << endl;
    cout << "B) total de palavras = " << palavras_total << endl;
    cout << "C) altura da arvore minima = " << ceil(log2(float(num_nodes) + 1) - 1) << endl;
    cout << "D) altura da ABB = " << altura() << endl;
    cout << "E) numero de folhas da ABB = " << folhas() << endl;
    cout << "F) comparacoes = " << comparacoes << endl;
    cout << "Media de comparacoes por palavra = " << float(comparacoes)/float(palavras_total) << "\n" << endl;

    //10 palavras com maiores freqûencias
    //método de ordenação seleção (comparando pela frequência e, para frequência iguais, colocando em ordem alfabética)
    int i_menor;
    int aux_frequency;
    string aux_word;

    for(int i = 1; i < num_nodes+1; i++){
        i_menor = i;
        for(int j = i+1; j <= num_nodes; j++){ 
            if(palavras[j].frequency < palavras[i_menor].frequency){
                i_menor = j; 
            }
            else if(palavras[j].frequency == palavras[i_menor].frequency){
                if(palavras[j].word > palavras[i_menor].word){
                    i_menor = j;
                }
            }
        }
        aux_word = palavras[i].word;
        aux_frequency = palavras[i].frequency;
        palavras[i].word = palavras[i_menor].word;
        palavras[i].frequency = palavras[i_menor].frequency;
        palavras[i_menor].word = aux_word;
        palavras[i_menor].frequency = aux_frequency;
    }

    //imprime as 10 palavras de maiores freqûencias
    cout << "  PALAVRAS" << setw(15) << "FREQUENCIA" << endl;
    for(int c = num_nodes; c > num_nodes-10; c--){
        cout << setw(10) << palavras[c].word << setw(15) << palavras[c].frequency << endl;
    }
    cout << "\n\n" << endl;
}
void BinarySearchTree::write(TreePointer &t){
    if(t != NULL){
        write(t->rightNode); //subárvore direita
        palavras[i].frequency = t->freq;
        palavras[i].word = t->entry;
        i++;
        write(t->leftNode); //subárvore esquerda
    }
}