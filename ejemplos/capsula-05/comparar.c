/*
 * comparar.c - ERROR A PROPÓSITO: las cadenas no se comparan con == (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g comparar.c -o comparar
 *   ./comparar
 *
 * Con == se comparan las DIRECCIONES de los arreglos, no su contenido.
 * Para comparar el contenido se usa strcmp, que retorna 0 si son iguales.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char clave[] = "abba";

    if (clave == "abba")                          /* error */
        printf("con ==     : iguales\n");
    else
        printf("con ==     : distintas (?)\n");

    if (strcmp(clave, "abba") == 0)
        printf("con strcmp : iguales\n");
    return 0;
}
