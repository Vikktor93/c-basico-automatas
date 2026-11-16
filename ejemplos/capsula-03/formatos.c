/*
 * formatos.c - un formato de printf para cada tipo (cápsula 03)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g formatos.c -o formatos
 *   ./formatos
 */
#include <stdio.h>

int main(void)
{
    int edad = 20;
    double nota = 6.5;
    char letra = 'A';
    printf("Edad: %d\n", edad);
    printf("Nota: %f\n", nota);
    printf("Nota: %.1f\n", nota);
    printf("Letra: %c\n", letra);
    printf("Curso: %s\n", "Automatas");
    printf("Tamaño: %zu bytes\n", sizeof(int));
    printf("Hex: %x\n", 255);
    printf("100%%\n");
    printf("a\tb\n");
    return 0;
}
