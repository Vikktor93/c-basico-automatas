/*
 * dos_resultados.c - parámetros de salida: una función que "retorna" dos
 *                    valores (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g dos_resultados.c -o dos_resultados
 *   ./dos_resultados
 *
 * return entrega un solo valor. Para entregar más, la función recibe
 * direcciones y escribe ahí sus resultados.
 */
#include <stdio.h>
#include <stdbool.h>

bool dividir(int a, int b, int *cociente, int *resto)
{
    if (b == 0)
        return false;                 /* el retorno indica si funcionó */
    *cociente = a / b;
    *resto = a % b;
    return true;
}

int main(void)
{
    int q, r;

    if (dividir(17, 5, &q, &r))
        printf("17 / 5 = %d, resto %d\n", q, r);
    if (!dividir(17, 0, &q, &r))
        printf("17 / 0 no se puede\n");
    return 0;
}
