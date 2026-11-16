# Cápsula 03 - Anatomía de un programa en C

**Tema:** las etapas de gcc (preprocesador, compilador, enlazador), `#include`, el código de salida de `main` y `printf` a fondo.

## Actividad

Completa `ficha.c` para que imprima tu ficha con cuatro datos, cada uno con **su formato**:

| Dato | Tipo | Formato |
|---|---|---|
| Nombre | texto | `%s` |
| Inicial | `char` | `%c` |
| Edad | `int` | `%d` |
| Promedio de notas | `double` | `%.1f` |

Salida de ejemplo:

```
Nombre: María Pérez
Inicial: M
Edad: 20
Promedio: 5.8
```

Al terminar, **borra la línea** que imprime `TODO`.

## Compilar y ejecutar

```bash
cd ~/c-basico-automatas
make DIR=capsula-03
./build/capsula-03/ficha
echo $?          # debe mostrar 0
```

## Probar

```bash
make probar DIR=capsula-03
```

La prueba revisa que:

- El programa compile **sin advertencias**. Si usas un formato equivocado (por ejemplo `%d` con un `double`), gcc avisa y la prueba falla.
- Imprima al menos 4 líneas y ninguna diga `TODO`.
- `main` retorne 0.

## Entregar

```bash
git add capsula-03/ficha.c
git commit -m "Cápsula 03: ficha con mis datos"
git push
```