//Elena María Barrios Jordan
//A01771338

#include <iostream>
using namespace std;

int factorial(int n){
    if (n <= 1){    //Caso Base
        return 1;
    }
    return n * factorial(n-1);
}

int sumIterative(int n){
    int suma = 0;
    for(int i=1; i<= n ; i++){ //Caso Base
        suma +=i;
    }
    return suma;
}

int sumRecursive(int n){
    if(n == 1){
        return 1;
    }
    return n + sumRecursive(n-1);
}

int sumFormula(int n) {
    return n*(n+1)/2;
}

int fibonacciIterative(int n) {
    int a = 1;
    int b = 1;
    int c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursive(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int bacteriasIterative(int n) {
    double Born = 3.78;
    double Dead = 2.34;
    
    int sum = 1; 
    for (int i= 1; i <= n; i++) {
        int bac;
        int bacBorn = sum * Dead;
        int bacDead = sum * Born;
        sum += bacBorn - bacDead;
        
    }
    return sum;
}

int bacteriaRecursive(int n) {
    if (n == 0) {
        return 1;
    }
    int bacteria = bacteriaRecursive(n - 1);
    return bacteria * 3.78;
    return bacteria * 2.34;

}

double investmentIterative(int mes, double cantidad){
    double interes = 0.1875;

    for (int i=1; i<=mes ; i++){
    double cantidad = cantidad * interes;
    }

    return cantidad;
}

double investmentRecursive(int mes, double cantidad){
    if (mes == 0) return cantidad;
    return investmentRecursive(cantidad * 0.1875, mes - 1);
}





int powIterative(int base, int exponente){
    int result = 1;
    for (int i = 0; i < exponente ; i++) {
        result *= 2;
    }
    return result;
}

int powRecursive(int base, int exponente){
    if (exponente==0) return 1;
   return base * powRecursive(base, exponente -1);
   
}



int main(){

    //Factorial
    cout << "El factorial de 5 es: " << factorial(5) <<endl;
    //Suma Iterativa
    cout << "La suma iterativa 5 es: " << sumIterative(5) <<endl;

    //Suma recursiva
    cout << "LA Suma Recursiva de 5 es: " << sumRecursive(5) <<endl;
    
    //Suma Con fórmula
    cout << "La Suma usando la fórmula es:" << sumFormula(7) <<endl;

    //Fibonacci con interativo
    cout << "La Suma de fibonacci usando el iterativo es:" << fibonacciIterative(8) <<endl;
    
    //Fibonacci con recursivo
    cout << "La Suma de fibonacci usando el iterativo es:" << fibonacciRecursive(8) <<endl;

    //Bacterias Iterativo
    cout << "Bacterias día 3: " << bacteriasIterative(3) << endl;
    
    //Bacterias recursivo
    cout << "Bacterias día 3: " << bacteriaRecursive(3) << endl;
    //Investment iterativo
    cout << "50 pesoss en 5 meses: " << investmentIterative(50, 5) << endl;
    
    //Investment recursivo
    cout << "50 pesoss en 5 meses: " << investmentRecursive(50, 5) << endl;
    //power iterativo
    cout << "3 elevado a 4: " << powIterative(2, 3) << endl;
    
    //power recursivo
    cout << "3 elevado a 4: " << powRecursive(2, 3) << endl;

    return 0;
}


