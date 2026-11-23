/*
 * sin_inicializar.c - ERROR A PROPÓSITO: un puntero que apunta a cualquier
 *                     parte (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g sin_inicializar.c -o sin_inicializar
 *   ./sin_inicializar
 *
 * p se declara pero nunca recibe una dirección: contiene basura.
 * Escribir en *p es escribir en una dirección al azar.
 */
#include <stdio.h>

int main(void)
{
    int *p;                           /* error: falta p = &algo; */

    *p = 5;
    printf("*p = %d\n", *p);
    return 0;
}
