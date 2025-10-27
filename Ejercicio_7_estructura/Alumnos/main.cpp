#include <iostream>
#include <cstdlib>
#include "estructura_alumnos.h" // Contiene las definiciones dinámicas

using namespace std;

int main() {
    
    // 1. Declaración estática (stack) de la estructura contenedora.
    // Esta estructura SOLO contiene el puntero base (p_tAlumno) y el contador.
    tListaAlumnos lista; 
    
    // 2. Puntero que almacenará la dirección de memoria del mejor alumno encontrado.
    // CRÍTICO: Ahora es un puntero (tAlumno*)
    tAlumno* p_mejorAlumno = nullptr; 

    cout << "--- Ejercicio de Alumnos (Version Dinamica con Punteros) ---" << endl;

    // 3. Pedir datos: La función es llamada con la dirección de 'lista' (&lista).
    // La función internamente ASIGNA la memoria con 'new[]'.
    pedirDatos(&lista); 

    // 4. Comprobar y obtener el mejor alumno. 
    // La función retorna un PUNTERO a la estructura del mejor alumno.
    p_mejorAlumno = encontrarMejorPromedio(&lista); 

    // 5. Imprimir los datos del mejor alumno (se usa el puntero retornado).
    if (p_mejorAlumno != nullptr) {
        // Se llama a la función de impresión con el puntero.
        imprimirDatos(p_mejorAlumno); 
    } else {
        cerr << "Error: No se pudo encontrar el mejor alumno." << endl;
    }

    // 6. Liberación de memoria CRÍTICA
    // Se llama a la función que usa 'delete[]' para liberar el bloque dinámico.
    liberarMemoria(&lista); 

    return EXIT_SUCCESS;
}