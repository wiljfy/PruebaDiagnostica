#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para generar los coeficientes usando el Triángulo de Pascal
int* generarCoeficientes(int n) {
    int* coeficientes = (int*)malloc((n + 1) * sizeof(int));
    
    for (int i = 0; i <= n; i++) {
        coeficientes[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            coeficientes[j] = coeficientes[j] + coeficientes[j - 1];
        }
    }
    
    return coeficientes;
}

// Función para imprimir el polinomio
void imprimirPolinomio(int* coeficientes, int n) {
    printf("(x + 1)^%d = ", n);
    
    for (int i = n; i >= 0; i--) {
        if (coeficientes[i] != 0) {
            if (i < n) {
                printf(" + ");
            }
            
            if (coeficientes[i] != 1 || i == 0) {
                printf("%d", coeficientes[i]);
            }
            
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
        }
    }
    printf("\n");
}

// Función para evaluar el polinomio paso a paso
void evaluarPolinomio(int* coeficientes, int n, double x) {
    double resultado = 0;
    printf("\nEvaluando f(%.2f) = (%.2f + 1)^%d\n", x, x, n);
    printf("Usando el polinomio: ");
    imprimirPolinomio(coeficientes, n);
    printf("\n");
    
    for (int i = 0; i <= n; i++) {
        double termino = coeficientes[i] * pow(x, i);
        printf("Término %d: %d * %.2f^%d = %d * %.4f = %.4f\n", 
               i, coeficientes[i], x, i, coeficientes[i], pow(x, i), termino);
        resultado += termino;
    }
    
    printf("\nResultado final: %.4f\n", resultado);
    printf("Verificación: (%.2f + 1)^%d = %.4f\n\n", x, n, pow(x + 1, n));
}

int main() {
    int n;
    double x;
    
    printf("Ingrese el exponente n (entero no negativo): ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Error: n debe ser no negativo.\n");
        return 1;
    }
    
    int* coeficientes = generarCoeficientes(n);
    
    // Parte a) Mostrar el polinomio
    printf("\na) Polinomio generado:\n");
    imprimirPolinomio(coeficientes, n);
    
    // Parte b) Evaluar el polinomio
    printf("\nb) Evaluacion del polinomio\n");
    printf("Ingrese el valor de x para evaluar: ");
    scanf("%lf", &x);
    
    evaluarPolinomio(coeficientes, n, x);
    
    free(coeficientes);
    return 0;
}
