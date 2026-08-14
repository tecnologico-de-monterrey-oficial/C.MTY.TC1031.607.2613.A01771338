#indef LIST_h
#define LIST_h

#include <iostream>
#include <vector>

using namespace std

template <typename T>
class List {
    private:
        vector<T> list;
        int size;
    public:
        List();
        void insert(T data);
};

template <typename T>
List<T>::List() {
    size = 0;
}

template <typename T>
void insert(T data) {
    list.push_back(data);
    size++;
}




 #endif /*List_h*/