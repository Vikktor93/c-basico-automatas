/*
 * escapes.c - secuencias de escape: \n, \t, \" y \\ (cápsula 03)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g escapes.c -o escapes
 *   ./escapes
 */
#include <stdio.h>

int main(void)
{
    printf("a\tb\n");
    printf("Dijo \"hola\"\n");
    printf("C:\\temp\n");
    return 0;
}
