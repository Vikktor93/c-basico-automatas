/*
 * malformato.c - formato equivocado, resultado basura (cápsula 03)
 *
 * ADVERTENCIA INTENCIONAL: este programa tiene un error a propósito.
 * %d espera un int, pero recibe un double.
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g malformato.c -o malformato
 *   ./malformato     -> imprime un número sin sentido, distinto cada vez
 *
 * Para corregirlo, cambia %d por %.1f, como sugiere gcc.
 */
#include <stdio.h>

int main(void)
{
    double nota = 6.5;
    printf("Nota: %d\n", nota);
    return 0;
}
