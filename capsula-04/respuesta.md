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
La función `intercambiar` no cambio los valores de `a` y `b` porque en C los parámetros `x` e `y` reciben copias de esos valores. Por eso, los cambios realizados dentro de la funcion solo afectan a las copias y no a las variables originales.
