#ifndef MATRICES_UTILS_H
#define MATRICES_UTILS_H

//Prototipos de las funciones
// 1. Prototipo de la funcion
int** asignarMemoria(int filas, int columnas);
void sumarMatrices();
void pedirDatos(int** matriz, int columnas, int filas, const std::string &Nombre);

//Funcion suma de matrices con punteros de punteros
int** sumarMatrices(int** MatrizA, int** MatrizB, int filas, int columnas);

//Funcion mostrar matriz
void mostrarMatriz(int** matriz, int filas, int columnas, const std::string& Nombre);
void liberarMemoria(int** matriz, int filas);
    #endif //MATRICES_UTILS_H
