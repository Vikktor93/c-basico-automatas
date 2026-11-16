# Ejemplos de las cápsulas

Esta carpeta contiene **los programas que aparecen en las cápsulas de video**, listos para compilar y modificar. Úsalos como apunte: ejecútalos, cámbialos y observa qué pasa.

> **Esta carpeta no se evalúa.** No hay pruebas automáticas ni checks para ella, y no necesitas entregar nada aquí. Las actividades evaluadas están en las carpetas `capsula-NN/` de la raíz.

| Carpeta | Cápsula | Temas |
|---|---|---|
| [`capsula-03/`](capsula-03/README.md) | 03 - Anatomía de un programa en C | Código de salida, `printf` y sus formatos, secuencias de escape, comentarios |
| [`capsula-04/`](capsula-04/README.md) | 04 - C para quien ya programa | Tipos y tamaños, `char`, división entera, desbordamiento, verdad, `switch`, prototipos, paso por valor |

## Cómo compilarlos

**Uno por uno**, como en las cápsulas, desde su carpeta:

```bash
cd ~/c-basico-automatas/ejemplos/capsula-04
gcc -Wall -Wextra -g swap.c -o swap
./swap
```

**Todos los de una cápsula**, con `make`, desde la raíz del repositorio:

```bash
cd ~/c-basico-automatas
make DIR=ejemplos/capsula-04
./build/ejemplos/capsula-04/swap
```

## Ejemplos con errores a propósito

Algunos programas tienen un error **intencional**, para que veas la advertencia de gcc y lo que pasa al ejecutarlos. Lo dice el comentario al inicio de cada archivo:

| Archivo | Error a propósito |
|---|---|
| `capsula-03/malformato.c` | `%d` con un `double` |
| `capsula-04/asignacion.c` | `=` en vez de `==` dentro de un `if` |
| `capsula-04/switch.c` | Falta un `break` |
| `capsula-04/prototipo_sin.c` | Función usada antes de declararla |

Por eso **no uses `make estricto`** en esta carpeta: con `-Werror` esos cuatro no compilan. Ese es justamente el punto.

## ¿Puedo modificarlos?

Sí, en tu rama. Si no quieres que tus cambios aparezcan en tu Pull Request, descártalos antes de hacer commit:

```bash
git restore ejemplos/
```

Los ejecutables que compiles aquí no se suben: el `.gitignore` los excluye.
