/*
 * promedio.c - comentarios y estilo (cápsula 03)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g promedio.c -o promedio
 *   ./promedio       -> 5.8
 */
#include <stdio.h>

int main(void)
{
    double nota1 = 5.5;
    double nota2 = 6.0;
    // %.1f muestra un decimal: 5.75 se redondea a 5.8
    printf("%.1f\n", (nota1 + nota2) / 2);
    return 0;
}
