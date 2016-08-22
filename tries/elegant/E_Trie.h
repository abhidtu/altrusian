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

#ifndef E_TRIE_H
#define E_TRIE_H

#include <vector>
#include <stack>
#include <string>
#include "../Trie.h"
#include "TrieNode.h"
#include "../Exceptions.h"

using namespace std;

namespace altrusian {

    class E_Trie : public Trie {

    protected:
        Tries::PrefixNotFoundException prefixNotFoundException;
        TrieNode *root = new TrieNode();
        TrieNode* ptrToLeafNode(string str);
        void recurseDescendants(TrieNode* node, std::string &s, vector<string> &vec);
        TrieNode*leafNode(std::string str);

    public:

        E_Trie(){ }

        void insert(string str);
        void insert(string str, string value);
        string search(string word);
        vector<string> descendants(string str);
        bool exists(string str);
        void remove(string str);

    };

}

#endif //E_TRIE_H
