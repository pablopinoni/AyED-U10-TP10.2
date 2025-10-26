#ifndef SUMA_MATRICES_H
#define SUMA_MATRICES_H

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
    #endif //SUMA_MATRICES_H