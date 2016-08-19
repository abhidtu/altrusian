//
// Created by linux on 19/1/16.
//

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "../../BinarySearchTreeNode.h"
#include "../../BinarySearchTree.h"

namespace altrusian {

    class AVL_Tree : public BinarySearchTree {

        protected:
        BinarySearchTreeNode* insert(BinarySearchTreeNode* root,int value);
        BinarySearchTreeNode* remove(BinarySearchTreeNode* root,int value);
        BinarySearchTreeNode* leftLeftCase(BinarySearchTreeNode* root);
        BinarySearchTreeNode* rightRightCase(BinarySearchTreeNode* root);
        BinarySearchTreeNode* leftRightCase(BinarySearchTreeNode* root);
        BinarySearchTreeNode* rightLeftCase(BinarySearchTreeNode* root);
        BinarySearchTreeNode* balance(BinarySearchTreeNode* root);

    };

}

#endif //AVL_TREE_H
