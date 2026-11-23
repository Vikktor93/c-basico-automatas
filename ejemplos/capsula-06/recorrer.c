/*
 * recorrer.c - recorrer una cadena con un puntero (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g recorrer.c -o recorrer
 *   ./recorrer
 *
 * En vez de un índice w[i], el puntero avanza (p++) hasta llegar al '\0'.
 * Es la forma en que un autómata lee su entrada: símbolo a símbolo.
 */
#include <stdio.h>

int largo(const char *w)
{
    const char *p = w;
    while (*p != '\0')
        p++;
    return (int)(p - w);              /* cuántos símbolos avanzó */
}

int main(void)
{
    const char *w = "abba";

    for (const char *p = w; *p != '\0'; p++)
        printf("símbolo '%c' en la posición %d\n", *p, (int)(p - w));

    printf("largo(\"%s\") = %d\n", w, largo(w));
    return 0;
}
