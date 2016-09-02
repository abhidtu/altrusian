/**
 * Copyright (c) 2016 Abhishek Chawla <abhidtu@gmail.com>
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


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


    int BinarySearchTree::lca(int node1, int node2) {

        BinarySearchTreeNode* lcaNode = lca(root, node1, node2);

        if(lcaNode != NULL) {
            return lcaNode->value;
        } else {
            return -1;
        }

    }

    BinarySearchTreeNode* BinarySearchTree::lca(BinarySearchTreeNode* root, int node1, int node2) {

        if(root == NULL) {
            return root;
        }

        if(find(root->left,node1) && find(root->left,node2)) {
            return lca(root->left,node1,node2);
        }else if(find(root->right,node1) && find(root->right,node2)){
            return lca(root->right,node1,node2);
        }

        return root;

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