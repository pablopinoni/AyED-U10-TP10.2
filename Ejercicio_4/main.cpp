/*Pedir una cadena de caracteres (string) al usuario, e indicar cuantas veces
aparece la vocal a,e,i,o,u; en la cadena de caracteres. NOTA: Usar punteros */
#include <iostream>
#include "vocales.h"


int main() {
    // Declaramos una variable para recibir el conteo total
    int conteo_final = 0;
    
    // 1. Obtiene el puntero a la cadena dinámica
    char* frase_ptr = getFrase();
    
    if (frase_ptr == nullptr) {
        return 1; // Sale si falla la asignación
    }

    // 2. Llama a la funcion de conteo, pasando el puntero a la cadena y la DIRECCIÓN del contador
    contarVocales(frase_ptr, &conteo_final);
    
    std::cout << "\nCadena ingresada: " << frase_ptr << std::endl;
    std::cout << "El numero total de vocales encontradas es: " << conteo_final << std::endl;

    // 3. Liberacion de memoria (CRITICO)
    delete[] frase_ptr;
    frase_ptr = nullptr;
    
    return 0;
}