/*
 * verdad.c - en C, la verdad es un número (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g verdad.c -o verdad
 *   ./verdad
 *
 * 0 es falso; cualquier otro valor es verdadero.
 * Una comparación produce 1 o 0.
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool listo = true;
    printf("%d %d\n", listo, !listo);
    if (42) printf("42 es verdadero\n");
    if (0)  printf("nunca\n");
    printf("%d\n", 3 > 2);
    return 0;
}
