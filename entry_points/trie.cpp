// Created by linux on 13/1/16.

#include <iostream>

#include "../trees/binary_search_trees/BinarySearchTreeNode.h"
#include "../tries/Trie.h"
#include "../tries/normal/N_Trie.h"

using namespace std;
using namespace LibAlDs;

int main() {

    LibAlDs::N_Trie n_trie;
    LibAlDs::Trie *trie = &n_trie;
    trie->insert("abate","subside or moderate");
    trie->insert("aberrant","abnormal or deviant");
    trie->insert("abeyance","suspended action");
    trie->insert("abscond","depart secretly and hide");
    trie->insert("abstemious","sparing in eating and drinking");
    trie->insert("admonish","warn");
    trie->insert("adultrate","make impure by adding inferior or tainted substances");
    trie->insert("aesthetic","artistic; dealing with or capable of appreciating the beautiful");
    trie->insert("banal","hackneyed; commonplace; trite; lacking originality");
    trie->insert("belie","contradict; give a false impression");
    trie->insert("beneficent","kindly; doing good");
    trie->insert("bolster","support; reinforce");
    trie->insert("bombastic","pompous; using inflated language");
    trie->insert("boorish","rude; insensitive");
    trie->insert("cacophonous","discordant; inharmonious");
    trie->insert("capricious","unpredictable; fickle");
    trie->insert("catalyst","agent that stimulates or precipitates a reaction, development, or change");
    trie->insert("caustic","burning; sarcastically biting");
    trie->insert("chicanery","trickery; deception");
    trie->insert("default","failure to act");
    trie->insert("deference","courteous regard for another's wish");
    trie->insert("delineate","portray; depict; sketch");
    trie->insert("deride","ridicule; make fun of");
    trie->insert("derivative","unoriginal; obtained from another source");

    vector<string> vec = trie->descendants("a");

    std::cout << "descendants \n\n";
    for(auto& val : vec) {
        cout << val << "\n";
    }

try {
        std::string s = trie->search("abate");
        std::cout << s;
    }catch(LibAlDs::Tries::PrefixNotFoundException e) {
        cout << e.what();
    }

    trie->remove("abate");

    vector<string> vec2 = trie->descendants("a");

    std::cout << "descendants \n\n";
    for(auto& val : vec2) {
        cout << val << "\n";
    }

    return 0;
}
