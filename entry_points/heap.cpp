// Created by linux on 13/1/16.

#include <iostream>
#include <chrono>
#include "../heaps/d_ary_heap/D_ary_Heap.h"
#include "../heaps/d_ary_heap/max_heap/MaxHeap.h"
#include "../heaps/d_ary_heap/min_heap/MinHeap.h"

using namespace std;
using namespace std::chrono;

int main() {

    vector<int> vec;

    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(11);
    vec.push_back(16);
    vec.push_back(30);
    vec.push_back(7);


    LibAlDs::Heaps::D_Ary_Heap::MinHeap heap1(3,vec);

    LibAlDs::Heap *heap11 = &heap1;

    vector<int> vec2;

    vec2.push_back(35);
    vec2.push_back(37);
    vec2.push_back(30);
    vec2.push_back(34);
    vec2.push_back(19);
    vec2.push_back(21);
    vec2.push_back(38);
    vec2.push_back(18);
    vec2.push_back(16);
    vec2.push_back(40);
    vec2.push_back(20);
    vec2.push_back(7);
    vec2.push_back(45);


    LibAlDs::Heaps::D_Ary_Heap::MinHeap heap2(3,vec2);

    LibAlDs::Heap *heap22 = &heap2;

    cout << heap11->max() << "\n";

    LibAlDs::Heap *h = LibAlDs::Heaps::D_Ary_Heap::MinHeap::mergeHeaps(heap11,heap22,3);
    cout << h->max() << "\n";

    //heap22->insert(100);

    //heap11->update(12,100);
/*
    vector<int> vec3;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for(int i=0;i<50000000;i++) {
        vec3.push_back(i);
    }


    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout <<"rand execution time -" << duration<<"\n";

    high_resolution_clock::time_point t11 = high_resolution_clock::now();


    LibAlDs::D_AryHeap heap3(3,vec3);

    high_resolution_clock::time_point t22 = high_resolution_clock::now();

    auto duration1 = duration_cast<milliseconds>( t22 - t11 ).count();

    cout <<"heap execution time -" << duration1<<"\n";

    LibAlDs::Heap *maxHeaps3 = &heap3;
*/

    return 0;
}