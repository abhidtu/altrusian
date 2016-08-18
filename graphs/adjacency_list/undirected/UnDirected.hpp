//
// Created by linux on 21/2/16.
//

#ifndef UNDIRECTED_H
#define UNDIRECTED_H

#include "../Adjacency_list.hpp"

namespace LibAlDs {
    namespace graph {
        namespace adjacency_list {

            template <class T>
            class UnDirected : public Adjacency_list<T> {

                using Adjacency_list<T>::Adjacency_list;
        
            public:
                void addEdge(int vertex1, int vertex2);
                void addEdge(int vertex1, int vertex2, int cost);
                void updateEdgeCost(int vertex1, int vertex2, int cost);
                void removeEdge(int vertex1, int vertex2);
                bool edgeExists(int vertex1, int vertex2);

            };

            template <class T>
            void UnDirected<T>::addEdge(int vertex1, int vertex2) {
                Adjacency_list<T>::addEdge(vertex1,vertex2);
                Adjacency_list<T>::addEdge(vertex2,vertex1);
            }

            template <class T>
            void UnDirected<T>::addEdge(int vertex1, int vertex2, int cost) {
                Adjacency_list<T>::addEdge(vertex1,vertex2,cost);
                Adjacency_list<T>::addEdge(vertex2,vertex1,cost);
            }

            template <class T>
            void UnDirected<T>::updateEdgeCost(int vertex1, int vertex2, int cost) {
                Adjacency_list<T>::updateEdgeCost(vertex1,vertex2,cost);
                Adjacency_list<T>::updateEdgeCost(vertex2,vertex1,cost);
            }

            template <class T>
            void UnDirected<T>::removeEdge(int vertex1, int vertex2) {
                Adjacency_list<T>::removeEdge(vertex1,vertex2);
                Adjacency_list<T>::removeEdge(vertex2,vertex1);
            }

            template <class T>
            bool UnDirected<T>::edgeExists(int vertex1, int vertex2) {
                return Adjacency_list<T>::edgeExists(vertex1,vertex2) && Adjacency_list<T>::edgeExists(vertex2,vertex1);
            }

        }
    }
}


#endif //C___UNDIRECTED_H
