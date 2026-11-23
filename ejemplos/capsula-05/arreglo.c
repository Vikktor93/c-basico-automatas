/*
 * arreglo.c - declarar, recorrer y medir un arreglo (cápsula 05)
 *
 * Compilar y ejecutar:
 *   gcc -Wall -Wextra -g arreglo.c -o arreglo
 *   ./arreglo
 *
 * Un arreglo es una fila de variables del mismo tipo, una al lado de la otra.
 * Los índices van de 0 a n-1, y C NO guarda el tamaño: hay que calcularlo.
 */
#include <stdio.h>

int main(void)
{
    int notas[5] = {55, 62, 40, 70, 58};
    int ceros[5] = {1, 2};          /* los que faltan quedan en 0 */

    int n = sizeof notas / sizeof notas[0];
    printf("sizeof notas = %zu bytes, cada int = %zu, n = %d\n",
           sizeof notas, sizeof notas[0], n);

    int suma = 0;
    for (int i = 0; i < n; i++) {
        printf("notas[%d] = %d\n", i, notas[i]);
        suma += notas[i];
    }
    printf("promedio = %.1f\n", (double)suma / n);

    printf("ceros = {%d, %d, %d, %d, %d}\n",
           ceros[0], ceros[1], ceros[2], ceros[3], ceros[4]);
    return 0;
}
