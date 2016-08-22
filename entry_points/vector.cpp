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

#include "../trees/binary_search_trees/BinarySearchTreeNode.h"

using namespace std;
using namespace altrusian;

int main() {

    vector<int> vec;

    int i;

    // push 5 values into the vector
    for(i = 0; i < 5; i++){
        vec.push_back(i);
    }

    // display the original size of vec
    cout << "vector size = " << vec.size() << endl;
    cout << "vector capacity = " << vec.capacity() << endl;
    //cout << "vector v = " << vec[100] << endl;

    for(auto& elem : vec){
        //cout << "elem is = "<< &elem-&vec[0] <<"\n";
    }
    for(auto i=vec.begin(); i!=vec.end(); ++i){
        std::cout<<(*i)<<std::endl;
    }
    vector<vector<int>> vector2;

    for(int j=0;j<15;j++){
        vector<int> v;
        for(int p=0;p<5;p++){
            v.push_back(p+j);
        }
        vector2.push_back(v);
    }


    return 0;
}
