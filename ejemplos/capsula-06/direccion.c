/*
 * direccion.c - toda variable vive en una dirección de memoria (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g direccion.c -o direccion
 *   ./direccion
 *
 * &x es la dirección de x. %p la imprime en hexadecimal.
 * Las direcciones cambian en cada ejecución: es normal.
 */
#include <stdio.h>

int main(void)
{
    int x = 42;
    int y = 7;
    char c = 'a';

    printf("x = %d  vive en %p\n", x, (void *)&x);
    printf("y = %d   vive en %p\n", y, (void *)&y);
    printf("c = %c   vive en %p\n", c, (void *)&c);
    printf("sizeof(int *) = %zu bytes: una dirección ocupa 8 bytes en 64 bits\n",
           sizeof(int *));
    return 0;
}
