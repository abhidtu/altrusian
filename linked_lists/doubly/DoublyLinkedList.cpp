// Created by linux on 14/1/16.

#include <iostream>
#include "DoublyLinkedList.h"

namespace LibAlDs {
    namespace Lists {

        /**
     * Tn = O(1)
     */
        void DoublyLinkedList::insertAtBeginning(int value) {
            isEmpty() ? attachInEmptyList(createNewNode(value)) : attachBeforeStart(createNewNode(value));
        }

        /**
     * Tn = O(1)
     */
        void DoublyLinkedList::insertAtEnd(int value) {
            isEmpty() ? attachInEmptyList(createNewNode(value)) : attachAfterEnd(createNewNode(value));
        }

        /**
     * Tn = O(1)
     */
        bool DoublyLinkedList::isEmpty() {
            return start == NULL;
        }

        //private methods
        /**
     * Tn = O(1)
     */
        DoublyLinkedListNode *DoublyLinkedList::createNewNode(int value) {
            DoublyLinkedListNode *node = new DoublyLinkedListNode();
            node->value = value;
            node->left = NULL;
            node->right = NULL;
            return node;
        }

        void DoublyLinkedList::attachInEmptyList(DoublyLinkedListNode* node) {
            start = end = node;
            NumNodes++;
        }

        void DoublyLinkedList::attachBeforeStart(DoublyLinkedListNode* node) {
            node->right = start;
            start->left = node;
            start = node;
            NumNodes++;
        }

        void DoublyLinkedList::attachAfterEnd(DoublyLinkedListNode* node) {
            end->right = node;
            node->left = end;
            end = node;
            NumNodes++;
        }

        bool DoublyLinkedList::containsSingleNode() {
            return start->right == NULL;
        }

        void DoublyLinkedList::detachFromBeginning() {
            DoublyLinkedListNode *tmp = start;
            start = start->right;
            start->left = NULL;
            delete tmp;
            tmp = NULL;
            NumNodes--;
        }

        void DoublyLinkedList::detachFromEnd() {
            end->left->right = NULL;
            DoublyLinkedListNode *tmp = end;
            end = end->left;
            delete tmp;
            tmp = NULL;
            NumNodes--;
        }

        void DoublyLinkedList::detachFromSingleNodeList() {
            delete start;
            start = end = NULL;
            NumNodes--;
        }

        bool DoublyLinkedList::hasNext(DoublyLinkedListNode* iterator) {
            return iterator->right != NULL;
        }

    }
}