#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <vector>

using namespace std;

template <typename T> 

class Node {
private:
    T value;
    size_t k; // Number of children
    vector<Node<T>*> children;

public:
    explicit Node(T val, size_t k = 2);

    // Getters
    T get_value() const;
    size_t get_k() const;
     vector<Node<T>*>& get_children() ;

    // Setters
    void set_value(T val);
    void set_k(size_t k);
    void set_children(const vector<Node<T>*>& children);
   
};

#include "Node.tpp" // Include the implementation file

#endif // NODE_H
