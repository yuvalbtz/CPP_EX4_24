#include "DFSIterator.hpp"

template<typename T, size_t k>
DFSIterator<T, k>::DFSIterator(Node<T>* root) {
    if (root) {
        stack.push(root);  // Push the root node onto the stack
    }
    ++(*this);  // Move to the first element
}

template<typename T, size_t k>
DFSIterator<T, k>& DFSIterator<T, k>::operator++() {
    // If the stack is empty, the traversal is complete
    if (stack.empty()) {
        this->current = nullptr;  // Set current to nullptr indicating the end
        return *this;
    }

    // Pop the top node from the stack and set it as the current node
    this->current = stack.top();
    stack.pop();

    // Push all children of the current node onto the stack in reverse order
    const auto& children = this->current->get_children();
    for (int i = children.size() - 1; i >= 0; --i) {
        if (children[i]) {
            stack.push(children[i]);
        }
    }

    // Return the iterator itself
    return *this;
}

