/*
 * paridad.c - Cápsula 04
 *
 * Completa los TODO. Al terminar, borra la línea que imprime "TODO"
 */
#include <stdio.h>
#include <stdbool.h>

bool es_par(int n){
    if (n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}
int main(void){
    for (int n = 1; n <= 10; n++) {
        if (es_par(n) == true) {
            printf("%d es par\n", n);
        } else {
            printf("%d es impar\n", n);
        }
    }    
    return 0;
}

/* TODO 3: escribe aquí la DEFINICIÓN de es_par.
 *   Retorna true si n es par y false si no.
 *   Pista: el operador % entrega el resto de la división.
 */
