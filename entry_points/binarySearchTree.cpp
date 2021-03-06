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
#include <chrono>
using namespace std;
using namespace std::chrono;
#include "../trees/binary_search_trees/unbalanced/SimpleBinarySearchTree.h"
#include "../trees/binary_search_trees/balanced/AVL_tree/AVL_Tree.h"

int main() {

    altrusian::AVL_Tree tree;
    //LibAlDs::Trees *trees = new LibAlDs::SimpleBinarySearchTree();
    altrusian::Trees *trees = &tree;
    /*
    trees->insert(15);
    trees->insert(10);
    trees->insert(20);
    trees->insert(5);
    trees->insert(13);
    trees->insert(3);
    trees->insert(7);
    trees->insert(2);
    trees->insert(4);
    trees->insert(6);
    trees->insert(9);
    trees->insert(12);
    trees->insert(11);
    trees->insert(14);
    trees->insert(17);
    trees->insert(16);
    trees->insert(19);
    trees->insert(18);
    trees->insert(25);
    trees->insert(23);
    trees->insert(22);
    trees->insert(24);
    trees->insert(30);
    trees->insert(27);
    trees->insert(33);
    trees->insert(28);

    //trees->remove(19);
    //trees->remove(23);
    trees->remove(25);

    trees->size();
*/
    trees->insert(2);
    trees->insert(10);
    trees->insert(1);
    trees->insert(5);
    trees->insert(7);
    trees->insert(9);
    trees->insert(12);
    trees->insert(8);
    trees->insert(3);
    trees->insert(4);
    trees->insert(6);
    trees->insert(17);
    trees->insert(11);
    trees->insert(18);



/*
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for(int i = 1;i<=100000;i++){
        trees->insert(i);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout <<"execution time -" << duration<<"\n";
*/

    trees->remove(18);
    trees->remove(17);
    trees->remove(11);
    trees->remove(12);
    trees->remove(10);
    trees->remove(8);
    trees->remove(9);
    trees->remove(4);
    trees->remove(7);
    trees->remove(6);
    trees->remove(2);

    cout << "size = " << trees->size();
    cout << "find = " << trees->find(17);

    return 0;
}