#include <iostream>
using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

typedef string TreeEntry;

class AVLTree{
    public:
        AVLTree();

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
            int bal; //fator balanceamento (-1, 0, +1)
            TreePointer leftNode, rightNode;
        };

        TreePointer root;

        int num_nodes;
        int palavras_distintas;
        int palavras_total;
        int comparacoes;
        int rotacoes;

        struct words{
            string word;
            int frequency;
        };
        words palavras[30000];
        int i;

        //busca com inserção recursiva
        void searchInsert(TreeEntry x, TreePointer &pA, bool &h);
        //altura da árvore 
        int altura(TreePointer &t);
        //número de folhas 
        int folhas(TreePointer &t);
        //passar dados da AVL para o vetor palavras[]
        void write(TreePointer &t);
};

#endif