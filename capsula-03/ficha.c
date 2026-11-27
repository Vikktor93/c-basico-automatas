#include <stdio.h>

int main(void)
{
    const char *nombre = "Benjamín Alocilla";
    char inicial = 'B';
    int edad = 21;
    double promedio = 5.8;

    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Promedio: %.1f\n", promedio);

    return 0;
}