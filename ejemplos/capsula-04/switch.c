/*
 * switch.c - no olvides el break (cápsula 04)
 *
 * ADVERTENCIA INTENCIONAL: al case 1 le falta el break.
 * Sin break, la ejecución sigue en el case siguiente.
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g switch.c -o switch
 *   ./switch         -> uno, dos
 *
 * La advertencia la activa -Wextra, no -Wall.
 */
#include <stdio.h>

int main(void)
{
    int opcion = 1;
    switch (opcion) {
    case 1:
        printf("uno\n");
    case 2:
        printf("dos\n");
        break;
    default:
        printf("otro\n");
    }
    return 0;
}
