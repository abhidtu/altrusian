// Created by linux on 14/1/16.

#include <stddef.h>
#include "DoublyLinkedListNode.h"
#include "../LinkedList.h"

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

namespace altrusian {
    namespace Lists {

        class DoublyLinkedList : public LinkedList {

        protected:
            DoublyLinkedListNode *start = NULL, *end = NULL;
            DoublyLinkedListNode* createNewNode(int value);
            void attachInEmptyList(DoublyLinkedListNode* node);
            void attachBeforeStart(DoublyLinkedListNode* node);
            void attachAfterEnd(DoublyLinkedListNode* node);
            bool containsSingleNode();
            void detachFromBeginning();
            void detachFromEnd();
            void detachFromSingleNodeList();
            bool hasNext(DoublyLinkedListNode* iterator);

        public:
            void insertAtBeginning(int value);
            void insertAtEnd(int value);
            bool isEmpty();

        };

    }
}


#endif //DOUBLY_LINKED_LIST_H
