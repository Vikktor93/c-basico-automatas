# Cápsula 06 - Pregunta de reflexión

En la cápsula 04, `intercambiar(int x, int y)` no cambiaba `a` ni `b`. En esta cápsula la escribiste como `intercambiar(int *x, int *y)` y la llamaste con `intercambiar(&a, &b)`.

## Preguntas

1. ¿Qué recibe ahora la función: los valores de `a` y `b`, o algo distinto? ¿Qué significa `*x = *y` dentro de ella?
2. ¿Por qué `scanf("%d", &n)` necesita el `&`, y `printf("%d\n", n)` no?

Responde en tres a cinco líneas, con tus palabras.

## Tu respuesta

<!-- Escribe tu respuesta debajo de esta línea. -->
Ahora la función recibe las direcciones de `a` y `b`, no sus valores. Con esas direcciones puede llegar a las variables originales y cambiarlas. `*x = *y` significa "pon en la casa de `x` lo que hay en la casa de `y`".

`printf` solo lee el valor de `n`, así que le basta una copia. `scanf` tiene que escribir en `n`, así que necesita saber dónde está ubicada, y por eso lleva `&`.
