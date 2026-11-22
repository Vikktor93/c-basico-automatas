/*
 * division.c - entre enteros, la división es entera (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g division.c -o division
 *   ./division
 *
 * r1 vale 3.0 aunque sea double: la división entre enteros ocurre antes de guardar.
 * r2 vale 3.5 porque (double) convierte a antes de dividir.
 */
#include <stdio.h>

int main(void)
{
    int a = 7, b = 2;
    double r1 = a / b;
    double r2 = (double) a / b;
    printf("%d %d\n", a / b, a % b);
    printf("%f %f\n", r1, r2);
    return 0;
}
