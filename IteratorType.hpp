#ifndef CPP_EX4_ITERATORTYPE_H
#define CPP_EX4_ITERATORTYPE_H

#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"
#include "InOrderIterator.hpp"
#include "DFSIterator.hpp"

//Type Traits
//Default Template
template<typename T, size_t k>
struct IteratorType {
    using PreOrder = DFSIterator<T, k>;
    using PostOrder = DFSIterator<T, k>;
    using InOrder = DFSIterator<T, k>;
};

//Specialized Template
template<typename T>
struct IteratorType<T, 2> {
    using PreOrder = PreOrderIterator<T, 2>;
    using PostOrder = PostOrderIterator<T, 2>;
    using InOrder = InOrderIterator<T, 2>;
};

#endif //CPP_EX4_ITERATORTYPE_H
