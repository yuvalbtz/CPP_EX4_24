#ifndef BASEITERATOR_H
#define BASEITERATOR_H

template<typename T>
class BaseIterator {
protected:
    Node<T>* current;

public:
    BaseIterator() : current(nullptr) {}
    Node<T>* operator*() { return current; }
    Node<T>* operator->() { return current; }
    bool operator!=(const BaseIterator<T>& other) const { return current != other.current; }
    bool operator==(const BaseIterator<T>& other) const { return current == other.current; }
};

#endif // BASEITERATOR_H
