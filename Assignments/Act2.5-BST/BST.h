#if !defined(BST_H)
#define BST_H

#include "NodeT.h"

template <typename T>
class BST {
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);

public:
    BST() : root(nullptr) {}
    void insert(T data);
    bool find(T data);
    void print();
};

template <typename T>
void BST<T>::insert(T data) {
    // si el árbol está vacío
    if (root == nullptr) {
        // el árbol está vacío
        // apuntamos root al nuevo nodo
        root = new NodeT<T>(data);
    } else {
        // el árbol no está vacío
        // creamos un apuntador aux igual a root
        NodeT<T>* aux = root;
        // creamos un apuntador father igual a root
        NodeT<T>* father = root;
        // itero en el árbol hasta encontrar donde voy a insertar el nodo
        while (aux != nullptr) {
            // valido si aux->data es igual a data
            if (aux->data == data) {
                // son iguales
                return;
            } else {
                // hacemos father igual a aux
                father = aux;
                // recorremos aux
                //if (data < aux->data ? aux = aux->left : aux = aux->right);  
                if (data < aux->data) {
                    aux = aux->left;
                } else {
                    aux = aux->right;
                }
            }
        }
        // inserto el nodo en el lado correspondiente
        if (data < father->data) {
            // el nodo va al lado izquierdo de father
            father->left = new NodeT<T>(data);
        } else {
            // el nodo va al lado derecho de father
            father->right = new NodeT<T>(data);
        }
    }
}

template <typename T>
bool BST<T>::find(T data) {
    // validamos que el árbol no este vacío
    if (root == nullptr) {
        // el árbol está vacío
        // retornamos false
        return false;
    } else {
        // el árbol no está vacío
        // creamos un apuntador aux igual a root
        NodeT<T>* aux = root;
        // itero en el árbol hasta encontrar el nodo a buscar o que no lo encuentre
        while (aux != nullptr) {
            // valido si aux->data es igual a data
            if (aux->data == data) {
                // son iguales, regreso true
                return true;
            } else {
                // recorremos aux
                //if (data < aux->data ? aux = aux->left : aux = aux->right);  
                if (data < aux->data) {
                    aux = aux->left;
                } else {
                    aux = aux->right;
                }
            }
        }
        // no se encontró el dato a buscar, regreso false
        return false;
    }
}

template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot) {
    if (node == nullptr) return;
    printTree(node->right, prefix + (isRoot ? "" : (isRight ? "      " : "|     ")), true, false);
    cout << prefix << (isRoot ? "" : (isRight ? ".---- " : "`---- ")) << node->data << endl;
    printTree(node->left,  prefix + (isRoot ? "" : (isRight ? "|     " : "      ")), false, false);
}

template <typename T>
void BST<T>::print() {
    if (root == nullptr) { 
        cout << "(arbol vacio)" << endl; 
        return; 
    }
    printTree(root, "", false, true);
}


#endif // BST_H