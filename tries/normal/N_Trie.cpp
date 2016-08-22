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
#include "N_Trie.h"
using namespace std;

namespace altrusian {

    void N_Trie::insert(string str) {
        ptrToLeafNode(str);
    }

    void N_Trie::insert(string str, string value) {
        ptrToLeafNode(str)->value = value;
    }

    string N_Trie::search(string str) {
        return leafNode(str)->value;
    }

    void N_Trie::recurseDescendants(TrieNode* node, std::string &s, vector<string> &vec) {

        if(!node->childNodes) {
            vec.push_back(s);
            return;
        }

        for(int i = 0; i < 256; i++) {
            if(node->hash[i]) {
                s.push_back((char) i);
                recurseDescendants(node->hash[i],s,vec);
                s.pop_back();
            }
        }

    }

    vector<string> N_Trie::descendants(string str) {
        std::string s;
        vector<string> vec;
        recurseDescendants(leafNode(str),s, vec);
        return vec;
    }

    TrieNode* N_Trie::ptrToLeafNode(string str) {

        TrieNode *node, *prevNode = root;
        for(auto& c : str) {
            if(prevNode->hash[c]) {
                node = prevNode->hash[c];
            } else {
                node = createNewNode();
                prevNode->childNodes++;
                NumNodes++;
            }
            prevNode->hash[c] = node;
            prevNode = node;
        }

        return prevNode;
    }

    TrieNode* N_Trie::leafNode(string str) {
        TrieNode *node = root;
        for(auto& c : str) {
            node->hash[c] ? node = node->hash[c] : throw prefixNotFoundException;
        }
        return node;
    }

    TrieNode* N_Trie::createNewNode() {
        return new TrieNode();
    }

    bool N_Trie::exists(string str) {
        TrieNode* node = root;
        for(auto& c : str) {
            if(node->hash[c]) {
                node = node->hash[c];
            }else {
                return false;
            }
        }
        return true;
    }

    void N_Trie::remove(string str) {

        TrieNode* node = root;
        TrieNode* lastBranching = root;
        int index = 0;
        int branchingCount = 0;

        //finding the lowest branching point in the path
        for(int i = 0; i < str.length(); i++) {

            //if str not found then return
            if(!node->hash[str[i]]) return;

            node = node->hash[str[i]];

            if(node->childNodes > 1) {
                lastBranching = node;
                index = i;
                branchingCount++;
            }
        }

        //if there is a child below this then return
        if(node->childNodes) {
            node->value = "";
            return;
        }

        //checking if the tree contains only one string and there is no branching
        int branchLeafIndex = 0;
        if(branchingCount) {
            branchLeafIndex = index+1;
        }

        TrieNode *tmp1 = nullptr,*tmp2 = nullptr;

        //copy the reference and then set it to nullptr
        tmp1 = lastBranching->hash[str[branchLeafIndex]];
        lastBranching->hash[str[branchLeafIndex]] = nullptr;
        lastBranching->childNodes--;

        //delete all the single node descendants
        if(branchLeafIndex+1 < str.length()) {
            for(int i = branchLeafIndex+1; i < str.length(); i++) {
                tmp2 = tmp1->hash[str[i]];
                delete tmp1;
                tmp1 = tmp2;
            }
        }

        delete tmp1;

    }

}