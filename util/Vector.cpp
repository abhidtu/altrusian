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
