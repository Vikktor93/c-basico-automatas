# Cápsula 06 - Pregunta de reflexión

En la cápsula 04, `intercambiar(int x, int y)` no cambiaba `a` ni `b`. En esta cápsula la escribiste como `intercambiar(int *x, int *y)` y la llamaste con `intercambiar(&a, &b)`.

## Preguntas

1. ¿Qué recibe ahora la función: los valores de `a` y `b`, o algo distinto? ¿Qué significa `*x = *y` dentro de ella?
2. ¿Por qué `scanf("%d", &n)` necesita el `&`, y `printf("%d\n", n)` no?

Responde en tres a cinco líneas, con tus palabras.

## Tu respuesta

1. Ahora la función recibe las direcciones de `a` y `b`, no sus valores:
   `x` e `y` son punteros que apuntan a esas variables. `*x = *y`
   significa "escribe, en la variable a la que apunta x, el valor que
   hay en la variable a la que apunta y". Por eso cambia el `a` de main
   y no una copia.

2. `scanf` tiene que escribir el número leído en `n`, así que necesita
   saber dónde está `n` en memoria: por eso recibe `&n`. `printf` solo
   lee el valor de `n` para mostrarlo, y le basta una copia del valor.

