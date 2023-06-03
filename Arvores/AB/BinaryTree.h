#include <iostream>
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef int TreeEntry;

class BinaryTree{
    public:
        BinaryTree();
        ~BinaryTree();
        bool empty();
        bool full();
        void clear();
        void preOrder();
        void inOrder();
        void postOrder();
        int nodes(); //número de nós
        int leaves(); //número de folhas
        int height(); //altura
        void print(); //escreve a árvore
        
    private:
        struct TreeNode;
        typedef TreeNode *TreePointer;
        struct TreeNode{
            TreeEntry entry;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;
        //int numNodes;

        void clear(TreePointer &t);   
        void process(TreeEntry x);
        void preOrder(TreePointer &t);
        void inOrder(TreePointer &t);
        void postOrder(TreePointer &t);  
        int nodes(TreePointer &t);  
        int leaves(TreePointer &t);
        int height(TreePointer &t);
        void print(TreePointer &t, int s); 
};

#endif
