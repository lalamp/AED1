#include <iostream>
using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

typedef int TreeEntry;

class AVLTree{
    public:
        AVLTree();
        ~AVLTree();
        void searchInsert(TreeEntry x);
        bool remove(TreeEntry x);

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

        void searchInsert(int x, TreePointer &pA, bool &h);
        bool remove(int x, TreePointer &p, bool &h);
        void removeMin(TreePointer &q, TreePointer &r, bool &h);
        void balanceL(TreePointer &pA, bool &h);
        void balanceR(TreePointer &pA, bool &h);
};

#endif