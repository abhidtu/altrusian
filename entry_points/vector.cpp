// Created by linux on 13/1/16.

#include <iostream>
#include <vector>
#include <stdexcept>

#include "../trees/binary_search_trees/BinarySearchTreeNode.h"

using namespace std;
using namespace LibAlDs;

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
