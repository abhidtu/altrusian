//
// Created by linux on 7/2/16.
//

#ifndef E_TRIE_H
#define E_TRIE_H

#include <vector>
#include <stack>
#include <string>
#include "../Trie.h"
#include "TrieNode.h"
#include "../Exceptions.h"

using namespace std;

namespace LibAlDs {

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
