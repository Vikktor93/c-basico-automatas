# Ejemplos - Cápsula 04: C para quien ya programa

Programas de la cápsula 04. **No se evalúan**: úsalos como apunte.

## Tipos y operadores

| Archivo | Muestra | Salida |
|---|---|---|
| [`tamanos.c`](tamanos.c) | Cada tipo tiene un tamaño fijo (`sizeof`) | `char: 1`, `int: 4`, `long: 8`, `float: 4`, `double: 8` |
| [`letras.c`](letras.c) | Un `char` es un número | `a es 97`, `b`, `7` |
| [`division.c`](division.c) | Entre enteros, la división es entera | `3 1` y `3.000000 3.500000` |
| [`overflow.c`](overflow.c) | Cuando un `int` no alcanza | `2147483647` y `-2147483648` |

## Control de flujo

| Archivo | Muestra | Salida |
|---|---|---|
| [`verdad.c`](verdad.c) | 0 es falso; cualquier otro valor es verdadero | `1 0`, `42 es verdadero`, `1` |
| [`asignacion.c`](asignacion.c) | **Error a propósito:** `=` en vez de `==` en un `if` | `x no es cero` |
| [`switch.c`](switch.c) | **Error a propósito:** falta un `break` | `uno` y `dos` |

## Funciones

| Archivo | Muestra | Salida |
|---|---|---|
| [`prototipo_sin.c`](prototipo_sin.c) | **Error a propósito:** función usada antes de declararla | `16`, con advertencia |
| [`prototipo_con.c`](prototipo_con.c) | El prototipo resuelve la advertencia | `16` |
| [`swap.c`](swap.c) | Paso por valor: `intercambiar` recibe copias | `dentro: x=2 y=1` y `en main: a=1 b=2` |

## Las advertencias de los errores a propósito

Compilando con `gcc -Wall -Wextra -g` (gcc 13, Ubuntu 24.04):

```
asignacion.c:18:9: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
switch.c:20:9: warning: this statement may fall through [-Wimplicit-fallthrough=]
prototipo_sin.c:15:20: warning: implicit declaration of function 'cuadrado' [-Wimplicit-function-declaration]
```

Desde gcc 14, `prototipo_sin.c` ya no compila: la advertencia pasa a ser un error.

## Detectar el desbordamiento

`overflow.c` no produce ninguna advertencia al compilar: el problema ocurre al ejecutar. Para detectarlo:

```bash
gcc -Wall -Wextra -g -fsanitize=undefined overflow.c -o overflow
./overflow
```

```
2147483647
overflow.c:...: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'
-2147483648
```

## Para experimentar

- En `division.c`, cambia `(double) a / b` por `(double) (a / b)`. ¿Por qué el resultado vuelve a ser 3?
- En `letras.c`, imprime `'A' + 32` con `%c`. ¿Qué letra aparece y por qué?
- En `switch.c`, agrega el `break` que falta y compila de nuevo: la advertencia desaparece.
- En `swap.c`, imprime `a` y `b` **antes** de llamar a `intercambiar`. ¿Cambia algo?
