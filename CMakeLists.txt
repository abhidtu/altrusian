cmake_minimum_required(VERSION 3.2)
project(c__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message("Boost libraries: ${Boost_LIBRARIES}")
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES  entry_points/heap.cpp)
add_executable(c__ ${SOURCE_FILES}
linked_lists/List.h
linked_lists/singly/SinglyLinkedList.cpp
linked_lists/singly/SinglyLinkedList.h
linked_lists/singly/SinglyLinkedListNode.h
linked_lists/doubly/DoublyLinkedListNode.h
linked_lists/doubly/DoublyLinkedList.cpp
linked_lists/doubly/DoublyLinkedList.h
trees/binary_search_trees/BinarySearchTreeNode.h
trees/binary_search_trees/unbalanced/SimpleBinarySearchTree.cpp
trees/binary_search_trees/unbalanced/SimpleBinarySearchTree.h
trees/Trees.h
trees/binary_search_trees/balanced/AVL_tree/AVL_Tree.cpp
trees/binary_search_trees/balanced/AVL_tree/AVL_Tree.h
trees/binary_search_trees/BinarySearchTree.cpp
trees/binary_search_trees/BinarySearchTree.h
trees/binary_search_trees/balanced/RedBlackTree/RedBlackTree.cpp
trees/binary_search_trees/balanced/RedBlackTree/RedBlackTree.h
heaps/Heap.h
heaps/d_ary_heap/D_ary_Heap.cpp
heaps/d_ary_heap/D_ary_Heap.h
util/Vector.cpp util/Vector.h
heaps/Exceptions.cpp heaps/Exceptions.h
heaps/d_ary_heap/max_heap/MaxHeap.cpp
heaps/d_ary_heap/max_heap/MaxHeap.h
heaps/d_ary_heap/min_heap/MinHeap.cpp
heaps/d_ary_heap/min_heap/MinHeap.h
linked_lists/LinkedList.cpp
linked_lists/LinkedList.h
tries/Trie.h
tries/elegant/E_Trie.cpp
tries/elegant/E_Trie.h
tries/elegant/TrieNode.h
tries/normal/N_Trie.cpp
tries/normal/N_Trie.h
tries/normal/TrieNode.h
tries/Exceptions.cpp
tries/Exceptions.h
graphs/adjacency_list/Adjacency_list.hpp
graphs/adjacency_list/GraphEdge.h
graphs/adjacency_matrix/Adjacency_matrix.hpp
graphs/Graph.hpp
graphs/adjacency_matrix/GraphEdge.h
graphs/adjacency_matrix/GraphNode.h
graphs/adjacency_matrix/directed/Directed.hpp
graphs/adjacency_matrix/undirected/UnDirected.hpp
graphs/adjacency_list/directed/Directed.hpp
graphs/adjacency_list/undirected/UnDirected.hpp
graphs/adjacency_list/GraphNode.h
graphs/Visitors.h)
target_link_libraries(c__ ${Boost_LIBRARIES})