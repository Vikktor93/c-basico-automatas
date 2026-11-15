# 3. Flujo de trabajo del estudiante

Guía para trabajar y entregar en **c-basico-automatas**. Sigue los pasos en orden. La parte A se hace **una sola vez** y la parte B se repite **en cada cápsula**.

> **Regla a seguir:** trabaja siempre en **tu rama** `estudiante/nombre-apellido`. Nunca en `main`.

---

## Antes de empezar

- [ ] Completaste [Preparar el entorno de C](01-entorno-c.md): `gcc --version` responde dentro de Ubuntu.
- [ ] Completaste [Configurar Git y GitHub](02-git-y-github.md): `gh auth status` dice que iniciaste sesión.
- [ ] **Aceptaste la invitación** al repositorio.

---

## A. Primera vez

### 1. Clonar el repositorio

En la terminal de Ubuntu, en tu carpeta personal:

```bash
cd ~
git clone https://github.com/Vikktor93/c-basico-automatas.git
cd c-basico-automatas
```

> Clona **dentro de Ubuntu** (`~`), no en `/mnt/c/...`. En el disco de Windows todo es más lento y pueden aparecer problemas de permisos.

### 2. Crear tu rama

Usa tu nombre y apellido en minúsculas, sin tildes ni ñ:

```bash
git checkout -b estudiante/nombre-apellido
```

Comprueba en qué rama estás (la actual aparece con `*`):

```bash
git branch
```

### 3. Abrir el repositorio en VS Code

```bash
code .
```

Revisa que abajo a la izquierda diga **`WSL: Ubuntu`**. Abajo a la izquierda también aparece el nombre de tu rama.

### 4. Probar que todo compila

```bash
make
./build/capsula-02/hola
```

Debes ver `Hola, mundo`.

---

## B. En cada cápsula

### 1. Asegúrate de estar en tu rama

```bash
git branch
```

Si no estás en la tuya:

```bash
git checkout estudiante/nombre-apellido
```

### 2. Lee el enunciado y desarrolla la actividad

Cada cápsula tiene su carpeta con un `README.md` que explica la actividad. Por ejemplo, para la cápsula 03:

```bash
code capsula-03/README.md       # lee el enunciado
code capsula-03/ficha.c         # completa los TODO
```

### 3. Compila y prueba

```bash
make DIR=capsula-03                 # compila solo esa cápsula
./build/capsula-03/ficha            # ejecuta
make probar DIR=capsula-03          # corre la prueba automática
```

Antes de subir, compila como lo hará GitHub, donde **las advertencias cuentan como errores**:

```bash
make estricto DIR=capsula-03
```

Si no aparece ninguna advertencia y la prueba muestra `✓`, está lista.

### 4. Guarda tus cambios (commit)

Puedes hacer varios commits durante la actividad. **Mientras más pequeños, mejor.**

```bash
git status                                   # qué archivos cambiaron
git add capsula-03/ficha.c                   # prepara el archivo
git commit -m "Agrega formatos de la ficha"  # guarda con un mensaje claro
```

Al terminar la cápsula, el último commit lleva su número:

```bash
git commit -m "Cápsula 03: ficha con mis datos"
```

> **Revisa `git status` antes de `git add .`**. Solo deben aparecer archivos `.c` o `.md`. Si aparece un ejecutable (`hola`, `ficha`, `paridad`), algo falló en el `.gitignore`: avisa al docente.

### 5. Sube tu rama a GitHub (push)

**La primera vez** se indica el destino con `-u`:

```bash
git push -u origin estudiante/nombre-apellido
```

**Las siguientes veces** basta con:

```bash
git push
```

### 6. Entrega: Pull Request en borrador (solo la primera vez)

1. Entra a <https://github.com/Vikktor93/c-basico-automatas>. Aparecerá un aviso amarillo con el botón **Compare & pull request**.
   - Si no aparece: pestaña **Pull requests** → **New pull request** → *base:* `main` ← *compare:* `estudiante/nombre-apellido`.
2. Título: **`Entrega - Nombre Apellido`**.
3. La descripción ya trae una plantilla: completa tu nombre y marca las cápsulas entregadas.
4. Abre la flecha del botón verde y elige **Create draft pull request**.

También puedes crearlo desde la terminal:

```bash
gh pr create --draft --base main --title "Entrega - Nombre Apellido" --fill
```

> **El PR nunca se fusiona** (no presiones *Merge*). Es tu carpeta de entrega: ahí el docente revisa y deja comentarios.

**En las cápsulas siguientes no abras un PR nuevo.** Cada `git push` actualiza automáticamente el mismo PR. Edita la descripción para marcar las cápsulas nuevas.

### 7. Revisa la compilación automática

En tu PR, baja hasta la sección de **checks**. Hay uno por cápsula:

| Ícono | Significado |
|---|---|
| 🟡 | Compilando y probando (tarda menos de un minuto) |
| ✓ verde | Compila sin advertencias y pasa la prueba |
| ✗ roja | Hay advertencias, errores o la prueba falló |

Es normal ver ✗ en las cápsulas que **todavía no haces**. Lo importante es que las que entregaste estén en ✓.

Si una está en ✗: clic en **Details**, abre el paso que falló y lee el mensaje. Es el mismo que verías con `make estricto` o `make probar` en tu computador.

### 8. Revisa los comentarios del docente

En tu PR → pestaña **Conversation** o **Files changed**. Corrige lo que se indique, haz commit y push. Los cambios aparecen en el mismo PR.

---

## C. Cuando el docente agrega una cápsula nueva a `main`

El docente avisará cuando publique una cápsula nueva (por ejemplo, `capsula-05/`). Para traerla a tu rama:

```bash
git checkout main
git pull
git checkout estudiante/nombre-apellido
git merge main
git push
```

> Si `git merge` abre VS Code pidiendo un mensaje, guarda y cierra la pestaña: el mensaje por defecto sirve.

Si aparece un **conflicto**, revisa [problemas frecuentes](05-problemas-frecuentes.md#conflicto-al-hacer-merge).

---

## D. Ver la solución del docente

Cuando cierra el plazo de una cápsula, el docente publica la rama `docente/solucion`.

**Opción 1 (recomendada), en GitHub:** selector de ramas → `docente/solucion` → navega por los archivos. Para ver la solución de **una cápsula específica**, en el mismo selector abre la pestaña **Tags** y elige, por ejemplo, `capsula-03`.

**Opción 2, en tu computador, para ejecutarla:**

```bash
git status                       # no debes tener cambios sin commit
git fetch
git checkout docente/solucion
make probar
```

Cuando termines, **vuelve a tu rama**. No trabajes en la del docente:

```bash
git checkout estudiante/nombre-apellido
```

**Opción 3, comparar tu código con la solución:**

```bash
git fetch
git diff estudiante/nombre-apellido origin/docente/solucion -- capsula-03/
```

---

## Resumen de comandos

| Momento | Comando |
|---|---|
| Clonar (una vez) | `git clone https://github.com/Vikktor93/c-basico-automatas.git` |
| Crear mi rama (una vez) | `git checkout -b estudiante/nombre-apellido` |
| Ver en qué rama estoy | `git branch` |
| Cambiar a mi rama | `git checkout estudiante/nombre-apellido` |
| Compilar una cápsula | `make DIR=capsula-NN` |
| Probar una cápsula | `make probar DIR=capsula-NN` |
| Compilar como GitHub | `make estricto DIR=capsula-NN` |
| Ver cambios | `git status` |
| Guardar cambios | `git add <archivo>` y `git commit -m "mensaje"` |
| Subir (primera vez) | `git push -u origin estudiante/nombre-apellido` |
| Subir (siguientes) | `git push` |
| Crear el PR (una vez) | `gh pr create --draft --base main --title "Entrega - Nombre Apellido" --fill` |
| Traer una cápsula nueva | `git checkout main`, `git pull`, `git checkout <mi-rama>`, `git merge main` |
