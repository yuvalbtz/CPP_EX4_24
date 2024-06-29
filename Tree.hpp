#ifndef TREE_H
#define TREE_H

#include "Node.hpp"
#include "Complex.hpp"
#include "BFSIterator.hpp"
#include "DFSIterator.hpp"
#include "InOrderIterator.hpp"
#include "IteratorType.hpp"
#include "MinHeapIterator.hpp"
#include "PostOrderIterator.hpp"
#include "PreOrderIterator.hpp"
#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

// Utility function to convert different types to string
template<typename T>
string to_string(const T& value) {
    if constexpr (is_same_v<T, string>) {
        return value;
    } else if constexpr (is_same_v<T, Complex>) {
        return value.to_string_complex();
    } else {
        return to_string(value);
    }
}

template <typename T, size_t k = 2> 
class Tree {
private:
  Node<T> *root;

  void clear(Node<T> *node);
  Node<T> *find_node(Node<T> *node, T value);

public:
  Tree(); // Constructor with default arity
  ~Tree();

  void add_root(Node<T> &root_node);
  bool add_sub_node(Node<T> &parent_node, Node<T> &sub_node);

  // Iterator methods
  typename IteratorType<T, k>::PreOrder begin_pre_order();
  typename IteratorType<T, k>::PreOrder end_pre_order();

  typename IteratorType<T, k>::PostOrder begin_post_order();
  typename IteratorType<T, k>::PostOrder end_post_order();

  typename IteratorType<T, k>::InOrder begin_in_order();
  typename IteratorType<T, k>::InOrder end_in_order();

  BFSIterator<T, k> begin_bfs_scan();
  BFSIterator<T, k> end_bfs_scan();

  DFSIterator<T, k> begin_dfs();
  DFSIterator<T, k> end_dfs();

  BFSIterator<T, k> begin();
  BFSIterator<T, k> end();

  MinHeapIterator<T, k> begin_min_heap();
  MinHeapIterator<T, k> end_min_heap();
  MinHeapIterator<T, k> myHeap();
  
  void printTree();
};

#include "Tree.tpp" // Include the implementation file

#endif // TREE_H
