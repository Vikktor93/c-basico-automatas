/*
 * punteros.c - Cápsula 06
 *
 * Completa los TODO. Al terminar, borra la línea que imprime "TODO"
 *
 * Recuerda:
 *   &x   la dirección de x           int *p = &x;
 *   *p   lo que hay en esa dirección  *p = 5;  (cambia x)
 */
#include <stdio.h>

void intercambiar(int *x, int *y);
void contar_simbolos(const char *w, int *ceros, int *unos);
const char *buscar(const char *w, char c);

int main(void)
{
    /* Parte 1: el intercambio que en la cápsula 04 no funcionaba */
    int a = 1, b = 2;
    printf("antes:   a=%d b=%d\n", a, b);

    /* TODO 4: llama a intercambiar para que cambie a y b.
     *   Pista: la función no necesita los valores de a y b, sino
     *   dónde están guardados.
     */
    intercambiar (&a, &b);
    printf("después: a=%d b=%d\n", a, b);

    /* Parte 2: una función que "retorna" dos resultados */
    const char *palabras[] = {"", "0110", "1000", "111"};
    int n = sizeof palabras / sizeof palabras[0];

    for (int i = 0; i < n; i++) {
        const char *w = palabras[i];
        int ceros = -1, unos = -1;
        contar_simbolos(w, &ceros, &unos);

        printf("w = %s: %d ceros, %d unos, ", w[0] == '\0' ? "λ" : w, ceros, unos);

        const char *p = buscar(w, '1');
        if (p != NULL)
            printf("primer 1 en la posición %d\n", (int)(p - w));
        else
            printf("no tiene 1\n");
    }

   
    return 0;
}

/* TODO 1: intercambiar cambia los valores de las variables a las que
 *   apuntan x e y.
 */
void intercambiar(int *x, int *y)
{
    int tmp = *x;
    *x =*y;
    *y = tmp;
   
}

/* TODO 2: contar_simbolos cuenta los '0' y los '1' de w y deja los
 *   resultados en *ceros y *unos. Otros símbolos se ignoran.
 *   Ojo: no confíes en el valor que traen *ceros y *unos (main los
 *   inicializa en -1). Asígnales tú el valor inicial.
 *   Ejemplo: w = "0110"  →  *ceros = 2, *unos = 2
 */
void contar_simbolos(const char *w, int *ceros, int *unos)
{
    *ceros = 0;
    *unos = 0;
    for (int i=0; w[i] !='\0'; i++){
        if (w[i] == '0'){
            *ceros = *ceros + 1;
        } else if (w[i] == '1'){
            *unos = *unos + 1;
        }
    }

}

/* TODO 3: buscar retorna un puntero a la PRIMERA aparición de c en w,
 *   o NULL si c no aparece.
 *   Recorre w con el puntero (w++), sin usar índices w[i].
 *   Ejemplo: buscar("1000", '0') retorna w + 1
 */
const char *buscar(const char *w, char c)
{
    while (*w != '\0'){
        if (*w == c) {
            return w;
        }
        w++;
    }   
    return NULL;
}
