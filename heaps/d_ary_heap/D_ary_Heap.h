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

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <vector>
#include "../Heap.h"
#include "../Exceptions.h"

namespace altrusian {
    namespace Heaps {
        namespace D_Ary_Heap {

            class D_ary_Heap : public Heap {

                Heaps::EmptyHeapException emptyHeapException;
                Heaps::IndexOutOfBounds indexOutOfBoundsException;

            protected:
                int d;
                virtual long int parentIndex(long int const &keyIndex);
                virtual long int firstChildIndex(long int const &keyIndex);
                virtual long int firstNodeIndex();
                virtual long int lastNodeIndex();
                virtual bool isCapableToShiftUp(long int const &keyIndex) = 0;
                virtual bool isCapableToShiftDown(long int const &keyIndex) = 0;
                virtual void shiftUp(long int const &keyIndex);
                virtual void shiftDown(long int const &keyIndex);
                virtual long int maxChildIndex(long int const &keyIndex) = 0;
                virtual void bubbleUp(long int keyIndex);
                virtual void bubbleDown(long int keyIndex);
                virtual bool isFirstNode(long int const &keyIndex);
                virtual bool isLeafNode(long int const &keyIndex);
                virtual bool indexNotInBounds(long int const &keyIndex);
                virtual long int dThChildIndex(long int const &firstChildIndex);
                virtual long int distanceFromFirstChild(long int const &keyIndex);

            public:
                int max();
                int extractMax();
                void insert(int value);
                void heapify();
                void update(long int const &keyIndex, int const &value);
                void mergeWith(Heap *heap);
                bool isEmpty();
                long int size();
                heapIterator it_begin();
                heapIterator it_end();

                static Heap *mergeHeaps(Heap *heap1, Heap *heap2, Heap *heap, std::vector<int> &vector);

            };

        }
    }
}


#endif //BINARYHEAP_H
