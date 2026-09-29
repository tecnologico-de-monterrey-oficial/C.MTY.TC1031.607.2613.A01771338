#include "Node.h"
using namespace std;
#include <iostream>


template <typename T>
class Queue {
private: 

    Node<T>* head; 
    Node<T>* tail;

public:
    queue(){
        head = nullptr;
        tail = nullptr;
    }
    
    void pop();
    void push(T data);
    void front(T data);
    void print();
}

template <typename T>
void Queue<T>::pop(){

    if(head !=nullptr){

        if (head == tail ){
            Node<T>* aux = head;
            delete aux;
            head = nullptr;
            tail = nullptr;
        
        } else{

            Node<T>* aux = head;
            head = head -> next;
            delete aux;
        }

    }
};


template <typename T>
void Queue<T>::push(T data){
    if(head !=nullptr){
        tail ->next = new Node<T>(data);
        tail = tail->next;

    }



}





