/*
 * swap.c - el intercambio que SÍ intercambia (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g swap.c -o swap
 *   ./swap
 *
 * Compáralo con ejemplos/capsula-04/swap.c: allá la función recibía copias
 * de a y b. Aquí recibe sus DIRECCIONES, y con *x y *y modifica las
 * variables originales de main.
 */
#include <stdio.h>

void intercambiar(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    printf("dentro:  *x=%d *y=%d\n", *x, *y);
}

int main(void)
{
    int a = 1, b = 2;
    intercambiar(&a, &b);
    printf("en main: a=%d b=%d\n", a, b);
    return 0;
}
