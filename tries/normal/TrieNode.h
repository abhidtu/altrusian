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
        TrieNode* hash[256] = {};
        int childNodes = 0;
    };

}

#endif //TRIENODE_H
