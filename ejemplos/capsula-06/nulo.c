/*
 * nulo.c - ERROR A PROPÓSITO: usar un puntero NULL (cápsula 06)
 *
 * Compilar y ejecutar de dos formas:
 *   gcc -Wall -Wextra -g nulo.c -o nulo
 *   ./nulo                               (Segmentation fault)
 *
 *   gcc -Wall -Wextra -g -fsanitize=address nulo.c -o nulo
 *   ./nulo                               (indica la línea exacta)
 *
 * NULL significa "no apunta a nada". Antes de usar *p hay que revisar
 * que p != NULL.
 */
#include <stdio.h>

const char *buscar(const char *w, char c)
{
    for (; *w != '\0'; w++)
        if (*w == c)
            return w;
    return NULL;
}

int main(void)
{
    const char *p = buscar("000", '1');      /* no hay '1': retorna NULL */

    printf("Buscando...\n");
    printf("encontré '%c'\n", *p);           /* error: falta if (p != NULL) */
    return 0;
}
