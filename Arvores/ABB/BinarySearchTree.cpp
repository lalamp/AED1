#include <iostream>
#include <iomanip>
#include "BinarySearchTree.h"
using namespace std;

#define INT_MIN 1;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
    //numNodes = 0;
}

BinarySearchTree::~BinarySearchTree(){
    
}

//mínimo
TreeEntry BinarySearchTree::minimum(){
    if(root == NULL){
        "Árvore vazia";
        return INT_MIN; // ???
    }
    return minimum(root); 
}    
    //recursivo
TreeEntry BinarySearchTree::minimum(TreePointer &t){
    if(t->leftNode == NULL)
        return t->entry;
    else
        minimum(t->leftNode);
}
    //iterativo
TreeEntry BinarySearchTree::minimum(TreePointer &t){
    while(t->leftNode != NULL){
        t = t->leftNode;
    }
    return t->entry;
}

//máximo
TreeEntry BinarySearchTree::maximum(){
    if(root == NULL){
        "Árvore vazia";
        return INT_MIN; //  ???
    }
    return maximum(root);
}
    //recursivo
TreeEntry BinarySearchTree::maximum(TreePointer &t){
    if(t->rightNode == NULL)
        return t->entry;
    else
        maximum(t->rightNode);
}    
    //iterativo
TreeEntry BinarySearchTree::maximum(TreePointer &t){
    while(t->rightNode != NULL){
        t = t->rightNode;
    }
    return t->entry;
}


//busca
    //iterativa
bool BinarySearchTree::getSearchIte(TreeEntry x){
    searchIte(x);
}
bool BinarySearchTree::searchIte(TreeEntry x){
    TreePointer t;
    t = root;
        
    while(t != NULL && x != t->entry){
        if(x > t->entry)
            t = t->rightNode;
        else
            t = t->leftNode;
    }

    return (t != NULL);       
}
    //recursiva
bool BinarySearchTree::getSearchRec(TreeEntry x){
    searchRec(x, root);
}
bool BinarySearchTree::searchRec(TreeEntry x, TreePointer &t){
    if(t == NULL)
        return false;
    if(x == t->entry) 
        return true;
    else{
        if(x > t->entry)
            return searchRec(x, t->rightNode);
        else
            return searchRec(x, t->leftNode); 
    }       
}

//inserção
    //iterativa
void BinarySearchTree::insertIte(TreeEntry x){
    TreePointer p = NULL, q = root, r;

    //nó que será inserido
    r = new TreeNode;
    if(r == NULL){
        cout << "Sem memória" << endl;
        abort();
    }
    r->entry = x;
    r->leftNode = NULL;
    r->rightNode = NULL;

    //local em que o nó será inserido
    while(q != NULL){
        p = q;
        if(x > q->entry)
            q = q->rightNode;
        else
            q = q->leftNode;
    }

    if(p == NULL) //árvore é vazia
        root = r;
    else
        if(x > p->entry)
            p->rightNode = r;
        else
            p->leftNode = r;
}
    //recursiva (conferir implementação)
void BinarySearchTree::getInsertRec(TreeEntry x){
    TreePointer p = NULL;

    TreePointer r = new TreeNode;
    if(r == NULL){
        cout << "Sem memória" << endl;
        abort();
    }
    r->entry = x;
    r->leftNode = NULL;
    r->rightNode = NULL;

    insertRec(x, root, p, r);
}
void BinarySearchTree::insertRec(TreeEntry x, TreePointer &q, TreePointer &p, TreePointer &r){
    if(q != NULL){
        p = q;
        if(x > q->entry)
            return insertRec(x, q->rightNode, p, r);
        else
            return insertRec(x, q->leftNode, p, r);
    }

    if(p == NULL)
        root = r;
    else
        if(x > p->entry)
            p->rightNode = r;
        else
            p->leftNode = r;
}

//buscas com inserção 
    //iterativa (conferir implementação)
void BinarySearchTree::searchInsertIte(TreeEntry x){ 
    TreePointer t = root;
    while(t != NULL){
        if(x == t->entry){
            t->freq++;
            break;
        }
        else
            if(x < t->entry) //procurar x na subárvore esquerda
                t = t->leftNode;
            else //procurar x na subárvore direita
                t = t->rightNode;
    }

    if(t == NULL){ //x não encontrado, então é inserido
        t = new TreeNode;
        t->entry = x;
        t->freq = 1;
        t->leftNode = t->rightNode = NULL;
    }
}
    //recursiva
void BinarySearchTree::getSearchInsertRec(TreeEntry x){ 
    searchInsertRec(x, root);
}
void BinarySearchTree::searchInsertRec(TreeEntry x, TreePointer &t){ 
    if(t == NULL){ //x não encontrado, então é inserido
        t = new TreeNode;
        t->entry = x;
        t->freq = 1;
        t->leftNode = t->rightNode = NULL;
    }
    else
        if(x == t->entry)
            t->freq++;
        else
            if(x < t->entry) //procurar x na subárvore esquerda
                searchInsertRec(x, t->leftNode);
            else //procurar x na subárvore direita
                searchInsertRec( x, t->rightNode );      
}

//remoção
    //iterativa (conferir implementação)
bool BinarySearchTree::removeIte(TreeEntry x){
    TreePointer p = root;

    while(p != NULL && p->entry != x){
        if(x < p->entry)
            p = p->leftNode;
        else if(x > p->entry)
            p = p->rightNode;
    }

    if(p == NULL) //elemento não está na árvore
        return false;
    
    if(p->entry == x){
        TreePointer q, r;
        q = p;

        if(q->leftNode == NULL)
            p = q->rightNode; //caso A
        else if(q->rightNode == NULL)
            p = q->leftNode; //caso B
        else{ //nenhuma das subárvores do nó de valor x é nula
            r = q->rightNode;
            while(r->leftNode != NULL){
                r = r->leftNode;
            }
            p->entry = r->entry;
            //p->freq = r->freq; //somente necessário se busca com inserção
            q = r;
            r = r->rightNode;
        }

        delete q;
        return true;
    }

}
    //recursiva
bool BinarySearchTree::removeRec(TreeEntry x){
    removeRec(x, root);
}
bool BinarySearchTree::removeRec(TreeEntry x, TreePointer &p){
    if(p == NULL) //elemento não está na árvore
        return false;

    if(x < p->entry)
        return removeRec(x, p->leftNode);
    else if(x > p->entry)
        return removeRec(x, p->rightNode);

    if(x == p->entry){
        TreePointer q;
        q = p;

        if(q->leftNode == NULL)
            p = q->rightNode; //caso A
        else if(q->rightNode == NULL)
            p = q->leftNode; //caso B
        else 
            removeMin(q, q->rightNode);

        delete q;
        return true;
    }
}
void BinarySearchTree::removeMin(TreePointer &q, TreePointer &r){
    if(r->leftNode != NULL)
        removeMin(q, r->leftNode);
    else
        q->entry = r->entry;
        //q->freq = r->freq; //somente necessário se busca com inserção
        q = r; 
        r = r->rightNode;
}
