# Cápsula 05 - Pregunta de reflexión

Considera este código, que usa tu función `largo`:

```c
char s[] = "lemas";
char t[5] = "lemas";

printf("%zu %d\n", sizeof s, largo(s));
printf("%d\n", largo(t));
```

La primera línea imprime `6 5`.

## Preguntas

1. ¿Por qué `sizeof s` y `largo(s)` dan resultados distintos?
2. `t` tiene espacio justo para las 5 letras. ¿Qué le falta a `t` y por qué `largo(t)` puede imprimir cualquier número (o hacer que el programa falle)?

Responde en tres a cinco líneas, con tus palabras.

## Tu respuesta

1. `sizeof s` y `largo(s)` dan resultados distintos porque `sizeof` cuenta todos los espacios que ocupa el arreglo, incluyendo el caracter final `'\0'`. En cambio, `largo` cuenta solamente las letras.

2. A `t` le falta el caracter `'\0'`, que indica donde termina una cadena. Por eso, `largo(t)` puede seguir leyendo memoria que no pertenece al arreglo, entregar un resultado incorrecto o incluso provocar que el programa falle.

