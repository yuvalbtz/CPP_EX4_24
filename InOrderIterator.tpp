#include "InOrderIterator.hpp"

template<typename T, size_t k>
void InOrderIterator<T, k>::pushLeftChildren(Node<T>* node) { // Push all left children of a node onto the stack
    while (node) {
        stack.push(node);
        node = (node->get_children().size() > 0) ? node->get_children()[0] : nullptr;
    }
}

template<typename T, size_t k>
InOrderIterator<T, k>::InOrderIterator(Node<T>* root) {
     if (root) {
            pushLeftChildren(root);
        }
        ++(*this);  // Move to the first element
}

template<typename T, size_t k>
InOrderIterator<T, k>& InOrderIterator<T, k>::operator++() {
    // If the stack is empty, the traversal is complete
        if (stack.empty()) {
            this->current = nullptr;  // Set current to nullptr indicating the end
            return *this;
        }

        // Pop the top node from the stack and set it as the current node
        this->current = stack.top();
        stack.pop();

        // Check if the current node has a right child
        Node<T> *node = (this->current->get_children().size() > 1) ? this->current->get_children()[1] : nullptr;

        // If there is a right child, push its left children onto the stack
        pushLeftChildren(node);

        // Return the iterator itself
        return *this;
}



