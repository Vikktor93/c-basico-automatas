/*
 * ficha.c - Cápsula 03
 *
 * Completa los TODO. Al terminar, borra la línea que imprime "TODO"
 */
#include <stdio.h>

int main(void)
{
    /* TODO 1: declara cuatro variables con tus datos:
     *   - nombre   : texto       (ejemplo: const char *nombre = "María Pérez";)
     *   - inicial  : un char     (ejemplo: 'M')
     *   - edad     : un int
     *   - promedio : un double
     */

    /* TODO 2: imprime cada dato en su propia línea, con su formato:
     *   %s para el nombre, %c para la inicial,
     *   %d para la edad y %.1f para el promedio.
     *
     * Ejemplo de salida:
     *   Nombre: María Pérez
     *   Inicial: M
     *   Edad: 20
     *   Promedio: 5.8
     */

    const char *nombre = "Karla Miranda";
    char inicial = 'K';
    int edad = 24;
    double nota1 = 5.0;
    double nota2 = 4.9;
    double nota3 = 5.5;

    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Promedio de notas: %.1f\n", (nota1 + nota2 + nota3) / 3);

    return 0;
}
