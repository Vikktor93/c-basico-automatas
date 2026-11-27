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

1. `sizeof s` mide toda la memoria del arreglo: las 5 letras de "lemas"
   más el '\0' final, o sea 6 bytes. `largo(s)` recorre la cadena solo
   hasta encontrar el '\0' y no lo cuenta, por eso da 5.

2. A `t` le falta espacio para el '\0': "lemas" necesita 6 bytes y `t`
   tiene 5. Sin terminador, `largo(t)` no sabe dónde parar y sigue
   leyendo la memoria que viene después del arreglo hasta encontrar un 0
   por casualidad. Por eso puede dar cualquier número o hacer que el
   programa falle.