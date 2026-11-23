/*
 * local.c - ERROR A PROPÓSITO: retornar la dirección de una variable local
 *           (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g local.c -o local
 *   ./local
 *
 * Las variables locales dejan de existir cuando la función termina
 * (como x e y en el swap de la cápsula 04). Su dirección queda inválida.
 */
#include <stdio.h>

int *siguiente(int n)
{
    int resultado = n + 1;
    return &resultado;                /* error: resultado muere al salir */
}

int main(void)
{
    int *p = siguiente(41);
    printf("Se esperaba 42\n");
    if (p != NULL)
        printf("*p = %d\n", *p);
    else
        printf("p es NULL: gcc reemplazó la dirección inválida por NULL\n");
    return 0;
}
