/*
 * leer_linea.c - leer una cadena del teclado con fgets (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g leer_linea.c -o leer_linea
 *   ./leer_linea                  (escribe una palabra y presiona Enter)
 *   echo 0110 | ./leer_linea      (o entrégale la línea con una tubería)
 *
 * fgets nunca escribe más de sizeof w bytes, pero guarda el '\n' del Enter.
 */
#include <stdio.h>

int main(void)
{
    char w[64];

    printf("Escribe una cadena: ");
    if (fgets(w, sizeof w, stdin) == NULL)
        return 1;

    int n = 0;
    while (w[n] != '\0' && w[n] != '\n')
        n++;
    w[n] = '\0';                      /* quitar el '\n' */

    printf("Leíste \"%s\", de largo %d\n", w, n);
    return 0;
}
