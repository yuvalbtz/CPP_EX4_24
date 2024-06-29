#ifndef POST_ORDER_ITERATOR_H
#define POST_ORDER_ITERATOR_H

#include "Node.hpp"
#include <stack>

using namespace std;

/**
 * PostOrderIterator manner:
 *  
 * left ->  right -> value  
 */    

template<typename T, size_t k = 2>
class PostOrderIterator : public BaseIterator<T> {
private:
    stack<Node<T>*> stack1;   // Stack to manage the nodes for traversal (processing)
    stack<Node<T>*> stack2;   // Stack to store the nodes in post-order

public:
    explicit PostOrderIterator(Node<T> *root) {
        if (root) {
            stack1.push(root);  // Push the root node onto stack1

            // Process all nodes and push them to stack2 in post-order
            while (!stack1.empty()) {
                Node<T>* node = stack1.top();  // Get the node on top of stack1
                stack1.pop();  // Remove the node from stack1
                stack2.push(node);  // Push the node onto stack2

                // Push all children of the node onto stack1
                for (auto child : node->get_children()) {
                    if (child) {
                        stack1.push(child);
                    }
                }
            }
        }
        ++(*this);  // Move to the first element in stack2
    }

    PostOrderIterator<T, k>& operator++() {
        if (stack2.empty()) {
            this->current = nullptr;  // If empty, set current to nullptr (end of traversal)
            return *this;
        }
        this->current = stack2.top();  // Set current to the top node of stack2
        stack2.pop();
        return *this;
    }
};

#endif // POST_ORDER_ITERATOR_H
