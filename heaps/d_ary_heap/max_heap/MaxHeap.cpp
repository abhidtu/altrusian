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


#include "MaxHeap.h"
#include "../../../util/Vector.h"

namespace altrusian {
    namespace Heaps {
        namespace D_Ary_Heap {

            bool MaxHeap::isCapableToShiftUp(long int const &keyIndex) {
                return !isFirstNode(keyIndex) && (vector[keyIndex] > vector[parentIndex(keyIndex)]);
            }

            bool MaxHeap::isCapableToShiftDown(long int const &keyIndex) {
                return !isLeafNode(keyIndex) && (vector[keyIndex] < vector[maxChildIndex(keyIndex)]);
            }

            long int MaxHeap::maxChildIndex(long int const &keyIndex) {
                long int firstChild = firstChildIndex(keyIndex);
                long int end = std::min(dThChildIndex(firstChild), lastNodeIndex());
                return Utils::Vector::maxElementIndex(vector, firstChild, end);
            }

            Heap *MaxHeap::mergeHeaps(Heap *heap1, Heap *heap2, int d) {
                MaxHeap *heap = new MaxHeap(d);
                return D_ary_Heap::mergeHeaps(heap1, heap2, heap, heap->vector);
            }

        }
    }
}