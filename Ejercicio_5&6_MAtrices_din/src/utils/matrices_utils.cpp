#include <iostream>
#include <iomanip>

// 1. Prototipo de la funcion
int** asignarMemoria(int filas, int columnas);

// 2. Implementación de la función (Completa el cuerpo)
int** asignarMemoria(int filas, int columnas) {
    // 1. Declarar el puntero de punteros
    int** matriz; 

    // 2. Asignar memoria para el array principal de punteros (las filas)
    matriz = new int*[filas]; 
    // 3. Usar un bucle para asignar memoria a cada fila (las columnas)
        for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
          }

    // 4. Retornar el puntero base
        return matriz;
}
// Implementación de la función (Completa el cuerpo)
void liberarMemoria(int** matriz, int filas) {
    // 1. Usar un bucle para liberar la memoria de CADA FILA (columnas)
     for (int i = 0; i < filas; i++)
     {
        delete[]matriz[i];
     }
     // primero libero el contenidol luego la matriz
    // 2. Liberar la memoria del ARRAY PRINCIPAL de punteros (las filas)
      delete[]matriz; // Libera el bloque de punteros (new int*[filas])
}

//Función para pedir datos

void pedirDatos(int** matriz, int columnas, int filas, const std::string &Nombre){

std::cout << "\n--- Llenando la " << Nombre << " ---" << std::endl;
    
    // Bucle externo (i) para recorrer las FILAS
    for (int i = 0; i < filas; ++i) {
        
        // Bucle interno (j) para recorrer las COLUMNAS
        for (int j = 0; j < columnas; ++j) {
            
            // 1. Muestra el mensaje de solicitud (ej: "Matriz A[0][0]:")
            std::cout << Nombre << "[" << i << "][" << j << "]: ";
            
            // 2. Lee el valor del usuario y lo asigna a la posición matriz[i][j]
            std::cin >> matriz[i][j];
        }
    }
}


//Funcion suma de matrices con punteros de punteros
int** sumarMatrices(int** MatrizA, int** MatrizB, int filas, int columnas){ // 1. Asignar memoria para la matriz resultante C (Llama a la función que ya creaste)
    int** MatrizSuma = asignarMemoria(filas, columnas); 

    // 2. Bucle externo (i) para las FILAS
    for (int i = 0; i < filas; ++i) {

        // 3. Bucle interno (j) para las COLUMNAS
        for (int j = 0; j < columnas; ++j) {

            // 4. Realizar la suma y asignarla a la MatrizSuma[i][j]
            MatrizSuma[i][j] = MatrizA[i][j] + MatrizB[i][j];
        }
    }
    
    // 5. Retornar la matriz resultante
    return MatrizSuma;
}

//Funcion mostrar matriz 
void mostrarMatriz(int** matriz, int filas, int columnas, const std::string& Nombre) {
    
    std::cout << "\n--- Resultado de la " << Nombre << " ---" << std::endl;
    
    // Bucle externo (i) para las FILAS
    for (int i = 0; i < filas; ++i) {
        
        // Bucle interno (j) para las COLUMNAS
        for (int j = 0; j < columnas; ++j) {
            
            // Usamos std::setw(5) para asegurar que cada número ocupe 5 espacios
            // Esto mantiene la forma visual de la matriz.
            std::cout << std::setw(5) << matriz[i][j];
        }
        
        // Salto de línea después de cada fila
        std::cout << "\n";
    }
}

//Función obtener taspuesta
int** obtenerTraspuesta(int** MatrizOriginal, int filas, int columnas) {
    
    // 1. Asignar memoria para la Matriz Traspuesta (CRÍTICO: Invertir dimensiones)
    // Las nuevas FILAS son las viejas COLUMNAS, y viceversa.
    int** MatrizTraspuesta = asignarMemoria(columnas, filas); 

    // 2. Llenar la Matriz Traspuesta
    // Recorremos la matriz original (i=filas, j=columnas)
    for (int i = 0; i < filas; ++i) { 
        for (int j = 0; j < columnas; ++j) {
            
            // 3. Asignación del valor: Inversión de índices
            // El elemento original en MatrizOriginal[i][j] se copia a MatrizTraspuesta[j][i]
            MatrizTraspuesta[j][i] = MatrizOriginal[i][j];
        }
    }
    
    // 4. Retornar la nueva matriz (M*N)
    return MatrizTraspuesta;
}