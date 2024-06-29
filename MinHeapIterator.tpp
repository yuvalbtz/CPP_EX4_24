#include "MinHeapIterator.hpp"
#include <algorithm>

using namespace std;

// Helper function to traverse the tree and collect nodes
template<typename T, size_t k>
void MinHeapIterator<T, k>::traverse(Node<T> *node) {
    if (!node) return;

    priority_queue<Node<T>*, vector<Node<T>*>, CompareNodes> minHeap;
    minHeap.push(node); // Push the root node

    while (!minHeap.empty()) {
        Node<T>* current = minHeap.top();
        minHeap.pop();
        heap.push_back(current); // Collect the node

        for (auto child : current->get_children()) {
            if (child) {
                minHeap.push(child); // Push children to the heap
            }
        }
    }

    // Directly sort the collected nodes in ascending order
    sort(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) {
        return a->get_value() < b->get_value();
    });

}

// Constructor initializes the iterator with the root node
template<typename T, size_t k>
MinHeapIterator<T, k>::MinHeapIterator(Node<T> *root) : index(0) , is_end(false) {
    if (root)
        traverse(root); // Collect all nodes from the tree
    else
        is_end = true;
}

// Pre-increment operator to advance the iterator
template<typename T, size_t k>
MinHeapIterator<T, k> &MinHeapIterator<T, k>::operator++() {
    if (index < heap.size() - 1)
        ++index;
    else
        is_end = true; // Mark end of iteration

    return *this;
}

// Dereference operator to access the current node
template<typename T, size_t k>
Node<T> *MinHeapIterator<T, k>::operator*() {
    if ( !is_end && index < heap.size()) {
        return heap[index];
    }
    return nullptr;
}

// Arrow operator to access members of the current node
template<typename T, size_t k>
Node<T> *MinHeapIterator<T, k>::operator->() {
    return operator*();
}

// Inequality operator to compare iterators
template<typename T, size_t k>
bool MinHeapIterator<T, k>::operator!=(const MinHeapIterator<T, k> &other) const {
    if (is_end || other.is_end)
        return is_end != other.is_end;
    else
        return index != other.index;
}

// Equality operator to compare iterators
template<typename T, size_t k>
bool MinHeapIterator<T, k>::operator==(const MinHeapIterator<T, k> &other) const {
    if (is_end || other.is_end)
        return is_end == other.is_end;
    else
        return index == other.index;
}