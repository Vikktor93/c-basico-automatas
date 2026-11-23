/*
 * leer_numero.c - por qué scanf necesita & (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g leer_numero.c -o leer_numero
 *   ./leer_numero                 (escribe un número y presiona Enter)
 *   echo 21 | ./leer_numero
 *
 * scanf tiene que ESCRIBIR en n, así que necesita su dirección: &n.
 * Retorna cuántos datos logró leer (1 si todo salió bien).
 */
#include <stdio.h>

int main(void)
{
    int n;

    printf("Escribe un número: ");
    if (scanf("%d", &n) != 1) {
        printf("Eso no es un número\n");
        return 1;
    }
    printf("El doble de %d es %d\n", n, 2 * n);
    return 0;
}
