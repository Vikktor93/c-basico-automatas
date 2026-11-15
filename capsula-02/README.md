# Cápsula 02 - Hola, mundo

**Tema:** VS Code conectado a WSL, el ciclo editar - compilar - ejecutar y cómo leer un error de compilación.

## Actividad

Modifica `hola.c` para que salude con **tu nombre** en vez de «mundo».

```
Hola, María Pérez
```

## Compilar y ejecutar

Como en la cápsula, desde esta carpeta:

```bash
cd ~/c-basico-automatas/capsula-02
gcc -Wall -Wextra -g hola.c -o hola
./hola
```

O desde la raíz del repositorio, con `make`:

```bash
cd ~/c-basico-automatas
make DIR=capsula-02
./build/capsula-02/hola
```

## Probar

```bash
make probar DIR=capsula-02
```

La prueba revisa que:

- El programa compile **sin advertencias**.
- La salida empiece con `Hola, ` y **no** sea `Hola, mundo`.
- `main` retorne 0.

## Entregar

Haz commit y push en tu rama (ver [flujo del estudiante](../docs/03-flujo-estudiante.md)):

```bash
git add capsula-02/hola.c
git commit -m "Cápsula 02: saludo con mi nombre"
git push
```
