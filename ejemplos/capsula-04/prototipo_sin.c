/*
 * prototipo_sin.c - usar una función antes de declararla (cápsula 04)
 *
 * ADVERTENCIA INTENCIONAL: main llama a cuadrado antes de que gcc la conozca.
 * Con gcc 13 (Ubuntu 24.04) es una advertencia; desde gcc 14 es un error.
 * Compara con prototipo_con.c.
 *
 * Compilar:
 *   gcc -Wall -Wextra -g prototipo_sin.c -o prototipo_sin
 */
#include <stdio.h>

int main(void)
{
    printf("%d\n", cuadrado(4));
    return 0;
}

int cuadrado(int n)
{
    return n * n;
}
