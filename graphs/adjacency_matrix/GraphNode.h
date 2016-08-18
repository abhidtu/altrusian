//
// Created by linux on 28/2/16.
//

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <iostream>
#include <vector>
#include "../adjacency_matrix/GraphEdge.h"


namespace LibAlDs {
    namespace graph {

        template <class T>
        class GraphNode {

        public:
            T context;
            std::vector<GraphEdge> vertexList;

        };

    }
}

#endif //GRAPHNODE_H
