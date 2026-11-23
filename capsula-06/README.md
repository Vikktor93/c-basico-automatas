# Cápsula 06 - Punteros

**Tema:** direcciones de memoria (`&`), punteros (`*`), paso por referencia, parámetros de salida, `NULL` y recorrido de cadenas con punteros.

## Actividad

### 1. Completa `punteros.c`

| Función | Qué hace | Ejemplo |
|---|---|---|
| `void intercambiar(int *x, int *y)` | Intercambia las variables a las que apuntan `x` e `y` | `a=1, b=2` → `a=2, b=1` |
| `void contar_simbolos(const char *w, int *ceros, int *unos)` | Deja en `*ceros` y `*unos` cuántos `0` y `1` tiene `w` | `"0110"` → 2 y 2 |
| `const char *buscar(const char *w, char c)` | Retorna un puntero a la primera `c` de `w`, o `NULL` | `buscar("1000", '0')` → `w + 1` |

Además, en `main` llama a `intercambiar` para que cambie `a` y `b` (TODO 4).

La salida completa esperada está en [`esperado.txt`](esperado.txt). Al terminar, **borra la línea** que imprime `TODO` y las líneas `(void)...` de cada función.

> **Relación con la cápsula 04:** allá `intercambiar` recibía copias y no cambiaba nada. Aquí recibe **direcciones**, y por eso sí puede modificar las variables de `main`.

### 2. Responde la pregunta de `respuesta.md`

¿Qué recibe ahora `intercambiar`, y por qué `scanf` necesita el `&`?

## Compilar y ejecutar

```bash
cd ~/c-basico-automatas
make DIR=capsula-06
./build/capsula-06/punteros
```

## Probar

```bash
make probar DIR=capsula-06
```

La prueba revisa, en este orden:

1. Que la salida coincida con `esperado.txt`. Las líneas con `-` son las esperadas y las con `+` las de tu programa.
2. Que tus funciones respondan bien con **otros datos**, distintos a los de `main`. Por ejemplo, que `buscar` retorne un puntero **dentro** de la cadena original.
3. Que escribiste tu respuesta en `respuesta.md`.

> Si el programa termina con `Segmentation fault`, casi siempre es un puntero `NULL` o sin inicializar. Compila a mano con `gcc -Wall -Wextra -g -fsanitize=address punteros.c -o punteros` y ejecuta: el mensaje indica la línea exacta.

## Entregar

```bash
git add capsula-06/punteros.c capsula-06/respuesta.md
git commit -m "Cápsula 06: punteros y respuesta"
git push
```

Luego marca la cápsula 06 en la descripción de tu Pull Request.
