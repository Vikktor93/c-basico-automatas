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

Los valores de a y b no cambian ya que lo que se envía a la función cambiar es el valor de a y b, entonces x e y se transforman en ese esos valores. Por ello es que las variables originales no cambian su valor, simplemente envian una copia del suyo a la función.