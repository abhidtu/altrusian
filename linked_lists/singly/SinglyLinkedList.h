// Created by linux on 11/1/16.

#include <stddef.h>
#include "SinglyLinkedListNode.h"
#include "../LinkedList.h"

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

namespace altrusian {
    namespace Lists {

        class SinglyLinkedList: public LinkedList {

        protected:
            SinglyLinkedListNode *start = NULL, *end = NULL;
            SinglyLinkedListNode* createNewNode(int value);
            void attachInEmptyList(SinglyLinkedListNode* node);
            void attachBeforeStart(SinglyLinkedListNode* node);
            void attachAfterEnd(SinglyLinkedListNode* node);
            bool containsSingleNode();
            void detachFromBeginning();
            void detachFromEnd();
            void detachFromSingleNodeList();
            bool hasNext(SinglyLinkedListNode* iterator);

        public:
            void insertAtBeginning(int value);
            void insertAtEnd(int value);
            bool isEmpty();

        };
}

}


#endif //SINGLY_LINKED_LIST_H
