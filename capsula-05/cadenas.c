/*
 * cadenas.c - Cápsula 05
 *
 * Regla: NO uses <string.h> (ni strlen ni ninguna otra función de ahí).
 * Cada cadena se recorre a mano hasta encontrar '\0'.
 *
 * "const" en un parámetro significa que la función promete no modificar
 * esa cadena: solo la lee.
 */
#include <stdio.h>
#include <stdbool.h>

int largo(const char s[]);
int contar(const char s[], char c);
bool en_alfabeto(const char s[], const char sigma[]);

int main(void)
{
    /* Un arreglo de cadenas: 5 palabras de hasta 7 símbolos + '\0' */
    char palabras[][8] = {"", "0110", "1001", "10a1", "111"};
    char sigma[] = "01";

    /* Tamaño de todo el arreglo dividido por el tamaño de una palabra */
    int n = sizeof palabras / sizeof palabras[0];

    for (int i = 0; i < n; i++) {
        printf("w = %s: largo %d, %d unos, en {0,1}: %s\n",
               palabras[i][0] == '\0' ? "λ" : palabras[i],
               largo(palabras[i]),
               contar(palabras[i], '1'),
               en_alfabeto(palabras[i], sigma) ? "sí" : "no");
    }

    return 0;
}

/* largo retorna cuántos símbolos tiene s, sin contar el '\0'. */
int largo(const char s[])
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

/* contar retorna cuántas veces aparece el carácter c en s. */
int contar(const char s[], char c)
{
    int veces = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            veces++;
    return veces;
}

/* en_alfabeto retorna true si TODOS los símbolos de s están en sigma. */
bool en_alfabeto(const char s[], const char sigma[])
{
    for (int i = 0; s[i] != '\0'; i++)
        if (contar(sigma, s[i]) == 0)
            return false;
    return true;
}