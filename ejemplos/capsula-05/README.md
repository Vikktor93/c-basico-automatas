# Ejemplos - Cápsula 05: Arreglos y cadenas

Programas de la cápsula 05. **No se evalúan**: úsalos como apunte.

## Arreglos

| Archivo | Muestra | Salida |
|---|---|---|
| [`arreglo.c`](arreglo.c) | Declarar, recorrer y medir un arreglo con `sizeof` | `sizeof notas = 20 bytes, cada int = 4, n = 5` |
| [`fuera_limites.c`](fuera_limites.c) | **Error a propósito:** escribir en `v[5]` | Sin aviso de gcc; con `-fsanitize=address` se detiene en la línea 21 |

## Cadenas

| Archivo | Muestra | Salida |
|---|---|---|
| [`cadena_nul.c`](cadena_nul.c) | `"hola"` ocupa 5 bytes: el último es `'\0'` | `s[4] = '\0'  código 0` |
| [`largo_sizeof.c`](largo_sizeof.c) | `sizeof` no es el largo, y dentro de una función un arreglo es un puntero (**advertencia a propósito**) | `20`, `5` y `8` |
| [`comillas.c`](comillas.c) | **Error a propósito:** `"a"` en vez de `'a'` | `c` termina con cualquier número |
| [`comparar.c`](comparar.c) | **Error a propósito:** comparar cadenas con `==` en vez de `strcmp` | `con ==: distintas (?)` |
| [`copiar.c`](copiar.c) | Un arreglo no se asigna con `=`: se copia símbolo a símbolo | `0110` y `01101` |
| [`palabras.c`](palabras.c) | Un arreglo de cadenas: un lenguaje finito en C | `L[1] = ab ...` |

## Leer cadenas

| Archivo | Muestra | Cómo ejecutarlo |
|---|---|---|
| [`leer_linea.c`](leer_linea.c) | `fgets` y el `'\n'` que guarda | `echo 0110 \| ./leer_linea` |
| [`argumentos.c`](argumentos.c) | `argc` y `argv`: las cadenas de la línea de comandos | `./argumentos 0110 abba λ` |

## Las advertencias de los errores a propósito

Compilando con `gcc -Wall -Wextra -g` (gcc 13, Ubuntu 24.04):

```
comillas.c:17:14: warning: initialization of 'char' from 'char *' makes integer from pointer without a cast [-Wint-conversion]
comparar.c:18:15: warning: comparison with string literal results in unspecified behavior [-Waddress]
largo_sizeof.c:17:61: warning: 'sizeof' on array function parameter 's' will return size of 'char *' [-Wsizeof-array-argument]
```

Desde gcc 14, `comillas.c` ya no compila: la advertencia pasa a ser un error.

`fuera_limites.c` **no produce advertencia**: el error aparece al ejecutar. Por eso conviene probar con el sanitizador:

```bash
gcc -Wall -Wextra -g -fsanitize=address fuera_limites.c -o fuera_limites
./fuera_limites
```

```
ERROR: AddressSanitizer: stack-buffer-overflow ...
    #0 ... in main fuera_limites.c:21
```
