/*
 * swap.c - un intercambio que no intercambia (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g swap.c -o swap
 *   ./swap
 *
 * En C los argumentos se pasan por valor: intercambiar recibe copias de a y b.
 * Cómo modificar a y b de verdad: punteros, en la cápsula 06.
 */
#include <stdio.h>

void intercambiar(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
    printf("dentro:  x=%d y=%d\n", x, y);
}

int main(void)
{
    int a = 1, b = 2;
    intercambiar(a, b);
    printf("en main: a=%d b=%d\n", a, b);
    return 0;
}
