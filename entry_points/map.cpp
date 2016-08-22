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
