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
la función recibe copias de los valores de a y b.. no son las originales
lo que se intercambia son esas valores(x e y), y desaparecen cuando la función termina
los valores originales no se tocaron , por eso en main siguen igual
