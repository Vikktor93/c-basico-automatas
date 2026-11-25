/*
 * cadenas.c - Cápsula 05
 *
 * Completa los TODO. Al terminar, borra la línea que imprime "TODO"
 *
 * Regla: NO uses <string.h> (ni strlen ni ninguna otra función de ahí).
 * La idea es que recorras tú mismo cada cadena hasta encontrar '\0'.
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

    /* TODO 4: calcula con sizeof cuántas palabras tiene el arreglo,
     *   en vez del 1 fijo (por ahora solo se procesa la primera).
     *   Pista: el tamaño de todo el arreglo dividido por el tamaño de
     *   una palabra (palabras[0]).
     */
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

/* TODO 1: largo retorna cuántos símbolos tiene s, sin contar el '\0'.
 *   Ejemplos: largo("0110") = 4, largo("") = 0
 */
int largo(const char s[])
{
    int n = 0;
    while (s[n] != '\0'){
        n++;
    }
        
    return n;
}

/* TODO 2: contar retorna cuántas veces aparece el carácter c en s.
 *   Ejemplos: contar("0110", '1') = 2, contar("", '1') = 0
 */
int contar(const char s[], char c)
{
    int veces = 0;
    for (int i = 0; s [i] != '\0'; i++){
        if (s[i]== c){
            veces++;
 
        }
    }
    
    return veces;
}

/* TODO 3: en_alfabeto retorna true si TODOS los símbolos de s están en
 *   sigma, y false si alguno no está.
 *   Ejemplos: en_alfabeto("0110", "01") = true
 *             en_alfabeto("10a1", "01") = false
 *             en_alfabeto("", "01")     = true   (λ está en todo Σ*)
 *   Pista: para cada símbolo de s, usa contar sobre sigma.
 */
bool en_alfabeto(const char s[], const char sigma[])
{
    for (int i = 0; s[i] !='\0'; i++){
        if(contar (sigma, s[i])==0 ){
            return false;
        }
    }
    
    return true;
}
