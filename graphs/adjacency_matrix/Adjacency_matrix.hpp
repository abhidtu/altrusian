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

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include "GraphEdge.h"
#include "../Graph.hpp"
#include "GraphNode.h"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
//#include "boost/graph/depth_first_search.hpp"

using namespace std;

namespace altrusian {
    namespace graph {

        template <class T>
        class Adjacency_matrix : public Graph<T> {

        protected:
        vector<GraphNode<T>> vertices;
        //void depthFirstSearch(DfsVisitor& visitor, int currentVertex, bool *isVertexVisited);

        public:
            Adjacency_matrix(){}

            Adjacency_matrix(int vertices) {
                this->numVertices = vertices;
                for(int i = 0; i < vertices; i++) addVertex(T());
            }

            virtual void addVertex(T context);
            virtual void setContext(int vertex, T context);
            virtual T getContext(int vertex);
            virtual void addEdge(int fromVertex, int toVertex);
            virtual void addEdge(int fromVertex, int toVertex, int cost);
            virtual void updateEdgeCost(int fromVertex, int toVertex, int cost);
            virtual void removeEdge(int fromVertex, int toVertex);
            virtual bool edgeExists(int fromVertex, int toVertex);
            virtual void breadthFirstSearch(BfsVisitor& visitor, int startVertex);
            virtual bool pathExists(int fromVertex, int toVertex);
            virtual bool isCyclic();
            virtual void depthFirstSearch(DfsVisitor& visitor, int startVertex);
        };

        template <class T>
        void Adjacency_matrix<T>::addVertex(T context) {
            GraphNode<T> graphNode;
            graphNode.context = context;

            for(int j = 0; j < this->numVertices; j++) {
                GraphEdge g;
                graphNode.vertexList.push_back(g);
            }

            vertices.push_back(graphNode);
        }

        template <class T>
        void Adjacency_matrix<T>::setContext(int vertex, T context) {
            vertices[vertex].context = context;
        }

        template <class T>
        T Adjacency_matrix<T>::getContext(int vertex) {
            return vertices[vertex].context;
        }

        template <class T>
        void Adjacency_matrix<T>::addEdge(int fromVertex, int toVertex) {
            vertices[fromVertex].vertexList[toVertex].exists = true;
        }

        template <class T>
        void Adjacency_matrix<T>::addEdge(int fromVertex, int toVertex, int cost) {
            vertices[fromVertex].vertexList[toVertex].cost = cost;
            vertices[fromVertex].vertexList[toVertex].exists =  true;
        }

        template <class T>
        void Adjacency_matrix<T>::updateEdgeCost(int fromVertex, int toVertex, int cost) {
            vertices[fromVertex].vertexList[toVertex].cost = cost;
        }

        template <class T>
        void Adjacency_matrix<T>::removeEdge(int fromVertex, int toVertex) {
            vertices[fromVertex].vertexList[toVertex].exists = false;
            vertices[fromVertex].vertexList[toVertex].cost = 0;
        }

        template <class T>
        bool Adjacency_matrix<T>::edgeExists(int fromVertex, int toVertex) {
            return vertices[fromVertex].vertexList[toVertex].exists;
        }

        template <class T>
        void Adjacency_matrix<T>::breadthFirstSearch(BfsVisitor& visitor, int startVertex) {
            queue<int> q;
            q.push(startVertex);

            bool isVertexVisited[this->numVertices] = {};

            while(!q.empty()) {
                int currentVertex = q.front();
                q.pop();

                if (!isVertexVisited[currentVertex]) {

                    visitor.onVertexDiscovery(currentVertex);
                    isVertexVisited[currentVertex] = true;

                    for (int vertex = 0; vertex < this->numVertices; vertex++) {
                        if (edgeExists(currentVertex, vertex)) q.push(vertex);
                    }

                }
            }

        }

        template <class T>
        void Adjacency_matrix<T>::depthFirstSearch(DfsVisitor& visitor, int startVertex) {

            stack<int> s;
            s.push(startVertex);

            bool isVertexVisited[this->numVertices] = {};

            while(!s.empty()) {
                int currentVertex = s.top();
                s.pop();

                if (!isVertexVisited[currentVertex]) {
                    visitor.onVertexDiscovery(currentVertex);

                    isVertexVisited[currentVertex] = true;

                    for (int vertex = 0; vertex < this->numVertices; vertex++) {
                        if (edgeExists(currentVertex, vertex))  s.push(vertex);
                    }

                }
            }

        }

/*
 * Recursive DFS implementation
        template <class T>
        void Adjacency_matrix<T>::depthFirstSearch(DfsVisitor& visitor, int currentVertex, bool *isVertexVisited) {

            visitor.onVertexDiscovery(currentVertex);
            isVertexVisited[currentVertex] = true;

            for(int vertex = 0; vertex < this->numVertices; vertex++) {
                if(edgeExists(currentVertex,vertex) && !isVertexVisited[vertex]) {
                    depthFirstSearch(visitor, vertex, isVertexVisited);
                }
            }

        }
*/

        template <class T>
        bool Adjacency_matrix<T>::pathExists(int fromVertex, int toVertex) {

            stack<int> s;
            s.push(fromVertex);

            bool isVertexVisited[this->numVertices] = {};

            while(!s.empty()) {
                int currentVertex = s.top();
                s.pop();

                if (!isVertexVisited[currentVertex]) {

                    if(currentVertex == toVertex) return true;
                    isVertexVisited[currentVertex] = true;

                    for (int vertex = 0; vertex < this->numVertices; vertex++) {
                        if (edgeExists(currentVertex, vertex)) s.push(vertex);
                    }

                }
            }
            return false;

        }


        template <class T>
        bool Adjacency_matrix<T>::isCyclic() {

            stack<int> s;
            s.push(0);

            bool isVertexVisited[this->numVertices] = {};

            stack<int> ps;
            ps.push(0);

            while(!s.empty()) {
                int currentVertex = s.top();
                s.pop();

                int parent = ps.top();
                ps.pop();

                if (!isVertexVisited[currentVertex]) {

                    isVertexVisited[currentVertex] = true;

                    for (int vertex = 0; vertex < this->numVertices; vertex++) {
                        if (edgeExists(currentVertex, vertex)) {

                            if(isVertexVisited[vertex] && vertex != parent) return true;

                            ps.push(currentVertex);
                            s.push(vertex);
                        }
                    }

                }
            }
            return false;

        }


    }

}



#endif //ADJACENCY_MATRIX_H
