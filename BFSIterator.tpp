#include "BFSIterator.hpp"

template<typename T, size_t k>
BFSIterator<T, k>::BFSIterator(Node<T>* root) {
    if (root) {
        queue.push(root);  // Push the root node onto the queue
    }
    ++(*this);  // Move to the first element
}

template<typename T, size_t k>
BFSIterator<T, k>& BFSIterator<T, k>::operator++() {
    // If the queue is empty, the traversal is complete
    if (queue.empty()) {
        this->current = nullptr;  // Set current to nullptr indicating the end
        return *this;
    }

    // Dequeue the front node and set it as the current node
    this->current = queue.front();
    queue.pop();

    // Enqueue all the children of the current node
    const auto& children = this->current->get_children();
    for (auto child : children) {
        if (child) {
            queue.push(child);
        }
    }

    // Return the iterator itself
    return *this;
}

