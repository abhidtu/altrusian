//
// Created by linux on 25/1/16.
//

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <vector>
#include "../Heap.h"
#include "../Exceptions.h"

namespace LibAlDs {
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
