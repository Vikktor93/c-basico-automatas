/*
 * palabras.c - un arreglo de cadenas es un arreglo de arreglos (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g palabras.c -o palabras
 *   ./palabras
 *
 * palabras[i] es la cadena i; palabras[i][j] es su símbolo j.
 * Es la forma de guardar un lenguaje finito en C.
 */
#include <stdio.h>

int main(void)
{
    char L[][6] = {"a", "ab", "abb", "ba"};      /* 4 cadenas de hasta 5 símbolos */
    int n = sizeof L / sizeof L[0];

    printf("L tiene %d cadenas y ocupa %zu bytes\n", n, sizeof L);
    for (int i = 0; i < n; i++)
        printf("L[%d] = %-4s  su primer símbolo es '%c'\n", i, L[i], L[i][0]);
    return 0;
}
