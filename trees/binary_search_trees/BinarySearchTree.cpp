//
// Created by linux on 19/1/16.
//

#include <iostream>
#include <algorithm>
#include "BinarySearchTree.h"

namespace altrusian {


    void BinarySearchTree::insert(int value) {
        root = insert(root,value);
        NumNodes++;
    }

    /**
     * Tn = O(N)
     */
    BinarySearchTreeNode* BinarySearchTree::find(int value) {
        return find(root,value);
    }

    /**
     * Tn = O(N)
     */
    void BinarySearchTree::remove(int value) {
        root = remove(root,value);
        NumNodes--;
    }

    /**
    * Tn = O(N)
    */
    BinarySearchTreeNode* BinarySearchTree::insert(BinarySearchTreeNode* root, int value) {

        if(root == NULL) return createNewNode(value);

        else if(root->value == value) return root;

        else if(root->value > value) root->left = insert(root->left,value);
        else if(root->value < value) root->right = insert(root->right,value);

        return root;

    }

    /**
     * Tn = O(1)
     */
    int BinarySearchTree::size() {
        return NumNodes;
    }

    bool BinarySearchTree::isEmpty() {
        return root == NULL;
    }


    //private methods

    /**
     * T(n) = O(n) if simple bst otherwise log(n)
     */
    BinarySearchTreeNode* BinarySearchTree::find(BinarySearchTreeNode* root,int value) {

        if(root == NULL || root->value == value) return root;

        else if(root->value > value) return find(root->left,value);
        else if(root->value < value) return find(root->right,value);

        return root;
    }


    /**
     * T(n) = O(n) if simple bst otherwise log(n)
     */
    BinarySearchTreeNode* BinarySearchTree::remove(BinarySearchTreeNode* root,int value){

        if(root == NULL) return NULL;

        else if(root->value == value && isLeafNode(root)){
            delete root;
            root = NULL;
            return NULL;
        }

        else if(root->value == value && isLeftOriented(root)){
            BinarySearchTreeNode *tmp = root->left;
            delete root;
            root = NULL;
            return tmp;
        }

        else if(root->value == value && isRightOriented(root)){
            BinarySearchTreeNode *tmp = root->right;
            delete root;
            root = NULL;
            return tmp;
        }

        else if(root->value == value && isInternalNode(root)){
            BinarySearchTreeNode* min = getMinElement(root->right);
            root->value = min->value;
            root->right = remove(root->right,min->value);
        }

        else if(root->value > value) root->left = remove(root->left,value);
        else if(root->value < value) root->right = remove(root->right,value);

        return root;

    }

    /**
     * T(n) = O(n) if simple bst otherwise log(n)
     * */
    BinarySearchTreeNode* BinarySearchTree::getMaxElement(BinarySearchTreeNode* root){

        BinarySearchTreeNode *tmp = root;

        if(tmp == NULL) return NULL;

        while (tmp->right != NULL) tmp = tmp->right;

        return tmp;

    }

    //T(n) = O(n) if simple bst otherwise log(n)
    BinarySearchTreeNode* BinarySearchTree::getMinElement(BinarySearchTreeNode* root){

        BinarySearchTreeNode *tmp = root;

        if(tmp == NULL) return NULL;

        while (tmp->left != NULL) tmp = tmp->left;

        return tmp;

    }

    /**
     * Tn = O(1)
     */
    BinarySearchTreeNode* BinarySearchTree::createNewNode(int value) {
        BinarySearchTreeNode *node = new BinarySearchTreeNode();
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    //T(n) = O(n) if simple bst otherwise log(n)
    int BinarySearchTree::height(BinarySearchTreeNode* root) {
        return root == NULL ? 0 : std::max(height(root->left),height(root->right))+1;
    }

    //T(n) = O(n) if simple bst otherwise log(n)
    bool BinarySearchTree::isBalanced(BinarySearchTreeNode* root) {
        return root == NULL ? false : std::abs(height(root->left)-height(root->right)) < 2;
    }

    //T(n) = O(n) if simple bst otherwise log(n)
    int BinarySearchTree::getBalanceFactor(BinarySearchTreeNode *root) {
        return root == NULL ? 0 : (height(root->left)-height(root->right));
    }

    bool BinarySearchTree::isLeafNode(BinarySearchTreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }

    bool BinarySearchTree::isLeftOriented(BinarySearchTreeNode *root) {
        return (root->left !=NULL && root->right == NULL);
    }

    bool BinarySearchTree::isRightOriented(BinarySearchTreeNode *root) {
        return (root->left == NULL && root->right != NULL);
    }

    bool BinarySearchTree::isInternalNode(BinarySearchTreeNode *root) {
        return (root->left != NULL && root->right != NULL);
    }
}