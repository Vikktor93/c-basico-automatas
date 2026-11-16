/*
 * paridad.c - Cápsula 04
 *
 * Completa los TODO. Al terminar, borra la línea que imprime "TODO"
 */
#include <stdio.h>
#include <stdbool.h>

/* TODO 1: escribe aquí el PROTOTIPO de la función es_par.
 *   Recibe un int y retorna un bool.
 */

 int es_par(int n);


int main(void)
{
    /* TODO 2: escribe un ciclo for de 1 a 10 que, usando es_par,
     * imprima una línea por número:
     *   1 es impar
     *   2 es par
     *   ...
     *   10 es par
     */

    for (int num = 1; num <= 10; num++) {
        if (es_par(num)) {
            printf("%d es par\n", num);
        } else {
            printf("%d es impar\n", num);
        }
    }

    return 0;
}

/* TODO 3: escribe aquí la DEFINICIÓN de es_par.
 *   Retorna true si n es par y false si no.
 *   Pista: el operador % entrega el resto de la división.
 */
int es_par(int n) 
{
    return n % 2 == 0;
}