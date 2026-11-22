/*
 * salida.c - main responde con un número (cápsula 03)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g salida.c -o salida
 *   ./salida
 *   echo $?        -> muestra 1
 *
 * return 0 significa «todo bien»; cualquier otro número, que algo falló.
 */
#include <stdio.h>

int main(void)
{
    printf("Algo salió mal\n");
    return 1;
}
