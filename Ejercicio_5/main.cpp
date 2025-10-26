/*Realice un programa que calcule la suma de dos
 matrices dinámicas.*/
#include <iostream>
#include "suma_matrices_din.h"
int main() {
    int filas_A, columnas_A;
    int filas_B, columnas_B;

    //Declaracion de punteros

    int** MatrizA = nullptr;
    int** MatrizB = nullptr;
    int** MatrizSuma = nullptr; 

    // Pedir dimensiones de la Matriz A
    std::cout << "--- Dimensiones de la Matriz A ---\n";
    std::cout << "Ingrese el numero de filas (A): ";
    std::cin >> filas_A;
    std::cout << "Ingrese el numero de columnas (A): ";
    std::cin >> columnas_A;

    // Pedir dimensiones de la Matriz B
    std::cout << "\n--- Dimensiones de la Matriz B ---\n";
    std::cout << "Ingrese el numero de filas (B): ";
    std::cin >> filas_B;
    std::cout << "Ingrese el numero de columnas (B): ";
    std::cin >> columnas_B;
    
    if (filas_A == filas_B && columnas_A == columnas_B)
    {

    // --- INICIO DE LLAMADAS CRÍTICAS ---
        
        // 1. ASIGNAR MEMORIA (A y B)
        MatrizA = asignarMemoria(filas_A, columnas_A); 
        MatrizB = asignarMemoria(filas_B, columnas_B);
        
        // 2. PEDIR DATOS (A y B)
        pedirDatos(MatrizA, columnas_A, filas_A, "Matriz A");
        pedirDatos(MatrizB, columnas_B, filas_B, "Matriz B");
        
        // 3. SUMAR MATRICES
        MatrizSuma = sumarMatrices(MatrizA, MatrizB, filas_A, columnas_A);

        // 4. MOSTRAR RESULTADOS
        mostrarMatriz(MatrizA, filas_A, columnas_A, "Matriz A");
        mostrarMatriz(MatrizB, filas_B, columnas_B, "Matriz B");
        mostrarMatriz(MatrizSuma, filas_A, columnas_A, "Matriz de SUMA");

    }
    else {

        std::cout << "No se pueden sumar matrices de distinto tamaño" << std::endl;
        return 1;   
    }
    // --- LIBERACIÓN DE MEMORIA CRÍTICA ---
    // ESTO SÓLO SE EJECUTA SI EL IF FUE EXITOSO.
    if (MatrizA != nullptr) {
        liberarMemoria(MatrizA, filas_A);
        liberarMemoria(MatrizB, filas_B);
        liberarMemoria(MatrizSuma, filas_A);
    }
return 0;
}

