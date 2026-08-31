//Elena María Barrios Jordan
//A01771338
#include <iostream>
#include <vector>
using namespace std;


//Secuencial
template <typename T>
int secuencial(vector<T> &list, T data) {
    int i = 0;
    while (i < list.size()) {
        if (list[i] == data) {
            return i;
        }
        i++;
    }
    return -1;
}

//Binary search
template <typename T>
int binarySearch(vector<T> &list, T data) {
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (list[mid] == data) {
            return mid;
        } else if (list[mid] < data) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {

    vector<int> i = {3,5,6,8,11,12,13,16,27,35};



  
}




int left = 0;
int right = n + 1;
int mid = (right + left) / 2;

int binaryResearch (left = 0, left < right, mid = (right + left) / 2) {
    if (list[mid] == data) {
        return mid;
    } else if (list[mid] < data) {
        return binaryResearch(left = mid + 1, right, data);
    } else {
        return binaryResearch(left, right = mid - 1, data);
    }
}
