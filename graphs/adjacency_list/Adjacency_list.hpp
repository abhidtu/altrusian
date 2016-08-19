//
// Created by linux on 15/2/16.
//

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H


#include <vector>
#include <list>
#include "GraphEdge.h"
#include "../Graph.hpp"
#include "../adjacency_list/GraphNode.h"
#include <queue>
#include <stack>

using namespace std;

namespace altrusian {
    namespace graph {

        template <class T>
        class Adjacency_list : public Graph<T> {

        protected:
            vector<GraphNode<T>> vertices;
            GraphEdge* getNewEdgeToVertex(int toVertex);
            GraphEdge* getNewEdgeToVertex(int toVertex,int cost);
            list<GraphEdge*> listOfVerticesConnectedTo(int vertex);
            //void depthFirstSearch(DfsVisitor& visitor, int currentVertex, bool *isVertexVisited);

        public:
            Adjacency_list(){}

            Adjacency_list(int vertices) {
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
            virtual void depthFirstSearch(DfsVisitor& visitor, int startVertex);
            virtual bool pathExists(int fromVertex, int toVertex);
            virtual bool isCyclic();

        };

        template <class T>
        GraphEdge *Adjacency_list<T>::getNewEdgeToVertex(int toVertex) {
            GraphEdge *g = new GraphEdge();
            g->vertex = toVertex;
            return g;
        }

        template <class T>
        GraphEdge *Adjacency_list<T>::getNewEdgeToVertex(int toVertex, int cost) {
            GraphEdge *g = new GraphEdge();
            g->vertex = toVertex;
            g->cost = cost;
            return g;
        }

        template <class T>
        void Adjacency_list<T>::addVertex(T context) {
            GraphNode<T> graphNode;
            graphNode.context = context;
            vertices.push_back(graphNode);
        }

        template <class T>
        void Adjacency_list<T>::setContext(int vertex, T context) {
            vertices[vertex].context = context;
        }

        template <class T>
        T Adjacency_list<T>::getContext(int vertex) {
            return vertices[vertex].context;
        }

        template <class T>
        void Adjacency_list<T>::addEdge(int fromVertex, int toVertex) {
            vertices[fromVertex].connectedVerticesList.push_back(getNewEdgeToVertex(toVertex));
        }

        template <class T>
        void Adjacency_list<T>::addEdge(int fromVertex, int toVertex, int cost) {
            vertices[fromVertex].connectedVerticesList.push_back(getNewEdgeToVertex(toVertex,cost));
        }

        template <class T>
        void Adjacency_list<T>::updateEdgeCost(int fromVertex, int toVertex, int cost) {
            for(auto *g : vertices[fromVertex].connectedVerticesList) {
                if(g->vertex == toVertex) g->cost = cost;
            }
        }

        template <class T>
        void Adjacency_list<T>::removeEdge(int fromVertex, int toVertex) {
            for(auto& g : vertices[fromVertex].connectedVerticesList) {
                if(g->vertex == toVertex) {
                    vertices[fromVertex].connectedVerticesList.remove(g);
                    break;
                }
            }
        }

        template <class T>
        bool Adjacency_list<T>::edgeExists(int fromVertex, int toVertex) {
            for(auto *g : vertices[fromVertex].connectedVerticesList) {
                if(g->vertex == toVertex) return true;
            }
            return false;
        }

        template <class T>
        list<GraphEdge *> Adjacency_list<T>::listOfVerticesConnectedTo(int vertex) {
            return vertices[vertex].connectedVerticesList;
        }

        template <class T>
        void Adjacency_list<T>::breadthFirstSearch(BfsVisitor& visitor, int startVertex) {
            queue<int> q;
            q.push(startVertex);

            bool isVertexVisited[this->numVertices] = {};

            while(!q.empty()) {
                int currentVertex = q.front();
                q.pop();

                if (!isVertexVisited[currentVertex]) {

                    visitor.onVertexDiscovery(currentVertex);
                    isVertexVisited[currentVertex] = true;

                    for (auto &g : listOfVerticesConnectedTo(currentVertex)) {
                        q.push(g->vertex);
                    }

                }

            }

        }

        template <class T>
        void Adjacency_list<T>::depthFirstSearch(DfsVisitor& visitor, int startVertex) {

            stack<int> s;
            s.push(startVertex);

            bool isVertexVisited[this->numVertices] = {};

            while(!s.empty()) {
                int currentVertex = s.top();
                s.pop();

                if (!isVertexVisited[currentVertex]) {

                    visitor.onVertexDiscovery(currentVertex);
                    isVertexVisited[currentVertex] = true;

                    for (auto &g : listOfVerticesConnectedTo(currentVertex)) {
                        s.push(g->vertex);
                    }

                }

            }

        }

/*
 * Recursive DFS implementation
        template <class T>
        void Adjacency_list<T>::depthFirstSearch(DfsVisitor& visitor,int currentVertex, bool *isVertexVisited) {

            visitor.onVertexDiscovery(currentVertex);
            isVertexVisited[currentVertex] = true;

            for(auto& g : listOfVerticesConnectedTo(currentVertex)) {
                if(!isVertexVisited[g->vertex]) {
                    depthFirstSearch(visitor,g->vertex,isVertexVisited);
                }
            }

        }
*/

        template <class T>
        bool Adjacency_list<T>::pathExists(int fromVertex, int toVertex) {

            stack<int> s;
            s.push(fromVertex);

            bool isVertexVisited[this->numVertices] = {};

            while(!s.empty()) {
                int currentVertex = s.top();
                s.pop();

                if (!isVertexVisited[currentVertex]) {

                    if(currentVertex == toVertex) return true;
                    isVertexVisited[currentVertex] = true;

                    for (auto &g : listOfVerticesConnectedTo(currentVertex)) {
                        s.push(g->vertex);
                    }

                }

            }

            return false;

        }


        template <class T>
        bool Adjacency_list<T>::isCyclic() {

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

                    for (auto &g : listOfVerticesConnectedTo(currentVertex)) {
                        if(isVertexVisited[g->vertex] && g->vertex != parent) return true;

                        ps.push(currentVertex);
                        s.push(g->vertex);
                    }

                }

            }
            return false;
        }

    }
 }


#endif //ADJACENCY_LIST_H
