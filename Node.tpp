#include "Node.hpp"

template <typename T>
Node<T>::Node(T val, size_t k) : value(val), k(k), children(k, nullptr) {}

// Getters
template <typename T>
T Node<T>::get_value() const {
    return value;
}

template <typename T>
size_t Node<T>::get_k() const {
    return k;
}

template <typename T>
 std::vector<Node<T>*>& Node<T>::get_children()  {
    return children;
}

// Setters
template <typename T>
void Node<T>::set_value(T val) {
    value = val;
}

template <typename T>
void Node<T>::set_k(size_t k) {
    this->k = k;
    children.resize(k, nullptr); // Resize the children vector to match the new k
}

template <typename T>
void Node<T>::set_children(const std::vector<Node<T>*>& children) {
    this->children = children;
}
