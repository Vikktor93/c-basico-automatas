#include <stdio.h>

int main(void)
{
    const char *nombre = "Victor Saldivia";
    char inicial = 'M';
    int edad = 33;
    double promedio = 6.3;

    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Promedio: %.1f\n", promedio);
    return 0;
}
