//
// Created by linux on 20/2/16.
//

#ifndef DIRECTED_H
#define DIRECTED_H

#include "../Adjacency_matrix.hpp"

namespace altrusian {
    namespace graph {
        namespace adjacency_matrix {

            template <class T>
            class Directed : public Adjacency_matrix<T> {

                using Adjacency_matrix<T>::Adjacency_matrix;

            public:

            };
        }

    }
}


#endif //DIRECTED_H
