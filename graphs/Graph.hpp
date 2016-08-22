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

#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include "Visitors.h"

namespace altrusian {

        template <class T>
        class Graph {

        protected:
            int numVertices;

        public:
            virtual bool isEmpty();
            virtual int size();
            virtual void addVertex(T context) = 0;
            virtual void setContext(int vertex, T context) = 0;
            virtual T getContext(int vertex) = 0;
            virtual void addEdge(int fromVertex, int toVertex) = 0;
            virtual void addEdge(int fromVertex, int toVertex, int cost) = 0;
            virtual void updateEdgeCost(int fromVertex, int toVertex, int cost) = 0;
            virtual void removeEdge(int fromVertex, int toVertex) = 0;
            virtual bool edgeExists(int fromVertex, int toVertex) = 0;
            virtual void breadthFirstSearch(altrusian::graph::BfsVisitor& visitor, int vertex) = 0;
            virtual void depthFirstSearch(altrusian::graph::DfsVisitor& visitor,int vertex) = 0;
            virtual bool pathExists(int fromVertex, int toVertex) = 0;
            virtual bool isCyclic() = 0;

        };

    template <class T>
    bool Graph<T>::isEmpty() {
        return numVertices == 0;
    }

    template <class T>
    int Graph<T>::size() {
        return numVertices;
    }

}

#endif //GRAPHS_H
