# Cápsula 04 - C para quien ya programa

**Tema:** tipos y operadores, verdad en C, control de flujo, funciones, prototipos y paso por valor.

## Actividad

### 1. Completa `paridad.c`

- Una función `bool es_par(int n)`, con su **prototipo antes de `main`** y su definición después.
- Un ciclo `for` del 1 al 10 que la use para imprimir:

```
1 es impar
2 es par
3 es impar
...
10 es par
```

La salida completa esperada está en [`esperado.txt`](esperado.txt). Al terminar, **borra la línea** que imprime `TODO`.

### 2. Responde la pregunta de `respuesta.md`

¿Por qué `intercambiar` no cambió `a` y `b`? Escribe tu respuesta en el mismo archivo.

## Compilar y ejecutar

```bash
cd ~/c-basico-automatas
make DIR=capsula-04
./build/capsula-04/paridad
```

## Probar

```bash
make probar DIR=capsula-04
```

La prueba compara tu salida, línea por línea, con `esperado.txt`. Si algo no coincide, muestra la diferencia:

- Las líneas con `-` son las esperadas.
- Las líneas con `+` son las que imprimió tu programa.

Además, el programa debe compilar **sin advertencias**: si llamas a `es_par` sin prototipo, gcc avisa y la prueba de GitHub falla.

## Entregar

```bash
git add capsula-04/paridad.c capsula-04/respuesta.md
git commit -m "Cápsula 04: paridad y respuesta"
git push
```
