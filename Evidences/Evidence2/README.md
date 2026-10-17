# Evidencia 2 - Actividad Integral de Estructuras de Datos Lineales
//Elena María Barrios Jordan  
// A01771338  
//Estructuras de Datos Lineales  
//Profesor: David Alonso Cantú

## Descripción
Este programa procesa un archivo de logs, a diferencia de mi primera evidencia que pude simplificar usando vectores en esta ocación, no se utilizan arreglos ni vectores ordenar los datos. En su lugar, se implementaron estructuras de datos lineales para realizarla, se ocuparon estructuras como:
//Fila (Queue): Utilizada como buffer de lectura. Las líneas del archivo de texto entran y salen en orden de llegada utilizando la estructura FIFO para ser procesadas y validadas.
//DoublyLinkedList: Que es como lo más importante de nuestro código porque funciona como el almacén principal del programa,cada nodo guarda un registro (fecha, hora, IP, mensaje). Se ordenan los datos y se realizan las búsquedas
//Pila (Stack): Utilizada para invertir el orden de los registros de un día específico y mostrarlos de más reciente a más antiguo utilizando la estructura LIFO

Para el ordenamiento de los registros dentro de la Lista Doblemente Ligada, se implementó el algoritmo Merge Sort. Lo elegí por su estabilidad conservando el orden de llegada de registros con la misma fecha y hora y porque garantiza un tiempo de ejecución predecible de (O(n log n)) en el peor de los casos

### Estructura del proyecto
El proyecto está organizado en las siguientes carpetas:
- data/: Contiene los archivos de entrada
- include/: Contiene los archivos (.h) de las estructuras (Node, LinkedList, Queue, Stack, DoublyLinkedList, Log).
- src/: Contiene el código fuente principal (main_logs.cpp y Log.cpp)
- out/: Aquí se genera el archivo de salida ordenado (output608.out)
- docs/: Contiene el documento de evidencia Evidencia2.pdf


## Instrucciones de Compilación y Ejecución
1. Abre la terminal.
2. Compila el programa con el siguiente comando:

g++ -std=c++17 src/main_logs.cpp src/Log.cpp -I include -o logs && ./logs

## VIDEO
https://youtu.be/Kqz8zexCS7U