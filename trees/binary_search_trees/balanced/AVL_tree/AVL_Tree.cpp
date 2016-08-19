//
// Created by linux on 19/1/16.
//

#include <iostream>
#include "AVL_Tree.h"

namespace altrusian {


    BinarySearchTreeNode* AVL_Tree::insert(BinarySearchTreeNode* root,int value){

        if(root == NULL) return createNewNode(value);

        else if(root->value == value) return root;

        else if(root->value > value) root->left = insert(root->left, value);
        else if(root->value < value) root->right = insert(root->right, value);

        return balance(root);

    }


    BinarySearchTreeNode* AVL_Tree::remove(BinarySearchTreeNode* root,int value) {

        if(root == NULL) return NULL;

        else if(root->value == value && root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return NULL;
        }

        else if(root->value == value && root->left !=NULL && root->right == NULL){
            BinarySearchTreeNode *tmp = root->left;
            delete root;
            root = NULL;
            return tmp;
        }

        else if(root->value == value && root->left == NULL && root->right != NULL){
            BinarySearchTreeNode *tmp = root->right;
            delete root;
            root = NULL;
            return tmp;
        }

        else if(root->value == value && root->left != NULL && root->right != NULL){
            BinarySearchTreeNode* min = getMinElement(root->right);
            root->value = min->value;
            root->right = remove(root->right,min->value);
        }

        else if(root->value > value) root->left = remove(root->left,value);
        else if(root->value < value) root->right = remove(root->right,value);

        return balance(root);

    }


    BinarySearchTreeNode* AVL_Tree::leftLeftCase(BinarySearchTreeNode *root) {
        BinarySearchTreeNode *tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        return tmp;
    }

    BinarySearchTreeNode* AVL_Tree::rightRightCase(BinarySearchTreeNode *root) {
        BinarySearchTreeNode *tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        return tmp;
    }

    BinarySearchTreeNode* AVL_Tree::leftRightCase(BinarySearchTreeNode *root) {
        BinarySearchTreeNode *tmp1 = root->left;
        root->left = tmp1->right;
        rightRightCase(tmp1);
        return leftLeftCase(root);
    }

    BinarySearchTreeNode* AVL_Tree::rightLeftCase(BinarySearchTreeNode *root) {
        BinarySearchTreeNode * tmp1 = root->right;
        root->right = tmp1->left;
        leftLeftCase(tmp1);
        return rightRightCase(root);
    }

    BinarySearchTreeNode* AVL_Tree::balance(BinarySearchTreeNode *root) {

        int balanceFactor = getBalanceFactor(root);

        if(balanceFactor > 1) {
            //LL case or LR case
            if(getBalanceFactor(root->left) > 0){
                //LL case
                return leftLeftCase(root);
            }else if(getBalanceFactor(root->left) < 0){
                //LR case
                return leftRightCase(root);
            }
        }
        else if(balanceFactor < -1){
            //RR or RL case
            if(getBalanceFactor(root->right) > 0) {
                //RL case
                return rightLeftCase(root);
            }else if(getBalanceFactor(root->right) < 0){
                //RR case
                return rightRightCase(root);
            }
        }

        return root;

    }

}
