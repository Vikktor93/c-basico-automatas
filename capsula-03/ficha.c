#include <stdio.h>

int main(void)
{
    const char *nombre = "Ian Fack"; 
    char inicial  = 'I';
    int edad = 23;
    double promedio = 5.5;
 
     /*   %s para el nombre, %c para la inicial,
     *   %d para la edad y %.1f para el promedio. */

    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Promedio: %.1f\n", promedio);
    return 0;
}


