// Created by linux on 11/1/16.

#include <iostream>
using namespace std;
#include "SinglyLinkedList.h"

namespace altrusian {
    namespace Lists {

        /**
     * Tn = O(1)
     */
        void SinglyLinkedList::insertAtBeginning(int value) {
            isEmpty() ? attachInEmptyList(createNewNode(value)) : attachBeforeStart(createNewNode(value));
        }

        /**
     * Tn = O(1)
     */
        void SinglyLinkedList::insertAtEnd(int value) {
            isEmpty() ? attachInEmptyList(createNewNode(value)) : attachAfterEnd(createNewNode(value));
        }

        //private methods
        /**
     * Tn = O(1)
     */
        SinglyLinkedListNode *SinglyLinkedList::createNewNode(int value) {

            SinglyLinkedListNode *node = new SinglyLinkedListNode();
            node->value = value;
            node->right = NULL;
            return node;

        }

        bool SinglyLinkedList::isEmpty() {
            return start == NULL;
        }

        void SinglyLinkedList::attachBeforeStart(SinglyLinkedListNode* node) {
            node->right = start;
            start = node;
            NumNodes++;
        }

        void SinglyLinkedList::attachAfterEnd(SinglyLinkedListNode* node) {
            end->right = node;
            end = node;
            NumNodes++;
        }

        void SinglyLinkedList::attachInEmptyList(SinglyLinkedListNode* node) {
            start = end = node;
            NumNodes++;
        }

        bool SinglyLinkedList::containsSingleNode() {
            return start->right == NULL;
        }

        void SinglyLinkedList::detachFromBeginning() {
            SinglyLinkedListNode *tmp = start;
            start = start->right;
            delete tmp;
            tmp = NULL;
            NumNodes--;
        }

        void SinglyLinkedList::detachFromEnd() {

            SinglyLinkedListNode *iterator = start;
            while (iterator->right != end) iterator = iterator->right;

            iterator->right = NULL;
            delete end;
            end = iterator;
            NumNodes--;
        }

        void SinglyLinkedList::detachFromSingleNodeList() {
            delete start;
            start = end = NULL;
            NumNodes--;
        }

        bool SinglyLinkedList::hasNext(SinglyLinkedListNode* iterator) {
            return iterator->right != NULL;
        }

    }
}