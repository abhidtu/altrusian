//
// Created by linux on 19/1/16.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stddef.h>
#include "../Trees.h"
#include "BinarySearchTreeNode.h"

namespace LibAlDs {

    class BinarySearchTree : public Trees {

    protected:
        BinarySearchTreeNode *root = NULL;
        virtual BinarySearchTreeNode* find(BinarySearchTreeNode* root,int value);
        virtual BinarySearchTreeNode* remove(BinarySearchTreeNode* root,int value);
        virtual BinarySearchTreeNode* insert(BinarySearchTreeNode* root,int value);
        virtual BinarySearchTreeNode* createNewNode(int value);
        virtual BinarySearchTreeNode* getMaxElement(BinarySearchTreeNode* root);
        virtual BinarySearchTreeNode* getMinElement(BinarySearchTreeNode* root);
        virtual int height(BinarySearchTreeNode* root);
        virtual bool isBalanced(BinarySearchTreeNode* root);
        virtual int getBalanceFactor(BinarySearchTreeNode* root);
        virtual bool isLeafNode(BinarySearchTreeNode* root);
        virtual bool isLeftOriented(BinarySearchTreeNode* root);
        virtual bool isRightOriented(BinarySearchTreeNode* root);
        virtual bool isInternalNode(BinarySearchTreeNode* root);

    public:
        void insert(int value);
        BinarySearchTreeNode* find(int value);
        void remove(int value);
        int size();
        bool isEmpty();

    };

}


#endif //BINARYSEARCHTREE_H
