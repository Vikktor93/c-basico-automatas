/*
 * asignacion.c - la trampa del = en un if (cápsula 04)
 *
 * ADVERTENCIA INTENCIONAL: este programa tiene un error a propósito.
 * x = 0 asigna (y vale 0, falso); para comparar se usa x == 0.
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g asignacion.c -o asignacion
 *   ./asignacion     -> x no es cero
 *
 * Sin -Wall, gcc no avisa nada.
 */
#include <stdio.h>

int main(void)
{
    int x = 5;
    if (x = 0)
        printf("x es cero\n");
    else
        printf("x no es cero\n");
    return 0;
}
