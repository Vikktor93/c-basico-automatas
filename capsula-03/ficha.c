#include <stdio.h>

int main(void) 
{
    char nombre[] = "Joaquín Macías"; // Usar un array de char para guardar nombre (Sugerencia de IA), además usar ""
    char inicial = 'J'; // Se usa '' para un solo carácter, mientras que "" se usa para varios caracteres, o sea una cadena
    int edad = 20;
    double promedio = 5.8;

    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Promedio: %.1f\n", promedio);
    return 0;
}
