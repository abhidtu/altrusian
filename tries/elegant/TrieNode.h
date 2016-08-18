//
// Created by linux on 7/2/16.
//

#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

namespace LibAlDs {

    class TrieNode {

    public:
        string value;
        std::unordered_map<char, TrieNode*> map;
        //TrieNode* map[256];
    };

}

#endif //TRIENODE_H