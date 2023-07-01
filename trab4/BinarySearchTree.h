#include <iostream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef string TreeEntry;

class BinarySearchTree{
    public:
        BinarySearchTree();

        void searchInsert(TreeEntry x); 
        int altura();
        int folhas();
        void write();
        
    private:
        struct TreeNode;
        typedef TreeNode *TreePointer;
        struct TreeNode{
            TreeEntry entry;
            int freq;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;

        int num_nodes;
        int palavras_distintas;
        int palavras_total;
        int comparacoes;

        struct words{
            string word;
            int frequency;
        };
        words palavras[50000];
        int i;
        
        //busca com inserção recursiva
        void searchInsert(TreeEntry x, TreePointer &t);
        //altura da árvore 
        int altura(TreePointer &t);
        //número de folhas 
        int folhas(TreePointer &t);
        //passar dados da ABB para o vetor palavras[]
        void write(TreePointer &t);
};

#endif