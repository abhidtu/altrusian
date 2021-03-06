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


#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "../D_ary_Heap.h"

namespace altrusian {
    namespace Heaps {
        namespace D_Ary_Heap {

            class MaxHeap : public D_ary_Heap {

            protected:
                bool isCapableToShiftUp(long int const &keyIndex);
                bool isCapableToShiftDown(long int const &keyIndex);
                long int maxChildIndex(long int const &keyIndex);

            public:
                MaxHeap(int d) { this->d = d; }

                MaxHeap(int d, std::vector<int> &vec) {
                    this->d = d;
                    vector = vec;
                    heapify();
                }

                static Heap* mergeHeaps(Heap *heap1, Heap *heap2, int d);

            };

        }
    }
}


#endif //MAXHEAP_H
