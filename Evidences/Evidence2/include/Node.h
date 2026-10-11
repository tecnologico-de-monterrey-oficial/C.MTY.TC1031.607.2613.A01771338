#ifndef NODE_H
#define NODE_H


template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}
    Node(const T& value, Node<T>* nextNode) : data(value), next(nextNode) {}
};

template <typename T>
struct NodeD {
    T data;
    NodeD<T>* next;
    NodeD<T>* prev;

    NodeD(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    NodeD(const T& value, NodeD<T>* nextNode, NodeD<T>* prevNode)
        : data(value), next(nextNode), prev(prevNode) {}
};

#endif