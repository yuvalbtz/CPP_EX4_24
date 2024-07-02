#ifndef POST_ORDER_ITERATOR_H
#define POST_ORDER_ITERATOR_H

#include "Node.hpp"
#include "BaseIterator.hpp"
#include <stack>

template<typename T, size_t k = 2>
class PostOrderIterator : public BaseIterator<T> {
private:
    std::stack<Node<T>*> stack1;
    std::stack<Node<T>*> stack2;

public:
    explicit PostOrderIterator(Node<T> *root);

    PostOrderIterator<T, k>& operator++();
};

#include "PostOrderIterator.tpp"

#endif // POST_ORDER_ITERATOR_H
