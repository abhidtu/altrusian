//
// Created by linux on 6/2/16.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include "List.h"
#include "singly/SinglyLinkedListNode.h"

namespace altrusian {
    namespace Lists {

        class LinkedList : public List {

    protected:
        virtual bool containsSingleNode() = 0;
        virtual void detachFromBeginning() = 0;
        virtual void detachFromEnd() = 0;
        virtual void detachFromSingleNodeList() = 0;

    public:
        void deleteFromBeginning();
        void deleteFromEnd();
        int size();
        virtual bool isEmpty() = 0;

    };
}


}


#endif //LINKEDLIST_H
