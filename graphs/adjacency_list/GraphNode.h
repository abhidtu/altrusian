//
// Created by linux on 28/2/16.
//

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <iostream>
#include <list>
#include "GraphEdge.h"

namespace LibAlDs {
    namespace graph {

        template <class T>
        class GraphNode {

        public:
            T context;
            std::list<GraphEdge*> connectedVerticesList;

        };

    }
}

#endif //GRAPHNODE_H
