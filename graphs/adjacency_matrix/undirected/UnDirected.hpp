//
// Created by linux on 20/2/16.
//

#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "../Adjacency_matrix.hpp"

namespace LibAlDs {
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
