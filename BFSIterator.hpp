#ifndef BFS_ITERATOR_H
#define BFS_ITERATOR_H

#include "Node.hpp"
#include "BaseIterator.hpp"
#include <queue>

using namespace std;

template<typename T, size_t k = 2>
class BFSIterator : public BaseIterator<T> {
private:
    queue<Node<T>*> queue;

public:
    explicit BFSIterator(Node<T>* root) {
        if (root) {
            queue.push(root);  // Push the root node onto the queue
        }
        ++(*this);  // Move to the first element
    }

    BFSIterator<T, k>& operator++() {
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
};



#endif // BFS_ITERATOR_H
