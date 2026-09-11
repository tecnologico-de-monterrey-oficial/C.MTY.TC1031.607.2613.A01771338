//Elena María Barrios Jordan
//A01771338

#pragma once

template <typename T>
struct Node{
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T value) : data(value), next(nullptr) {} // este es el nodo final que apunta a un nulo
    Node(T value, std::unique_ptr<Node<T>> nextNode) : data(value), next(std::move(nextNode)) {} // este es el nodo que apunta a otro nodo
};

int main() {
     
    auto node1 = std::make_unique<Node<int>>(20); // nodo final
    auto node2 = std::make_unique<Node<int>>(10, std::move(node1)); // nodo que apunta a node1
}