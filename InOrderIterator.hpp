#ifndef INORDER_ITERATOR_HPP
#define INORDER_ITERATOR_HPP

#include "Node.hpp"
#include "BaseIterator.hpp"
#include <stack>

template<typename T, size_t k = 2>
class InOrderIterator : public BaseIterator<T> {
private:
    std::stack<Node<T>*> stack;
    void pushLeftChildren(Node<T>* node);

public:
    explicit InOrderIterator(Node<T>* root);
    InOrderIterator<T, k>& operator++();
};

#include "InOrderIterator.tpp"

#endif // INORDER_ITERATOR_HPP
