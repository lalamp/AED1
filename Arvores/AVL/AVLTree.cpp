#include <iostream>
#include "AVLTree.h"
using namespace std;

//busca com inserção
void AVLTree::searchInsert(TreeEntry x){ 
    bool h = false;
    searchInsert(x, root, h);
}

void AVLTree::searchInsert(int x, TreePointer &pA, bool &h){ 
    TreePointer pB, pC;

    if(pA == NULL){ //inserir
        pA = new TreeNode;
        h = true;
        pA->entry = x;
        pA->freq = 1;
        pA->leftNode = pA->rightNode = NULL;
        pA->bal = 0;
    } 
    else
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
                            pA->leftNode = pB->rightNode; 
                            pB->rightNode = pA;
                            pA->bal = 0; 
                            pA = pB;
                        }
                        else{ //rotação LR
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
        else
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
                                pA->rightNode = pB->leftNode;
                                pB->leftNode = pA;
                                pA->bal = 0; 
                                pA = pB;
                            }
                            else{ //rotação RL
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
            else 
                pA->freq++;
}

//remoção
bool AVLTree::remove(TreeEntry x){ 
    bool h=false;
    return remove(x, root, h);
}

bool AVLTree::remove(int x, TreePointer &p, bool &h){ 
    TreePointer q;
    bool removeu;

    if(p == NULL) //x não encontrado
        return false;
    
    if(x < p->entry){ 
        removeu = remove(x,p->leftNode,h);
        if(h)
            balanceL(p, h);
        return removeu;
    }

    else
        if(x > p->entry){ 
            removeu = remove(x,p->rightNode,h);
            if(h)
                balanceR(p, h);
            return removeu;
        }
        else{ //remover p->
            q = p;

            if(q->rightNode == NULL){
                p = q->leftNode;
                h = true;
            }
            else
                if(q->leftNode == NULL){
                    p = q->rightNode;
                    h = true;
                }
                else{ 
                    removeMin(q, q->rightNode, h);
                    if(h)
                        balanceR(p,h);
                }
            delete q;
            return true; //x removido
        }
}

void AVLTree::removeMin(TreePointer &q, TreePointer &r, bool &h){
    if(r->leftNode != NULL){ 
        removeMin(q, r->leftNode, h);
        if(h)
            balanceL(r,h);
    }
    else{ 
        q->entry = r->entry;
        q->freq = r->freq;
        q = r;
        r = r->rightNode;
        h = true;
    }
}

void AVLTree::balanceL(TreePointer &pA, bool &h){ 
    TreePointer pB, pC;
    int balB, balC;

    //subárvore esquerda encolheu
    switch(pA->bal){ 
        case +1: 
            pA->bal = 0; 
            break;

        case 0: 
            pA->bal = -1; 
            h = false; 
            break;

        case -1:
            pB = pA->rightNode; 
            balB = pB->bal;
            
            if(balB <= 0){  //rotação RR
                pA->rightNode = pB->leftNode;
                pB->leftNode = pA;
                
                if(balB == 0){ 
                    pA->bal = -1; 
                    pB->bal = +1; 
                    h = false; 
                }
                else{ 
                    pA->bal = 0; 
                    pB->bal = 0; 
                }

                pA = pB;
            }
            else{  //rotação RL
                pC = pB->leftNode; 
                balC = pC->bal;
                pB->leftNode = pC->rightNode;
                pC->rightNode = pB;
                pA->rightNode = pC->leftNode;
                pC->leftNode = pA;

                if(balC==-1) 
                    pA->bal=+1; 
                else 
                    pA->bal=0;

                if(balC==+1) 
                    pB->bal=-1; 
                else    
                    pB->bal=0;

                pA = pC; 
                pC->bal = 0;
            }
    }
}

void AVLTree::balanceR(TreePointer &pA, bool &h){ 
    TreePointer pB, pC;
    int balB, balC;

    //subárvore direita encolheu
    switch(pA->bal){ 
        case -1: 
            pA->bal = 0; 
            break;
        case 0: 
            pA->bal = +1; 
            h = false; 
            break;
        case +1:
            pB = pA->leftNode; 
            balB = pB->bal;
            if(balB >= 0){  //rotação LL
                pA->leftNode = pB->rightNode;
                pB->rightNode = pA;

                if(balB == 0){ 
                    pA->bal = +1; 
                    pB->bal = -1; 
                    h = false; 
                }
                else{ 
                    pA->bal = 0; 
                    pB->bal = 0; 
                }

                pA = pB;
            }
            else{  //rotação LR
                pC = pB->rightNode; 
                balC = pC->bal;
                pB->rightNode = pC->leftNode;
                pC->leftNode = pB;
                pA->leftNode = pC->rightNode;
                pC->rightNode = pA;

                if(balC==+1) 
                    pA->bal=-1; 
                else 
                    pA->bal=0;

                if(balC==-1) 
                    pB->bal=+1; 
                else 
                    pB->bal=0;

                pA = pC; 
                pC->bal = 0;
            }
    }
}