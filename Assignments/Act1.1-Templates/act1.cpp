#include <iostream>
using namespace std;

//int sum(int a, int b) {
//    return a + b;
//}
//double sum(double a, double b) {
//    return a + b;
//}

//string sum(string a, string b) {
//    return a + b;
//}

int main() {

    int a= 5;
    int b=10;
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl;

    double c= 22.5;
    double d= 17.5;
    cout << "Sum of" << c << " and " << d << " is: " << sum(c, d) << endl;

    string e= "Hello ";
    string f= "World!";
    cout << "Sum of" << e << " and " << f << " is: " << sum(e, f) << endl;

    List<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    List<string> things;
    things.insert("Laptop");
    things.insert("bottle")

    return 0;
}

template <typename T>
T sum(T a, T b) {
    return a + b;
}