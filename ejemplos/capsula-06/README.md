# Ejemplos - Cápsula 06: Punteros

Programas de la cápsula 06. **No se evalúan**: úsalos como apunte.

## Direcciones y punteros

| Archivo | Muestra | Salida |
|---|---|---|
| [`direccion.c`](direccion.c) | `&x` y `%p`: toda variable tiene una dirección | `x = 42  vive en 0x7ffc...` (cambia en cada ejecución) |
| [`puntero.c`](puntero.c) | `int *p = &x;` y `*p = 25` cambia `x` | `x = 25` |
| [`swap.c`](swap.c) | El intercambio que sí intercambia. Compáralo con [`../capsula-04/swap.c`](../capsula-04/swap.c) | `en main: a=2 b=1` |
| [`leer_numero.c`](leer_numero.c) | Por qué `scanf` necesita `&` | `echo 21 \| ./leer_numero` → `El doble de 21 es 42` |

## Punteros y arreglos

| Archivo | Muestra | Salida |
|---|---|---|
| [`arreglo_puntero.c`](arreglo_puntero.c) | `v` es `&v[0]`, `*(v+i)` es `v[i]`, y `p++` avanza un elemento | Direcciones separadas por 4 bytes |
| [`recorrer.c`](recorrer.c) | Recorrer una cadena con un puntero hasta el `'\0'` | `largo("abba") = 4` |
| [`dos_resultados.c`](dos_resultados.c) | Parámetros de salida: `dividir(a, b, &q, &r)` | `17 / 5 = 3, resto 2` |

## Errores a propósito

| Archivo | Error | Qué pasa |
|---|---|---|
| [`nulo.c`](nulo.c) | Usar `*p` cuando `p` es `NULL` | `Segmentation fault` |
| [`sin_inicializar.c`](sin_inicializar.c) | Puntero sin inicializar | Advertencia de gcc; al ejecutar puede «funcionar» o caerse |
| [`local.c`](local.c) | Retornar la dirección de una variable local | Advertencia de gcc; `p` termina en `NULL` |

Compilando con `gcc -Wall -Wextra -g` (gcc 13, Ubuntu 24.04):

```
local.c:17:12: warning: function returns address of local variable [-Wreturn-local-addr]
sin_inicializar.c:18:8: warning: 'p' is used uninitialized [-Wuninitialized]
```

`nulo.c` **no produce advertencia**. Con el sanitizador, el error indica la línea:

```bash
gcc -Wall -Wextra -g -fsanitize=address nulo.c -o nulo
./nulo
```

```
ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 ...
    #0 ... in main nulo.c:29
```

> La dirección `0x000000000000` es `NULL`. Cuando veas ese número en un error, busca un puntero que no revisaste.
