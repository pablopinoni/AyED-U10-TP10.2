/* Realice un programa que lea una matriz dinámica de NxM y cree su matriz
traspuesta. La matriz traspuesta es aquella en la que la columna i era la fila i de la
matriz original.
AT[j][i]=A[i][j] */
#include <iostream>
#include <string>
#include "matrices_utils.h" 

int main() {
    int filas, columnas;
    int** MatrizOriginal = nullptr;
    int** MatrizTraspuesta = nullptr;

    // 1. Pedir Dimensiones de la Matriz Original (N x M)
    std::cout << "--- Ejercicio: Matriz Traspuesta ---\n";
    std::cout << "Ingrese el numero de filas (N): ";
    std::cin >> filas;
    std::cout << "Ingrese el numero de columnas (M): ";
    std::cin >> columnas;

    if (filas <= 0 || columnas <= 0) {
        std::cerr << "Error: Las dimensiones deben ser positivas.\n";
        return 1;
    }

    // --- FLUJO CRÍTICO ---

    // 2. Asignar Memoria y Pedir Datos
    MatrizOriginal = asignarMemoria(filas, columnas); 
    pedirDatos(MatrizOriginal, columnas, filas, "Matriz Original A");
    
    // 3. Obtener la Traspuesta
    MatrizTraspuesta = obtenerTraspuesta(MatrizOriginal, filas, columnas);

    // 4. Mostrar Resultados
    mostrarMatriz(MatrizOriginal, filas, columnas, "Matriz Original (N x M)");
    
    // Al mostrar la traspuesta: CRÍTICO usar COLUMNAS como filas y FILAS como columnas.
    mostrarMatriz(MatrizTraspuesta, columnas, filas, "Matriz Traspuesta (M x N)"); 

    // 5. Liberación de Memoria CRÍTICA
    
    // Liberar la Matriz Original (N filas)
    liberarMemoria(MatrizOriginal, filas);
    
    // Liberar la Matriz Traspuesta: CRÍTICO usar COLUMNAS (M) como el número de filas
    // que se asignó para esta matriz.
    liberarMemoria(MatrizTraspuesta, columnas); 

    return 0;
}