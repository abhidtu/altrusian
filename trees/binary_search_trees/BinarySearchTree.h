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


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stddef.h>
#include "../Trees.h"
#include "BinarySearchTreeNode.h"

namespace altrusian {

    class BinarySearchTree : public Trees {

    protected:
        BinarySearchTreeNode *root = NULL;
        virtual BinarySearchTreeNode* find(BinarySearchTreeNode* root,int value);
        virtual BinarySearchTreeNode* remove(BinarySearchTreeNode* root,int value);
        virtual BinarySearchTreeNode* insert(BinarySearchTreeNode* root,int value);
        virtual BinarySearchTreeNode* lca(BinarySearchTreeNode* root, int node1, int node2);
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
        int lca(int node1, int node2);
        int size();
        bool isEmpty();

    };

}


#endif //BINARYSEARCHTREE_H
