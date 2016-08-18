//
// Created by linux on 4/2/16.
//

#include "MaxHeap.h"
#include "../../../util/Vector.h"

namespace LibAlDs {
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