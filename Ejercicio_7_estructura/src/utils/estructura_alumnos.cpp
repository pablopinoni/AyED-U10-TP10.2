#include "estructura_alumnos.h"
#include <iostream>
#include <string>

 
// Función para pedir datos
void pedirDatos(tListaAlumnos* p_lista){
    using namespace std;
    
    // 1. Asignar memoria dinámica
    p_lista->p_tAlumno = new tAlumno[N_ALUMNOS]; 
    if (p_lista->p_tAlumno == nullptr) {
        cerr << "Error: Falla al asignar memoria dinámica." << endl;
        p_lista->cont = 0;
        return;
    }
    p_lista->cont = N_ALUMNOS;

    cout << "\n===== INGRESAR DATOS DE " << N_ALUMNOS << " ALUMNOS =====\n" << endl;
    
    // 2. Iterar para pedir los 3 alumnos
    for (int i = 0; i < N_ALUMNOS; ++i) {
        cout << "\n--- Alumno " << i + 1 << " ---" << endl;
        
        // 3. Acceso con aritmética de punteros y operador flecha (->)
        cin.ignore(); 
        cout << "Ingrese nombre: ";
        getline(cin, (p_lista->p_tAlumno + i)->nombre); 
        
        cout << "Ingrese edad: ";
        cin >> (p_lista->p_tAlumno + i)->edad;
        
        cout << "Ingrese promedio: ";
        cin >> (p_lista->p_tAlumno+ i)->promedio;
    }
}



// Función para encontrar el puntero al alumno con mejor promedio
tAlumno* encontrarMejorPromedio(const tListaAlumnos* p_lista) {
    
    // 1. Inicializamos el puntero al mejor alumno (p_mejor)
    // Asumimos que el primer alumno (p_lista->alumnos) es el mejor al inicio.
    tAlumno* p_mejor = p_lista->p_tAlumno; 
    
    // El número de alumnos es p_lista->cont
    int N = p_lista->cont;

    // 2. Iteramos desde el segundo alumno (índice 1)
    for (int i = 1; i < N; ++i) {
        
        // Obtenemos un puntero al alumno actual para hacer la comparación más clara
        tAlumno* p_alumnoActual = p_lista->p_tAlumno + i; 
        
        // 3. Comparamos los promedios usando el operador flecha (->)
        // CRÍTICO: Compara el promedio del alumno actual con el del mejor encontrado.
        if (p_alumnoActual->promedio > p_mejor->promedio) {
            
            // 4. Actualizamos: p_mejor ahora apunta a la dirección de p_alumnoActual
            p_mejor = p_alumnoActual;
        }
    }
    
    // 5. Retornamos la dirección (el puntero) de la estructura del mejor alumno
    return p_mejor;
}

// Funcion imprimir datos
void imprimirDatos(const tAlumno* p_mejorAlumno){

    std::cout << "\n==================================" << std::endl;
    std::cout << "EL alumno con mejor promedio es: " << std::endl;
    std::cout << "==================================" << std::endl;

    // CRÍTICO: Usar el operador flecha (->) para acceder a los campos
    std::cout << "Nombre: " << p_mejorAlumno->nombre << std::endl;
    std::cout << "Edad: " << p_mejorAlumno->edad << std::endl;
    std::cout << "Promedio: " << p_mejorAlumno->promedio << std::endl;
    std::cout << "==================================" << std::endl;

}
//Función para libnerar la memoria dinámica

void liberarMemoria(tListaAlumnos* p_lista) {
    // CRÍTICO: Se usa delete[] para liberar el bloque completo
    // asignado previamente con new tAlumno[N_ALUMNOS].
    
    if (p_lista->p_tAlumno != nullptr) {
        delete[] p_lista->p_tAlumno; 
        
        // Buena práctica: Resetear el puntero después de liberar la memoria
        p_lista->p_tAlumno = nullptr; 
        
        // Resetear el contador
        p_lista->cont = 0;
        
        std::cout << "\nMemoria dinamica de los alumnos liberada exitosamente." << std::endl;
    }
}
