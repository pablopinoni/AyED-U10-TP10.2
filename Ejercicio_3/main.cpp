#include <iostream>
#include "array_dinamico.h"
using namespace std;




int main(){
 

   int N; //Declaramos variable para tamaño array
   cout << "Ingresá la cantidad de núeros que contendrá el arreglo: \n";
   cin >> N;
   
   int* ptr_dinamico; //Creamos ptr 
   ptr_dinamico =  new int[N]; // Asignacion dinámica

    if (ptr_dinamico==nullptr)
    {
        cerr << "No se pudo asignar memoria." << endl;
        return 1;
    }
    

//Declaración e iniccialización de punteros a función

void (*pfn_ordenar)(int*, int);
pfn_ordenar= selectionSort;

void (*pfn_leer)(int*, int);
pfn_leer = leerDatosArray; 
//llamada a las funciones a través de ptr_func
pfn_leer(ptr_dinamico, N); // Llama a leerDatosArray
pfn_ordenar(ptr_dinamico, N); // Llama a selectionSort

//Impresión
cout << "\n--- Array Ordenado Ascendentemente ---\n";

// Bucle para imprimir el array ordenado
for (int i = 0; i < N; ++i) {
    // Imprime el valor en la posicion i
    cout << ptr_dinamico[i] << " "; 
}
cout << endl;

delete[]ptr_dinamico;
 ptr_dinamico = nullptr;
  return 0;
}