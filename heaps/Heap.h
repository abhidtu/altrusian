//
// Created by linux on 15/1/16.
//

#ifndef HEAPS_H
#define HEAPS_H

namespace LibAlDs {

    class Heap {

    protected:
        std::vector<int> vector;

    public:
        typedef typename std::vector<int>::iterator heapIterator;
        virtual int max() = 0;
        virtual int extractMax() = 0;
        virtual void insert(int value) = 0;
        virtual void heapify() = 0;
        virtual void update(long int const& keyIndex, int const& value) = 0;
        virtual void mergeWith(Heap* heap) = 0;
        virtual bool isEmpty() = 0;
        virtual long int size() = 0;
        virtual heapIterator it_begin() = 0;
        virtual heapIterator it_end() = 0;

    };

}
#endif //HEAPS_H
