#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

#include <stack>
#include "BaseIterator.hpp"
#include "Node.hpp"


/**
 * PreOrderIterator manner:
 *  
 * value ->  left -> right  
 */    



template<typename T, size_t k>
class PreOrderIterator : public BaseIterator<T> {
private:
    std::stack<Node<T>*> stack;

public:
   explicit PreOrderIterator(Node<T>* root) {
        if (root) {
            stack.push(root);  // Push the root node onto the stack
        }
        ++(*this);  // Move to the first element
    }

    PreOrderIterator<T, k>& operator++() {
        if (stack.empty()) {  // Check if the stack is empty
            this->current = nullptr;  // If empty, set current to nullptr (end of traversal)
            return *this;
        }
        this->current = stack.top();  // Set current to the node on top of the stack
        stack.pop();

        // Push children of the current node to the stack in reverse order
        const auto& children = this->current->get_children();
        for (int i = children.size() - 1; i >= 0; --i) {
            // Push each non-null child onto the stack
            if (children[i]) {
                stack.push(children[i]);
            }
        }
        return *this;  // Return the iterator
    }
};

#endif // PREORDERITERATOR_H
