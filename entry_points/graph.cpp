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
#include "../graphs/Graph.hpp"
//#include "../graphs/adjacency_matrix/undirected/UnDirected.hpp"
#include "../graphs/adjacency_list/undirected/UnDirected.hpp"

#include <unordered_map>

using namespace std;
using namespace altrusian;

class SuperStar {
public:
    string name;
    int weight;
    int height;
    int chest;
    int biceps;
};

class Traversal : public altrusian::graph::DfsVisitor {


public:
    void onVertexDiscovery(int vertex) {
        cout << vertex;
    }

};

class BfsTraversal : public altrusian::graph::BfsVisitor {

public:
    void onVertexDiscovery(int vertex) {
        cout << vertex;
    }

};

int main() {

    altrusian::graph::adjacency_list::UnDirected<SuperStar> directed(10);
    altrusian::Graph<SuperStar> *graphs = &directed;

    SuperStar star;
    star.biceps = 50;
    star.chest = 200;
    star.height = 6;
    star.name = "jhon cena";
    star.weight = 286;

    graphs->addEdge(0,2);
    graphs->setContext(0,star);

    //graphs->addEdge(0,6);
    //graphs->addEdge(0,9);

    //graphs->addEdge(1,2);
    graphs->addEdge(1,5);

    //graphs->addEdge(2,8);
    //graphs->addEdge(2,3);
    graphs->addEdge(2,6);
    graphs->addEdge(2,7);

    graphs->addEdge(3,8);
    graphs->addEdge(3,4);

    graphs->addEdge(4,7);

    graphs->addEdge(5,7);

    graphs->addEdge(6,9);



    //graphs->updateEdgeCost(0,1,8);
    //graphs->updateEdgeCost(0,2,8);

   // graphs->removeEdge(0,2);

    //cout << graphs->edgeExists(0,2);

    //graphs->addVertex();

    //cout << graphs->isEmpty();
    //cout << graphs->size();
    //cout << "\n";

    BfsTraversal bfsTraversal;

    cout << "bfs " ;
    graphs->breadthFirstSearch(bfsTraversal,0);

    cout << "\n";

    Traversal traversal;

    cout << "dfs ";
    graphs->depthFirstSearch(traversal,0);

    cout << "\n";
    cout << "pathExists " << graphs->pathExists(0,6);

    cout << "\n";

    cout << "iscyclic " << graphs->isCyclic();

    return 0;
}

