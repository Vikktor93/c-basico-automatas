/*
 * puntero.c - un puntero guarda una dirección; * accede a lo apuntado (cápsula 06)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g puntero.c -o puntero
 *   ./puntero
 *
 *   int *p = &x;   p guarda la dirección de x ("p apunta a x")
 *   *p             la variable a la que apunta p: leerla o cambiarla
 */
#include <stdio.h>

int main(void)
{
    int x = 10;
    int *p = &x;

    printf("x = %d, p = %p, *p = %d\n", x, (void *)p, *p);

    *p = 25;                          /* cambia x a través de p */
    printf("después de *p = 25:  x = %d\n", x);

    int y = 3;
    p = &y;                           /* ahora p apunta a otra variable */
    *p = *p * 2;
    printf("después de p = &y y *p = *p * 2:  x = %d, y = %d\n", x, y);
    return 0;
}
