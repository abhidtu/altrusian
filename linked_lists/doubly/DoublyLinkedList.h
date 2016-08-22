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
