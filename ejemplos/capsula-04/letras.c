/*
 * letras.c - un char es un número (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g letras.c -o letras
 *   ./letras
 *
 * '7' - '0' convierte un dígito en número: es lo que hace delta[q][*p - '0'] en un AFD.
 */
#include <stdio.h>

int main(void)
{
    char c = 'a';
    printf("%c es %d\n", c, c);
    printf("%c\n", c + 1);
    printf("%d\n", '7' - '0');
    return 0;
}
