/*
 * comillas.c - ERROR A PROPÓSITO: 'a' no es lo mismo que "a" (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g comillas.c -o comillas
 *   ./comillas
 *
 *   'a'  es UN carácter (un número: 97)
 *   "a"  es una CADENA: el arreglo {'a', '\0'}, de 2 bytes
 *
 * gcc 13 advierte en la línea de c; desde gcc 14 ya no compila.
 */
#include <stdio.h>

int main(void)
{
    char c = "a";            /* error: debería ser 'a' */

    printf("sizeof 'a' en un char = %zu, sizeof \"a\" = %zu\n",
           sizeof(char), sizeof "a");
    printf("c = %d (se esperaba 97)\n", c);
    return 0;
}
