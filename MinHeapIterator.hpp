#ifndef MIN_HEAP_ITERATOR_H
#define MIN_HEAP_ITERATOR_H

#include "Node.hpp"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T, size_t k = 2> 
class MinHeapIterator : public BaseIterator<T> {
private:
  vector<Node<T> *> heap; // Vector to store heap elements
  size_t index;                // Current index in the heap
  bool is_end;                 // Flag to indicate the end iterator

  // helper struct to compare the node value
  struct CompareNodes {
    bool operator()(Node<T> *a, Node<T> *b) const {
      return a->get_value() < b->get_value(); // Min-heap comparison
    }
  };

  // Helper function to traverse the tree and collect nodes
  void traverse(Node<T> *node);

public:
  // Constructor initializes the iterator with the root node
  explicit MinHeapIterator(Node<T> *root);

  // Pre-increment operator to advance the iterator
  MinHeapIterator<T, k> &operator++();

  // Dereference operator to access the current node
  Node<T> *operator*();

  // Arrow operator to access members of the current node
  Node<T> *operator->();

  // Inequality operator to compare iterators
  bool operator!=(const MinHeapIterator<T, k> &other) const;

  // Equality operator to compare iterators
  bool operator==(const MinHeapIterator<T, k> &other) const;
};

#include "MinHeapIterator.tpp" // Include the implementation file

#endif // MIN_HEAP_ITERATOR_H
