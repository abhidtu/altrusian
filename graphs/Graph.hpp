//
// Created by linux on 15/2/16.
//

#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include "Visitors.h"

namespace LibAlDs {

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
            virtual void breadthFirstSearch(LibAlDs::graph::BfsVisitor& visitor, int vertex) = 0;
            virtual void depthFirstSearch(LibAlDs::graph::DfsVisitor& visitor,int vertex) = 0;
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
