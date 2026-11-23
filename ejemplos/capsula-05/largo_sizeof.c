/*
 * largo_sizeof.c - sizeof no es el largo, y un arreglo "olvida" su tamaño
 *                  al pasar a una función (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g largo_sizeof.c -o largo_sizeof
 *   ./largo_sizeof
 *
 * ERROR A PROPÓSITO en mal_tamano: gcc advierte que sizeof de un parámetro
 * arreglo da el tamaño de un puntero (8), no el del arreglo.
 */
#include <stdio.h>
#include <string.h>

void mal_tamano(char s[])
{
    printf("dentro de la función: sizeof s = %zu\n", sizeof s);
}

int main(void)
{
    char s[20] = "lemas";

    printf("sizeof s = %zu   (memoria reservada)\n", sizeof s);
    printf("strlen s = %zu   (símbolos hasta el '\\0')\n", strlen(s));
    mal_tamano(s);
    return 0;
}
