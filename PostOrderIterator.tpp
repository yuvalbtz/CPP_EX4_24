#include "PostOrderIterator.hpp"

template<typename T, size_t k>
PostOrderIterator<T, k>::PostOrderIterator(Node<T> *root) {
    if (root) {
        stack1.push(root);

        while (!stack1.empty()) {
            Node<T>* node = stack1.top();
            stack1.pop();
            stack2.push(node);

            for (auto child : node->get_children()) {
                if (child) {
                    stack1.push(child);
                }
            }
        }
    }
    ++(*this);
}

template<typename T, size_t k>
PostOrderIterator<T, k>& PostOrderIterator<T, k>::operator++() {
    if (stack2.empty()) {
        this->current = nullptr;
        return *this;
    }
    this->current = stack2.top();
    stack2.pop();
    return *this;
}

