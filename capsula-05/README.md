# Cápsula 05 - Arreglos y cadenas

**Tema:** arreglos, `sizeof`, cadenas como arreglos de `char` terminados en `'\0'`, arreglos de cadenas y recorrido hasta el `'\0'`.

## Actividad

### 1. Completa `cadenas.c`

Implementa tres funciones **sin usar `<string.h>`**:

| Función | Retorna | Ejemplo |
|---|---|---|
| `int largo(const char s[])` | Cantidad de símbolos de `s`, sin el `'\0'` | `largo("0110")` = 4 |
| `int contar(const char s[], char c)` | Cuántas veces aparece `c` en `s` | `contar("0110", '1')` = 2 |
| `bool en_alfabeto(const char s[], const char sigma[])` | `true` si todos los símbolos de `s` están en `sigma` | `en_alfabeto("10a1", "01")` = `false` |

Además, en `main` calcula con `sizeof` cuántas palabras tiene el arreglo (TODO 4).

La salida completa esperada está en [`esperado.txt`](esperado.txt). Al terminar, **borra la línea** que imprime `TODO` y las líneas `(void)...` de cada función.

> **Relación con el curso:** `largo` es |w|, `contar(w, '1')` es |w|₁, y `en_alfabeto(w, "01")` responde si w ∈ {0,1}*.

### 2. Responde la pregunta de `respuesta.md`

¿Por qué `sizeof` y `largo` dan resultados distintos, y qué le falta a un arreglo sin espacio para el `'\0'`?

## Compilar y ejecutar

```bash
cd ~/c-basico-automatas
make DIR=capsula-05
./build/capsula-05/cadenas
```

## Probar

```bash
make probar DIR=capsula-05
```

La prueba revisa cuatro cosas, en este orden:

1. Que `cadenas.c` **no incluya** `<string.h>`.
2. Que la salida coincida con `esperado.txt`. Las líneas con `-` son las esperadas y las con `+` las de tu programa.
3. Que tus funciones respondan bien con **otras cadenas**, distintas a las de `main`. Si falla, verás qué caso no se cumple.
4. Que escribiste tu respuesta en `respuesta.md`.

## Entregar

```bash
git add capsula-05/cadenas.c capsula-05/respuesta.md
git commit -m "Cápsula 05: cadenas y respuesta"
git push
```

Luego marca la cápsula 05 en la descripción de tu Pull Request.
