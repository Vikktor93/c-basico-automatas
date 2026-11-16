/*
 * prototipo_con.c - el prototipo anuncia la función (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g prototipo_con.c -o prototipo_con
 *   ./prototipo_con  -> 16
 */
#include <stdio.h>

int cuadrado(int n);

int main(void)
{
    printf("%d\n", cuadrado(4));
    return 0;
}

int cuadrado(int n)
{
    return n * n;
}
