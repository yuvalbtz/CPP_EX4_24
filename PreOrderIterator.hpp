#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

#include "Node.hpp"
#include "BaseIterator.hpp"
#include <stack>

template<typename T, size_t k = 2>
class PreOrderIterator : public BaseIterator<T> {
private:
    std::stack<Node<T>*> stack;

public:
    explicit PreOrderIterator(Node<T>* root);

    PreOrderIterator<T, k>& operator++();
};

#include "PreOrderIterator.tpp"

#endif // PREORDERITERATOR_H
