//
// Created by linux on 4/2/16.
//

#include "MinHeap.h"
#include "../../../util/Vector.h"


namespace altrusian {
    namespace Heaps {
        namespace D_Ary_Heap {

            bool MinHeap::isCapableToShiftUp(long int const &keyIndex) {
                return !isFirstNode(keyIndex) && (vector[keyIndex] < vector[parentIndex(keyIndex)]);
            }

            bool MinHeap::isCapableToShiftDown(long int const &keyIndex) {
                return !isLeafNode(keyIndex) && (vector[keyIndex] > vector[maxChildIndex(keyIndex)]);
            }

            long int MinHeap::maxChildIndex(long int const &keyIndex) {
                long int firstChild = firstChildIndex(keyIndex);
                long int end = std::min(dThChildIndex(firstChild), lastNodeIndex());
                return Utils::Vector::minElementIndex(vector, firstChild, end);
            }

            Heap *MinHeap::mergeHeaps(Heap *heap1, Heap *heap2, int d) {
                MinHeap *heap = new MinHeap(d);
                return D_ary_Heap::mergeHeaps(heap1, heap2, heap, heap->vector);
            }

        }
    }
}