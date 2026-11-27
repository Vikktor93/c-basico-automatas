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
Porque en C los argumentos se pasan por valor: intercambiar recibe copias de a y b, intercambia esas copias dentro de la función y los originales en main no cambian. Para modificarlos habría que pasar sus direcciones con punteros.
