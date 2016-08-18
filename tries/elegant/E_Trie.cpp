//
// Created by linux on 7/2/16.
//

#include <iostream>
#include "E_Trie.h"
using namespace std;

namespace LibAlDs {

    void E_Trie::insert(string str) {
        ptrToLeafNode(str);
    }

    void E_Trie::insert(string str, string value) {
        ptrToLeafNode(str)->value = value;
    }

    string E_Trie::search(string str) {
        return leafNode(str)->value;
    }

    void E_Trie::recurseDescendants(TrieNode* node, std::string &s, vector<string> &vec) {

        if(node->map.empty()) {
            vec.push_back(s);
            return;
        }

        for(auto& key : node->map) {
            s.push_back(key.first);
            recurseDescendants(key.second,s,vec);
            s.pop_back();
        }

    }

    vector<string> E_Trie::descendants(string str) {
        std::string s;
        vector<string> vec;
        recurseDescendants(leafNode(str),s, vec);
        return vec;
    }

    TrieNode* E_Trie::ptrToLeafNode(string str) {

        TrieNode *node, *prevNode = root;
        for(auto& c : str) {
            node = prevNode->map.count(c) ? prevNode->map[c] : new TrieNode();
            prevNode->map[c] = node;
            prevNode = node;
        }

        return prevNode;
    }

    TrieNode *E_Trie::leafNode(string str) {
        TrieNode *node = root;
        for(auto& c : str) {
            node->map.count(c) ? node = node->map[c] : throw prefixNotFoundException;
        }
        return node;
    }

    bool E_Trie::exists(string str) {
        TrieNode* node = root;
        for(auto& c : str) {
            if(node->map.count(c)) {
                node = node->map[c];
            }else {
                return false;
            }
        }
        return true;
    }

    void E_Trie::remove(string str) {

    }
}