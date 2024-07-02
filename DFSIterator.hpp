#ifndef DFS_ITERATOR_H
#define DFS_ITERATOR_H

#include <stack>
#include "BaseIterator.hpp"
#include "Node.hpp"

template<typename T, size_t k = 2>
class DFSIterator : public BaseIterator<T> {
private:
    std::stack<Node<T>*> stack;

public:
    explicit DFSIterator(Node<T>* root);

    DFSIterator<T, k>& operator++();
};

#include "DFSIterator.tpp"

#endif // DFS_ITERATOR_H
