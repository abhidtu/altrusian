// Created by linux on 13/1/16.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <map>

#include "../trees/binary_search_trees/BinarySearchTreeNode.h"

using namespace std;
using namespace LibAlDs;

int main() {

    std::unordered_map<string,string> map;
    map.emplace("hello","test");
    map.emplace("aabbcc1","teaast");
    map.emplace("aabbcc2","teaast");
    map.emplace("aabbcc3","teaast");
    map.emplace("aabbcc4","teaast");
    map.emplace("aabbcc5","teaast");
    map.emplace("aabbcc6","teaast");
    map.emplace("aabbcc7","teaast");
    map.emplace("aabbcc8","teaast");
    map.emplace("aabbcc9","teaast");
    map.emplace("aabbcc10","teaast");

    for (auto& x: map)
        std::cout << x.first << ": " << x.second << std::endl;

    std::cout << map["hello"] << std::endl;
    std::cout << "size = " << map.size() << std::endl;
    std::cout << "bucket_count = " << map.bucket_count() << std::endl;
    std::cout << "load_factor = " << map.load_factor() << std::endl;
    std::cout << "max_load_factor = " << map.max_load_factor() << std::endl;

    std::unordered_map<char,int> mymap;
    mymap.emplace('a',1);
    mymap.emplace('b',2);
    mymap['a'] = 20;
    mymap['b'] = 12;
    mymap['c'] = 11;

    for (auto& x: mymap)
        std::cout << x.first << ": " << x.second << std::endl;

    return 0;
}
