/**
 * Copyright (c) 2016 Abhishek Chawla <abhidtu@gmail.com>
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include "DoublyLinkedList.h"

namespace altrusian {
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