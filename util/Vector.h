//
// Created by linux on 1/2/16.
//

#ifndef VECTOR_H
#define VECTOR_H

#include "vector"

using namespace std;

namespace LibAlDs {

    namespace Utils {

        class Vector {

        public:
            static long int maxElementIndex(vector<int> const& vec, long int const& startIndex, long int const& endIndex);
            static long int minElementIndex(vector<int> const& vec, long int const& startIndex, long int const& endIndex);

        };

    }

}



#endif //VECTOR_H
