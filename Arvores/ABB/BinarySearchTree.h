#include <iostream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef int TreeEntry;

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        /*bool empty();
        bool full();
        void clear();
        void preOrder();
        void inOrder();
        void postOrder();
        int nodes(); //número de nós
        int leaves(); //número de folhas
        int height(); //altura
        void print(); //escreve a árvore
        */

        //máximo e mínimo
        TreeEntry minimum();
        TreeEntry maximum();

        //busca
        bool getSearchIte(TreeEntry x); //chamar a busca iterativa
        bool getSearchRec(TreeEntry x); //chamar a busca recursiva

        //inserção
        void insertIte(TreeEntry x); //inserção iterativa
        void getInsertRec(TreeEntry x); //chama a inserção recursiva

        //busca com inserção 
        void searchInsertIte(TreeEntry x); //busca com inserção iterativa
        void getSearchInsertRec(TreeEntry x); //chama a busca com inserção recursiva

        //remoção
        bool removeIte(TreeEntry x); //remoção iterativa
        bool removeRec(TreeEntry x); //chama a remoção recursiva

        
    private:
        struct TreeNode;
        typedef TreeNode *TreePointer;
        struct TreeNode{
            TreeEntry entry;
            int freq;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;
        //int numNodes;

        /*
        void clear(TreePointer &t);   
        void process(TreeEntry x);
        void preOrder(TreePointer &t);
        void inOrder(TreePointer &t);
        void postOrder(TreePointer &t);  
        int nodes(TreePointer &t);  
        int leaves(TreePointer &t);
        int height(TreePointer &t);
        void print(TreePointer &t, int s);
        */ 

        //máximo e mínimo
        TreeEntry minimum(TreePointer &t);
        TreeEntry maximum(TreePointer &t);

        //busca
        bool searchIte(TreeEntry x); //iterativa
        bool searchRec(TreeEntry x, TreePointer &t); //recursiva

        //inserção recursiva
        void insertRec(TreeEntry x, TreePointer &q, TreePointer &p, TreePointer &r);

        //busca com inserção recursiva
        void searchInsertRec(TreeEntry x, TreePointer &t);

        //remoção
        bool removeRec(TreeEntry x, TreePointer &p); //recursiva
        void removeMin(TreePointer &q, TreePointer &r); //método auxiliar (caso C)

};

#endif