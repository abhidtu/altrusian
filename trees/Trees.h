//
// Created by linux on 15/1/16.
//

#ifndef TREES_H
#define TREES_H

#include "binary_search_trees/BinarySearchTreeNode.h"

namespace LibAlDs {

    class Trees {

    protected:
        int NumNodes = 0;

    public:
        virtual void insert(int value) = 0;
        virtual BinarySearchTreeNode* find(int value) = 0;
        virtual void remove(int value) = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;

    };

}
#endif //TREES_H
