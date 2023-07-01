#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>

#include "BinarySearchTree.h"
#include "AVLTree.h"

using namespace std;

int main(){ 
    BinarySearchTree bst;
    AVLTree avl;
    string word;
    ifstream theInput("C:/Users/lal4mp/Documents/codes/C++/c++usp/aed1/trab4/arquivos/exame.txt");

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

BinarySearchTree::BinarySearchTree(){
    root = NULL;
    num_nodes = palavras_distintas = 0;
    palavras_total = 0;
    comparacoes = 0;
    i = 1;
}
AVLTree::AVLTree(){
    root = NULL;
    num_nodes = palavras_distintas = 0;
    palavras_total = 0;
    comparacoes = 0;
    rotacoes = 0;
    i = 1;
}

//busca com inserção ABB
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

//busca com inserção AVL
void AVLTree::searchInsert(TreeEntry x){ 
    bool h = false;
    searchInsert(x, root, h);
}

void AVLTree::searchInsert(TreeEntry x, TreePointer &pA, bool &h){ 
    TreePointer pB, pC;

    if(pA == NULL){ //inserir
        pA = new TreeNode;
        h = true;
        pA->entry = x;
        pA->freq = 1;
        pA->leftNode = pA->rightNode = NULL;
        pA->bal = 0;

        palavras_distintas++;
        num_nodes++;
        palavras_total++;
    } 
    else{
        comparacoes++;
        if(x < pA->entry){ 
            searchInsert(x, pA->leftNode, h);

            //subárvore esquerda cresceu
            if(h){ 
                switch(pA->bal){ 
                    case -1: 
                        pA->bal = 0; 
                        h = false; 
                        break;
                    case 0: 
                        pA->bal = +1; 
                        break;
                    case +1: 
                        pB = pA->leftNode;
                        if(pB->bal == +1){ //rotação LL
                            rotacoes++;
                            
                            pA->leftNode = pB->rightNode; 
                            pB->rightNode = pA;
                            pA->bal = 0; 
                            pA = pB;
                        }
                        else{ //rotação LR
                            rotacoes++;
                            
                            pC = pB->rightNode; 
                            pB->rightNode = pC->leftNode;
                            pC->leftNode = pB; 
                            pA->leftNode = pC->rightNode;
                            pC->rightNode = pA;

                            if(pC->bal == +1) 
                                pA->bal = -1; 
                            else 
                                pA->bal = 0;

                            if(pC->bal == -1) 
                                pB->bal = +1; 
                            else 
                                pB->bal = 0;

                            pA = pC;
                        }

                        pA->bal = 0; 
                        h = false;
                }
            }
        }
        else{
            comparacoes++;
            if(x > pA->entry){ 
                searchInsert(x, pA->rightNode, h);

                //subárvore direita cresceu
                if(h){ 
                    switch(pA->bal){ 
                        case +1: 
                            pA->bal = 0; 
                            h = false; 
                            break;
                        case 0: 
                            pA->bal = -1; 
                            break;
                        case -1: 
                            pB = pA->rightNode;
                            if(pB->bal == -1){ //rotação RR
                                rotacoes++;
                                
                                pA->rightNode = pB->leftNode;
                                pB->leftNode = pA;
                                pA->bal = 0; 
                                pA = pB;
                            }
                            else{ //rotação RL
                                rotacoes++;

                                pC = pB->leftNode; 
                                pB->leftNode = pC->rightNode;
                                pC->rightNode = pB; 
                                pA->rightNode = pC->leftNode;
                                pC->leftNode = pA;

                                if(pC->bal == -1) 
                                    pA->bal = +1; 
                                else 
                                    pA->bal = 0;

                                if(pC->bal == +1) 
                                    pB->bal = -1; 
                                else 
                                    pB->bal = 0;

                                pA = pC;
                            }
                            pA->bal = 0; 
                            h = false;
                    }
                }
            }
            
            //elemento encontrado
            else{
                pA->freq++;
                palavras_total++;
            }
        }
    }
}

//altura da árvore ABB
int BinarySearchTree::altura(){ 
    return altura(root);
}
int BinarySearchTree::altura(TreePointer &t){
    if(t == NULL)
        return 0;
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

//altura da árvore AVL
int AVLTree::altura(){ 
    return altura(root);
}
int AVLTree::altura(TreePointer &t){
    if(t == NULL)
        return 0;
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


//número de folhas ABB
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

//número de folhas AVL
int AVLTree::folhas(){ 
    return folhas(root);
}
int AVLTree::folhas(TreePointer &t){ 
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
    for(int c = num_nodes; c >= num_nodes-10; c--){
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

//escrever os dados AVL
void AVLTree::write(){
    write(root); //passar as palavras e suas frequências para um vetor
    
    cout << "\n                   AVL" << endl;
    cout << "\nA) palavras distintas = " << palavras_distintas << endl;
    cout << "B) total de palavras = " << palavras_total << endl;
    cout << "C) altura da arvore minima = " << ceil(log2(float(num_nodes) + 1) - 1) << endl;
    cout << "G) altura da AVL = " << altura() << endl;
    cout << "H) numero de folhas da AVL = " << folhas() << endl;
    cout << "I) comparacoes = " << comparacoes << endl;
    cout << "J) rotacoes = " << rotacoes << endl;
    cout << "Media de comparacoes por palavra = " << comparacoes/palavras_total << endl;
    cout << "Media de rotacoes por palavra distinta = " << comparacoes/palavras_distintas << "\n\n" << endl;

    //10 palavras com maiores frequências
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
    for(int c = num_nodes; c >= num_nodes-10; c--){
        cout << setw(10) << palavras[c].word << setw(15) << palavras[c].frequency << endl;
    }
    cout << "\n\n" << endl;
}
void AVLTree::write(TreePointer &t){
    if(t != NULL){
        write(t->rightNode); //subárvore direita
        palavras[i].frequency = t->freq;
        palavras[i].word = t->entry;
        i++;
        write(t->leftNode); //subárvore esquerda
    }
}