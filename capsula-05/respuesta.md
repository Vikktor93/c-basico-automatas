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

<!-- Escribe tu respuesta debajo de esta línea. -->

