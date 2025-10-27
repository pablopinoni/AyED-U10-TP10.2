#ifndef ESTRUCTURA_ALUMNOS_H
#define ESTRUCTURA_ALUMNOS_H
#include <string>

// Definición de la estructura del Alumno
typedef struct {
    std::string nombre;
    int edad;
    float promedio;
} tAlumno; 

// Definición de la Constante
const int N_ALUMNOS = 3; 

// Estructura Contenedora Dinámica (Usando el nombre de puntero que elegiste)
typedef struct {
    // CRÍTICO: Usamos 'p_tAlumno' como el puntero base al array dinámico
    tAlumno* p_tAlumno; 
    int cont;         
} tListaAlumnos; // <-- Punto y coma necesario aquí.

// Prototipos adaptados a Punteros

/** Asigna memoria dinámicamente y pide datos. */
void pedirDatos(tListaAlumnos* p_lista); // <-- Se mantiene

/** Retorna la dirección (puntero) del mejor alumno. */
tAlumno* encontrarMejorPromedio(const tListaAlumnos* p_lista); 

/** Imprime los datos, recibiendo un puntero constante. */
void imprimirDatos(const tAlumno* p_mejorAlumno); 
/** CRÍTICO: Función necesaria para liberar la memoria dinámica. */
void liberarMemoria(tListaAlumnos* p_lista); 


#endif //ESTRUCTURA_ALUMNOS_H