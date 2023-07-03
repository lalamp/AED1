#include <iostream>
#include <iomanip>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree(){
    root = NULL;
    //numNodes = 0;
}

BinaryTree::~BinaryTree(){
    clear();
}

bool BinaryTree::empty(){
    return (root == NULL);
}
bool BinaryTree::full(){
    return false;
}

void BinaryTree::clear(){
    clear(root);
    root = NULL;
    //numNodes = 0;
}
void BinaryTree::clear(TreePointer &t){
    if(t != NULL){
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
    }
}

//número de nós
int BinaryTree::nodes(){
    return nodes(root);
}
int BinaryTree::nodes(TreePointer &t){
    if(t == NULL)
        return 0;
    else
        return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}
/* caso em que há o contador 'numNodes'
int BinaryTree::nodes(){
    return numNodes;
}
*/

//número de folhas
int BinaryTree::leaves(){
    return leaves(root);
}
int BinaryTree::leaves(TreePointer &t){
    if(t == NULL)
        return 0;
    else
        if(t->leftNode == NULL && t->rightNode == NULL)
            return 1;
        else
            return leaves(t->leftNode) + leaves(t->rightNode);
}

//altura da árvore
int BinaryTree::height(){
    return height(root);
}
int BinaryTree::height(TreePointer &t){
    if(t == NULL)
        return -1;
    else{
        int L, R;
        L = height(t->leftNode);
        R = height(t->rightNode);
        if(L > R)
            return L+1;
        else
            return R+1;
    }
}

//pré-ordem (esquerda primeiro)
void BinaryTree::preOrder(){
    preOrder(root);
}
void BinaryTree::preOrder(TreePointer &t){
    if(t != NULL){
        process(t->entry); //cout << t->entry << " ";
        preOrder(t->leftNode);
        preOrder(t->rightNode);
    }
}

//em-ordem (fundo primeiro)
void BinaryTree::inOrder(){
    inOrder(root);
}
void BinaryTree::inOrder(TreePointer &t){
    if(t != NULL){
        inOrder(t->leftNode);
        process(t->entry); //cout << t->entry << " ";
        inOrder(t->rightNode);
    }
}

//pós-ordem (direita primeiro)
void BinaryTree::postOrder(){
    postOrder(root);
}
void BinaryTree::postOrder(TreePointer &t){
    if(t != NULL){
        postOrder(t->leftNode);
        postOrder(t->rightNode);
        process(t->entry); //cout << t->entry << " ";
    }
}

//escrever a árvore
void BinaryTree::print(){
    print(root, 0);
}
void BinaryTree::print(TreePointer &t, int s){
    int i;
    if(t != NULL){
        print(t->rightNode, s+3); //escreve a subárvore direita
        for(i = 1; i<=s; i++)
            cout << " ";
        cout << setw(6) << t->entry << endl; //escreve a raiz
        print(t->leftNode, s+3); //escreve a subárvore esquerda
    }
}



