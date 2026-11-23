/*
 * fuera_limites.c - ERROR A PROPÓSITO: escribir fuera del arreglo (cápsula 05)
 *
 * Compilar y ejecutar de dos formas:
 *   gcc -Wall -Wextra -g fuera_limites.c -o fuera_limites
 *   ./fuera_limites                      (puede "funcionar" o no: es indefinido)
 *
 *   gcc -Wall -Wextra -g -fsanitize=address fuera_limites.c -o fuera_limites
 *   ./fuera_limites                      (se detiene y muestra la línea exacta)
 *
 * C no revisa los índices. v[5] no existe en un arreglo de 5 elementos,
 * pero C escribe igual en esa memoria, que pertenece a otra cosa.
 */
#include <stdio.h>

int main(void)
{
    int v[5] = {0};

    for (int i = 0; i <= 5; i++)     /* error: debería ser i < 5 */
        v[i] = i * 10;

    printf("v[4] = %d\n", v[4]);
    return 0;
}
