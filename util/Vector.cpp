//
// Created by linux on 1/2/16.
//

#include "Vector.h"

namespace altrusian {

    namespace Utils {

        long int Vector::maxElementIndex(vector<int> const& vec, long int const& startIndex, long int const& endIndex) {
            long int max = vec[startIndex];
            long int maxIndex = startIndex;
            for(auto i = startIndex; i <= endIndex; i++) {

                if(vec[i] > max) {
                    max = vec[i];
                    maxIndex = i;
                }

            }
            return maxIndex;
        }

        long int Vector::minElementIndex(vector<int> const& vec, long int const& startIndex, long int const& endIndex) {
            long int max = vec[startIndex];
            long int maxIndex = startIndex;
            for(auto i = startIndex; i <= endIndex; i++) {

                if(vec[i] < max) {
                    max = vec[i];
                    maxIndex = i;
                }

            }
            return maxIndex;
        }

    }

}
