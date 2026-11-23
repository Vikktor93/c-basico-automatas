/*
 * cadena_nul.c - una cadena es un arreglo de char que termina en '\0' (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g cadena_nul.c -o cadena_nul
 *   ./cadena_nul
 *
 * "hola" ocupa 5 bytes: 'h' 'o' 'l' 'a' y el terminador '\0' (código 0).
 */
#include <stdio.h>

int main(void)
{
    char s[] = "hola";
    char t[] = {'h', 'o', 'l', 'a', '\0'};   /* lo mismo, escrito a mano */

    for (size_t i = 0; i < sizeof s; i++) {
        if (s[i] == '\0')
            printf("s[%zu] = '\\0'  código %d\n", i, s[i]);
        else
            printf("s[%zu] = '%c'   código %d\n", i, s[i], s[i]);
    }

    printf("s = %s, t = %s\n", s, t);

    s[2] = '\0';                             /* cortar la cadena */
    printf("después de s[2] = '\\0': s = %s\n", s);
    return 0;
}
