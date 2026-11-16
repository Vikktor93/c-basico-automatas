/*
 * overflow.c - cuando un int no alcanza (cápsula 04)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g overflow.c -o overflow
 *   ./overflow
 *
 * Desbordar un int con signo es comportamiento indefinido: C no avisa.
 * Para detectarlo al ejecutar:
 *   gcc -Wall -Wextra -g -fsanitize=undefined overflow.c -o overflow
 *   ./overflow
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int x = INT_MAX;
    printf("%d\n", x);
    x = x + 1;
    printf("%d\n", x);
    return 0;
}
