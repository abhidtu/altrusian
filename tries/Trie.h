//
// Created by linux on 7/2/16.
//

#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

using namespace std;

namespace altrusian {

    class Trie {

    protected:
        int NumNodes = 0;

    public:
        virtual void insert(string str) = 0;
        virtual void insert(string str, string value) = 0;
        virtual string search(string word) = 0;
        virtual vector<string> descendants(string word) = 0;
        virtual bool exists(string str) = 0;
        virtual void remove(string str) = 0;
    };

}

#endif //TRIE_H