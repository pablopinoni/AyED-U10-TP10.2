#include <iostream>
#include <string>
#include <limits> // Para limpiar el buffer
#include <cctype> // Necesario para tolower()

// Función que pide la frase y retorna el puntero a la memoria dinámica
char* getFrase() 
{
    const int N_MAX = 100;
    // Asignación dinámica (memoria creada en el Heap)
    char* ptr_cadena = new char[N_MAX];
    
    // Verificación de asignación (práctica efectiva)
    if (ptr_cadena == nullptr) {
        std::cerr << "Error: No se pudo asignar memoria para la cadena." << std::endl;
        return nullptr;
    }

    std::cout << "Escriba una frase (max " << N_MAX - 1 << " caracteres):" << std::endl;
    
    // Limpiar el buffer de entrada antes de usar getline (necesario si hay un cin anterior)
   // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Usamos getline para leer la frase completa, incluyendo espacios
    std::cin.getline(ptr_cadena, N_MAX);

    return ptr_cadena; // Retorna la dirección de la cadena
}

//Función contar vocales
void contarVocales(char *line, int *count_total)
{
    char* ptr_actual = line; // Puntero auxiliar para iterar
    
    // Inicializar el conteo total, modificando la variable de main
    *count_total = 0; 
    
    // Bucle para recorrer la cadena, deteniéndose en el carácter nulo '\0'
    while ( *ptr_actual != '\0' ) {
        
        // Convertir a minúsculas y compararla
        char caracter = std::tolower(*ptr_actual);
        
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
            // Aumentar el VALOR de la variable apuntada por count_total
            (*count_total)++;
        }
        
        // Mover el puntero a la siguiente posición
        ptr_actual++; 
    }
}

