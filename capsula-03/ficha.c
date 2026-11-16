
/*
 * ficha.c - Cápsula 03
 *
 * Completa los TODO. Al terminar, borra la línea que imprime "TODO"
 */
#include <stdio.h>

int main(void)
{
    /* TODO 1: declara cuatro variables con tus datos:
     *   - nombre   : Marco Saldivia
     *   - inicial  : M
     *   - edad     : 20
     *   - promedio : 5.8
     */
    char nombre[] = "Marco Saldivia";
    char inicial = 'M';
    int edad = 20;
    double promedio = 5.8;

    /* TODO 2: imprime cada dato en su propia línea, con su formato:
     *   %s para el nombre, %c para la inicial,
     *   %d para la edad y %.1f para el promedio.
     */
    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Promedio: %.1f\n", promedio);

    return 0;
}


