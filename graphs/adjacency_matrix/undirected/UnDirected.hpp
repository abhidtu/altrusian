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


#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "../Adjacency_matrix.hpp"

namespace altrusian {
    namespace graph {
        namespace adjacency_matrix {

            template <class T>
            class UnDirected : public Adjacency_matrix<T> {

                using Adjacency_matrix<T>::Adjacency_matrix;

            public:
                void addEdge(int vertex1, int vertex2);
                void addEdge(int vertex1, int vertex2, int cost);
                void updateEdgeCost(int vertex1, int vertex2, int cost);
                void removeEdge(int vertex1, int vertex2);
                bool edgeExists(int vertex1, int vertex2);

            };

            template <class T>
            void UnDirected<T>::addEdge(int vertex1, int vertex2) {
                Adjacency_matrix<T>::addEdge(vertex1,vertex2);
                Adjacency_matrix<T>::addEdge(vertex2,vertex1);
            }

            template <class T>
            void UnDirected<T>::addEdge(int vertex1, int vertex2, int cost) {
                Adjacency_matrix<T>::addEdge(vertex1,vertex2,cost);
                Adjacency_matrix<T>::addEdge(vertex2,vertex1,cost);
            }

            template <class T>
            void UnDirected<T>::updateEdgeCost(int vertex1, int vertex2, int cost) {
                Adjacency_matrix<T>::updateEdgeCost(vertex1,vertex2,cost);
                Adjacency_matrix<T>::updateEdgeCost(vertex2,vertex1,cost);
            }

            template <class T>
            void UnDirected<T>::removeEdge(int vertex1, int vertex2) {
                Adjacency_matrix<T>::removeEdge(vertex1,vertex2);
                Adjacency_matrix<T>::removeEdge(vertex2,vertex1);
            }

            template <class T>
            bool UnDirected<T>::edgeExists(int vertex1, int vertex2) {
                return Adjacency_matrix<T>::edgeExists(vertex1,vertex2) && Adjacency_matrix<T>::edgeExists(vertex2,vertex1);
            }

        }

    }
}


#endif //UNDIRECTED_H
