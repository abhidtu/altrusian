//
// Created by linux on 25/1/16.
//

#include <stdexcept>
#include <cmath>
#include "D_ary_Heap.h"
#include "../Exceptions.h"

namespace altrusian {
    namespace Heaps {
        namespace D_Ary_Heap {

            typedef typename std::vector<int>::iterator heapIterator;

            int D_ary_Heap::max() {
                return !isEmpty() ? vector[firstNodeIndex()] : throw emptyHeapException;
            }

            int D_ary_Heap::extractMax() {
                int value = max();
                if(!isEmpty()) {
                    vector[firstNodeIndex()] = vector.back();
                    vector.pop_back();
                    bubbleDown(firstNodeIndex());
                }
                return value;
            }

            void D_ary_Heap::insert(int value) {

                vector.push_back(value);
                bubbleUp(lastNodeIndex());

            }

            void D_ary_Heap::heapify() {

                long int currentIndex = parentIndex(lastNodeIndex());

                while (currentIndex >= firstNodeIndex()) {
                    bubbleDown(currentIndex);
                    currentIndex--;
                }

            }

            //dependency injection of vector
            Heap*D_ary_Heap::mergeHeaps(Heap* heap1, Heap* heap2, Heap* heap, std::vector<int> &vector) {

                for(auto it = heap1->it_begin() ; it != heap1->it_end(); ++it) vector.push_back(*it);
                for(auto it = heap2->it_begin() ; it != heap2->it_end(); ++it) vector.push_back(*it);

                heap->heapify();

                return heap;

            }

            void D_ary_Heap::mergeWith(Heap* heap) {

                for(auto it = heap->it_begin() ; it != heap->it_end(); ++it)  vector.push_back(*it);

                heapify();

            }

            bool D_ary_Heap::isEmpty() {
                return vector.empty();
            }

            long int D_ary_Heap::size() {
                return vector.size();
            }

            void D_ary_Heap::bubbleUp(long int keyIndex) {

                while ( isCapableToShiftUp(keyIndex) ) {
                    shiftUp(keyIndex);
                    keyIndex = parentIndex(keyIndex);
                }
            }

            void D_ary_Heap::bubbleDown(long int keyIndex) {

                while ( isCapableToShiftDown(keyIndex) ) {
                    long int prevKeyIndex = maxChildIndex(keyIndex);
                    shiftDown(keyIndex);
                    keyIndex = prevKeyIndex;
                }
            }

            void D_ary_Heap::update(long int const& keyIndex, int const& value) {

                if(indexNotInBounds(keyIndex)) throw indexOutOfBoundsException;

                vector[keyIndex] = value;
                bubbleDown(keyIndex);
                bubbleUp(keyIndex);
            }

            heapIterator D_ary_Heap::it_begin() {
                return vector.begin();
            }

            heapIterator D_ary_Heap::it_end() {
                return vector.end();
            }

            bool D_ary_Heap::isFirstNode(long int const& keyIndex) {
                return keyIndex == 0;
            }

            bool D_ary_Heap::isLeafNode(long int const& keyIndex) {
                return firstChildIndex(keyIndex) > lastNodeIndex();
            }

            long int D_ary_Heap::parentIndex(long int const& keyIndex) {
                return (keyIndex - (distanceFromFirstChild(keyIndex))) / d;
            }

            long int D_ary_Heap::firstChildIndex(long int const& keyIndex) {
                return d*keyIndex + 1;
            }

            long int D_ary_Heap::lastNodeIndex() {
                return vector.size() - 1;
            }

            long int D_ary_Heap::firstNodeIndex() {
                return 0;
            }

            void D_ary_Heap::shiftUp(long int const& keyIndex) {
                std::swap(vector[keyIndex], vector[parentIndex(keyIndex)]);
            }

            void D_ary_Heap::shiftDown(long int const& keyIndex) {
                std::swap(vector[keyIndex], vector[maxChildIndex(keyIndex)]);
            }

            bool D_ary_Heap::indexNotInBounds(long int const& keyIndex) {
                return keyIndex > lastNodeIndex() || keyIndex < firstNodeIndex();
            }

            long int D_ary_Heap::dThChildIndex(long int const &firstChild) {
                return firstChild + d - 1;
            }

            long int D_ary_Heap::distanceFromFirstChild(long int const &keyIndex) {
                return (keyIndex - 1) % d;
            }

        }
    }
}
