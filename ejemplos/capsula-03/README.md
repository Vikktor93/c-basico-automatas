# Ejemplos - Cápsula 03: Anatomía de un programa en C

Programas de la cápsula 03. **No se evalúan**: úsalos como apunte.

| Archivo | Muestra | Salida |
|---|---|---|
| [`salida.c`](salida.c) | `main` retorna 1: el código de salida | `Algo salió mal` y `echo $?` muestra `1` |
| [`formatos.c`](formatos.c) | Un formato de `printf` para cada tipo | Ver abajo |
| [`escapes.c`](escapes.c) | `\t`, `\"` y `\\` dentro de un texto | Ver abajo |
| [`malformato.c`](malformato.c) | **Error a propósito:** `%d` con un `double` | Un número sin sentido, distinto cada vez |
| [`promedio.c`](promedio.c) | Comentarios y estilo | `5.8` |

## Salidas

**`salida.c`**

```
$ ./salida
Algo salió mal
$ echo $?
1
$ ./salida && echo "esto no se imprime"
Algo salió mal
```

`&&` ejecuta lo siguiente solo si el programa anterior retornó 0.

**`formatos.c`**

```
Edad: 20
Nota: 6.500000
Nota: 6.5
Letra: A
Curso: Automatas
Tamaño: 4 bytes
Hex: ff
100%
a       b
```

**`escapes.c`**

```
a       b
Dijo "hola"
C:\temp
```

**`malformato.c`**: gcc avisa al compilar, y hasta sugiere la corrección:

```
malformato.c:18:20: warning: format '%d' expects argument of type 'int', but argument 2 has type 'double' [-Wformat=]
```

Al ejecutarlo imprime un número sin sentido, por ejemplo `Nota: -1869674856`. Corrígelo cambiando `%d` por `%.1f`.

## Para experimentar

- En `formatos.c`, cambia `%.1f` por `%.3f` o `%8.2f`. ¿Qué hace el número antes del punto?
- En `salida.c`, cambia `return 1;` por `return 42;` y revisa `echo $?`.
- Mira la primera etapa de gcc con cualquiera de ellos: `gcc -E promedio.c | wc -l`. ¿Qué pasó con el comentario?
