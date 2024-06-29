#ifndef IN_ORDER_ITERATOR_H
#define IN_ORDER_ITERATOR_H

#include "Node.hpp"
#include <stack>

using namespace std;

/**
 * PostOrderIterator manner:
 *  
 * left -> value -> right  
 */    

template<typename T, size_t k = 2>
class InOrderIterator : public BaseIterator<T> {
private:
    stack<Node<T> *> stack;  // Stack to manage the nodes for traversal

    // Push all left children of a node onto the stack
    void pushLeftChildren(Node<T> *node) {
        while (node) {
            stack.push(node);
            node = (node->get_children().size() > 0) ? node->get_children()[0] : nullptr;
        }
    }

public:
    // Constructor initializes the iterator with the root node
    explicit InOrderIterator(Node<T> *root) {
        if (root) {
            pushLeftChildren(root);
        }
        ++(*this);  // Move to the first element
    }

    // Pre-increment operator to advance the iterator
    InOrderIterator<T, k>& operator++() {
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
};

#endif // IN_ORDER_ITERATOR_H
