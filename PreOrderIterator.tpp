#include "PreOrderIterator.hpp"

template<typename T, size_t k>
PreOrderIterator<T, k>::PreOrderIterator(Node<T>* root) {
    if (root) {
        stack.push(root);
    }
    ++(*this);  // Move to the first element
}

template<typename T, size_t k>
PreOrderIterator<T, k>& PreOrderIterator<T, k>::operator++() {
    if (stack.empty()) {
        this->current = nullptr;
        return *this;
    }
    this->current = stack.top();
    stack.pop();

    const auto& children = this->current->get_children();
    for (int i = children.size() - 1; i >= 0; --i) {
        if (children[i]) {
            stack.push(children[i]);
        }
    }
    return *this;
}

