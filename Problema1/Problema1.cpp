#include <stdio.h>
#include <string.h>
#include <ctype.h>

int es_fen_valido(const char *C) {
    if (C == NULL) {
        return 0; // Cadena nula no es válida
    }

    int fila = 0;
    int columna = 0;
    int i = 0;

    while (C[i] != '\0' && C[i] != ' ') {
        if (isdigit(C[i])) {
            columna += C[i] - '0';
        } else if (strchr("PNBRQKpnbrqk", C[i]) != NULL) {
            columna++;
        } else if (C[i] == '/') {
            if (columna != 8) {
                return 0; // Número incorrecto de columnas en la fila
            }
            fila++;
            columna = 0;
        } else {
            return 0; // Carácter no válido
        }
        i++;
    }

    if (fila != 7 || columna != 8) {
        return 0; // Número incorrecto de filas o columnas
    }

    return 1; // Cadena FEN válida
}

int main() {
    char C1[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    char C2[] = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";
    char C3[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBjj";

    printf("'%s' es FEN valido: %s\n", C1, es_fen_valido(C1) ? "Si" : "No");
    printf("'%s' es FEN valido: %s\n", C2, es_fen_valido(C2) ? "Si" : "No");
    printf("'%s' es FEN valido: %s\n", C3, es_fen_valido(C3) ? "Si" : "No");

    return 0;
}

