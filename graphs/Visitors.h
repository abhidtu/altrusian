//
// Created by linux on 1/3/16.
//

#include <stack>

#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

namespace LibAlDs {
    namespace graph {

        class DfsVisitor {

        public:
            virtual void onVertexDiscovery(int vertex) = 0;

        };

        class BfsVisitor {

        public:
            virtual void onVertexDiscovery(int vertex) = 0;

        };



    }
}

#endif //VISITOR_H
