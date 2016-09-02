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


#ifndef TREES_H
#define TREES_H

#include "binary_search_trees/BinarySearchTreeNode.h"

namespace altrusian {

    class Trees {

    protected:
        int NumNodes = 0;

    public:
        virtual void insert(int value) = 0;
        virtual BinarySearchTreeNode* find(int value) = 0;
        virtual void remove(int value) = 0;
        virtual int lca(int node1, int node2) = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;

    };

}
#endif //TREES_H
