/*
 * punteros.c - Cápsula 06
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

    /* Se entregan las direcciones de a y b, no sus valores */
    intercambiar(&a, &b);

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

/* intercambiar cambia los valores de las variables a las que
 * apuntan x e y.
 */
void intercambiar(int *x, int *y)
{
    int tmp = *x;   /* guarda el valor de la variable de x */
    *x = *y;        /* escribe en esa variable el valor de y */
    *y = tmp;       /* escribe en la variable de y el valor guardado */
}

/* contar_simbolos deja en *ceros y *unos la cantidad de '0' y '1' de w. */
void contar_simbolos(const char *w, int *ceros, int *unos)
{
    *ceros = 0;     /* main los dejó en -1: partimos desde 0 */
    *unos = 0;

    for (const char *p = w; *p != '\0'; p++) {
        if (*p == '0')
            (*ceros)++;
        else if (*p == '1')
            (*unos)++;
    }
}

/* buscar retorna un puntero a la primera aparición de c en w,
 * o NULL si c no aparece.
 */
const char *buscar(const char *w, char c)
{
    while (*w != '\0') {
        if (*w == c)
            return w;
        w++;
    }
    return NULL;
}