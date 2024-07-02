#ifndef BFS_ITERATOR_H
#define BFS_ITERATOR_H

#include "Node.hpp"
#include "BaseIterator.hpp"
#include <queue>

template<typename T, size_t k = 2>
class BFSIterator : public BaseIterator<T> {
private:
    std::queue<Node<T>*> queue;

public:
    explicit BFSIterator(Node<T>* root);

    BFSIterator<T, k>& operator++();
};

#include "BFSIterator.tpp"

#endif // BFS_ITERATOR_H
