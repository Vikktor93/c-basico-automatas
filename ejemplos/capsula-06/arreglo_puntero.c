/*
 * arreglo_puntero.c - el nombre de un arreglo es la dirección de su primer
 *                     elemento (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g arreglo_puntero.c -o arreglo_puntero
 *   ./arreglo_puntero
 *
 *   v       es lo mismo que &v[0]
 *   v + i   es la dirección de v[i]  (avanza i elementos, no i bytes)
 *   *(v+i)  es lo mismo que v[i]
 */
#include <stdio.h>

int main(void)
{
    int v[4] = {10, 20, 30, 40};
    int *p = v;                       /* sin &: v ya es una dirección */

    printf("v = %p, &v[0] = %p\n", (void *)v, (void *)&v[0]);
    for (int i = 0; i < 4; i++)
        printf("v[%d] = %d   *(v+%d) = %d   dirección %p\n",
               i, v[i], i, *(v + i), (void *)(v + i));

    p++;                              /* avanza un int: 4 bytes */
    printf("después de p++: *p = %d\n", *p);
    printf("p - v = %d (elementos de distancia, no bytes)\n", (int)(p - v));
    return 0;
}
