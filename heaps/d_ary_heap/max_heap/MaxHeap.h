//
// Created by linux on 4/2/16.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "../D_ary_Heap.h"

namespace LibAlDs {
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
