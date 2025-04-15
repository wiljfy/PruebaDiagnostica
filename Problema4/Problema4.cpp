#include <iostream>
#include <string>

using namespace std;

// funcion que verifica si es una palabra reservada
bool isReservedWord (const string& word, const string E[], int numreservedwords) {
    for (int i = 0; i < numreservedwords; ++i) {
        if (word == E[i]) {
            return true;
        }
    }
    return false;
}

//funcion que cuenta la cantidad de palabras reservadas
int countReservedWords (const string& cod, const string E[], int numreservedwords) {
    int cont = 0;
    string currentword;

    // Iterar sobre cada carÃ¡cter del codigo
    for (char caracter : cod) {
        // Si es un caraccter de espacio o un simbolo de puntuacion, termina la palabra actual
        if (isspace(caracter) || ispunct(caracter)) {
            // Verificar si la palabra actual es una palabra reservada
            if (isReservedWord(currentword, E, numreservedwords)) {
                cont++;
            }
            // Limpiar la palabra actual para comenzar una nueva palabra
            currentword.clear();
        } else {
            // Agregar el caracter actual a la palabra actual
            currentword.push_back(caracter);
        }
    }

    // Verificar si la ultima palabra del codigo es una palabra reservada
    if (!currentword.empty() && isReservedWord(currentword, E, numreservedwords)) {
        cont++;
    }

    return cont;
}

int main() {
    // Definir el codigo y las palabras reservadas
    string C = "Prueba Diagnostica, es la primera asignacion de la materia"; // Cadena a analizar
    string E[] = {"Diagnostica", "la", "materia"}; // palabras reservadas
    int numreservedwords = sizeof(E) / sizeof(E[0]);

    // Obtener el resumen
    int amountReservedWords = countReservedWords(C, E, numreservedwords);

    // Mostrar el resumen
    cout << "La cantidad de ocurrencias de la palabra E en C es : " << amountReservedWords << endl;

    return 0;
}
