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
