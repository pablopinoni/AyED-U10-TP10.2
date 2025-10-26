#include <iostream>
#include "array_dinamico.h"



//Funcion leer datos array
void leerDatosArray(int* arr, int N){

for (int i = 0; i < N; i++)
{
   std::cout << "Ingrese el valor para la posicion [" << i << "]: ";
        
        // LÍNEA CLAVE: Lectura y asignación a la posición de puntero
    std::cin >> *(arr + i); 
}




}

//Funcion ordenar elementos del array
// array_dinamico.cpp

void selectionSort(int* arr, int size) {
    int i, j;
    int *min_ptr; // Puntero para rastrear la direccion del elemento minimo.
    
    // 1. Bucle Externo (i): Recorre hasta el penultimo elemento
    for (i = 0; i < size - 1; i++) {
        
        // Inicializar el puntero del mínimo a la posicion actual (arr + i)
        min_ptr = arr + i; 

        // 2. Bucle Interno (j): Busca el minimo en la sub-lista no ordenada
        for (j = i + 1; j < size; j++) {
            
            // Compara el VALOR actual *(arr + j) 
            // con el VALOR del minimo actual *(min_ptr)
            if ( *(arr + j) < *(min_ptr)) {
                min_ptr = arr +j;
                // Si es menor, actualiza min_ptr para que apunte a la nueva direccion (arr + j)

                // Asignacion de puntero AQUI
            }
        }

        // 3. Intercambio: Solo si el minimo encontrado no es la posicion original (arr + i)
        if (min_ptr != (arr + i)) {
            //Guardamos el valor de la posicion 1
            int aux = *(arr + i); 
            // 2. Asignar el VALOR de *(min_ptr) a la posición *(arr + i)
            *(arr + i) = *(min_ptr); 

            // 3. Asignar el VALOR guardado en aux al puntero *(min_ptr)
            *(min_ptr) = aux; 
        }
    }
}