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

bool es_par(int num);

int main(void)
{
    /* TODO 2: escribe un ciclo for de 1 a 10 que, usando es_par,
     * imprima una línea por número:
     *   1 es impar
     *   2 es par
     *   ...
     *   10 es par
     */

    for (int i = 1; i <= 10; i++) {
        if (es_par(i)) {
            printf("%i es par\n", i);
        } else {
            printf("%i es impar\n", i);
        }
    };

    return 0;
}

/* TODO 3: escribe aquí la DEFINICIÓN de es_par.
 *   Retorna true si n es par y false si no.
 *   Pista: el operador % entrega el resto de la división.
 */


 bool es_par(int num) {
    if (num % 2 == 0) {
        return true;
    }
    return false; 
}
