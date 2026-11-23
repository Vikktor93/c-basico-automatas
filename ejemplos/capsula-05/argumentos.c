/*
 * argumentos.c - recibir cadenas desde la línea de comandos (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g argumentos.c -o argumentos
 *   ./argumentos 0110 abba λ
 *
 * argc es la cantidad de argumentos; argv[0] es el nombre del programa y
 * argv[1] ... argv[argc-1] son las cadenas que escribiste.
 * Así recibirá sus datos el programa del Taller de Programación.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
    return 0;
}
