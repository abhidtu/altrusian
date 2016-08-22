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