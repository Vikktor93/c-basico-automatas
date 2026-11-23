/*
 * copiar.c - un arreglo no se puede asignar con = (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g copiar.c -o copiar
 *   ./copiar
 *
 * Prueba a quitar el comentario de la línea "t = s;": no compila.
 * Para copiar una cadena se copia símbolo por símbolo (o con snprintf).
 */
#include <stdio.h>

int main(void)
{
    char s[] = "0110";
    char t[10];

    /* t = s; */                      /* error: assignment to expression with array type */

    int i = 0;
    while (s[i] != '\0') {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';                      /* ¡no olvidar el terminador! */
    printf("copia a mano: %s\n", t);

    char u[10];
    snprintf(u, sizeof u, "%s%s", s, "1");   /* copiar y concatenar sin desbordar */
    printf("con snprintf: %s\n", u);
    return 0;
}
