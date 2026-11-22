/*
 * tamanos.c - cada tipo tiene un tamaño fijo (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g tamanos.c -o tamanos
 *   ./tamanos
 *
 * Los valores son los de Ubuntu de 64 bits; en otros sistemas pueden cambiar.
 */
#include <stdio.h>

int main(void)
{
    printf("char:   %zu\n", sizeof(char));
    printf("int:    %zu\n", sizeof(int));
    printf("long:   %zu\n", sizeof(long));
    printf("float:  %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    return 0;
}
