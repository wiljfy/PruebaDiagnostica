#include <string>
#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;

// Funcion para evaluar la expresion aritmetica
double evaluarExpresion(const string& expresion) {
    double result = 0.0;
    char op = '+'; // Operador inicial
    double number = 0.0;

    for (size_t i = 0; i < expresion.length(); ++i) {
        char c = expresion[i];

        if (isdigit(c) || c == 'E' || c == '.' || (c == '-' && i == 0)) {
            // Si es un digito, un punto decimal, un exponente o el signo negativo inicial
            string numStr;
            while (isdigit(expresion[i]) || expresion[i] == '.' || expresion[i] == 'E' || (expresion[i] == '-' && i == 0)) {
                numStr += expresion[i++];
            }
            
            number = stod(numStr);
            --i; // Retroceder el indice para no saltar el siguiente caracter

            // Aplicar el operador actual al numero y actualizar el resultado
            switch (op) {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
                case '*':
                    result *= number;
                    break;
                case '/':
                    result /= number;
                    break;
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Si es un operador, actualizar el operador actual
            op = c;
        } else if (c == '(') {
            // Si es un parentesis de apertura, buscar el parentesis de cierre
            size_t j = i + 1;
            int count = 1;
            while (j < expresion.length() && count > 0) {
                if (expresion[j] == '(') ++count;
                else if (expresion[j] == ')') --count;
                ++j;
            }
            string subExpr = expresion.substr(i + 1, j - i - 2);
            number = evaluarExpresion(subExpr); // Evaluar la subexpresion
            i = j - 1; // Actualizar el Ã­ndice
            // Aplicar el operador actual al resultado de la subexpresion y actualizar el resultado
            switch (op) {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
                case '*':
                    result *= number;
                    break;
                case '/':
                    result /= number;
                    break;
            }
        }
    }

    return result;
}

//funcion principal main 
int main() {
    string expresion = "(125E10 – 1e15)/5E-85*15";
    double result = evaluarExpresion(expresion);
    cout << "El resultado de la expresion \"" << expresion << "\" es: " << scientific << result << endl;

    return 0;
}
