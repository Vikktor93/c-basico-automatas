# Cápsula 04 - Pregunta de reflexión

En la cápsula vimos esta función:

```c
void intercambiar(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
```

Al llamar `intercambiar(a, b)` desde `main`, los valores de `a` y `b` **no cambian**.

## Pregunta

¿Por qué `intercambiar` no cambió `a` y `b`? Responde en dos o tres líneas, con tus palabras.

## Tu respuesta

<!-- Escribe tu respuesta debajo de esta línea. -->

Porque C pasa los argumentos por valor, asi que x e y son solo copias de a y b, y no las variables originales.
Lo que se intercambia dentro de la función son esas copias, por lo que a y b en main no cambian.