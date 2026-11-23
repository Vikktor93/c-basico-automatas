# 4. Flujo de trabajo del docente

Guía para administrar **c-basico-automatas**: configuración inicial, solución de referencia, revisión de entregas y publicación de cápsulas y soluciones.

> **Regla a seguir:** `main` contiene solo el **código base** de las cápsulas (esqueletos con TODO). La solución vive en `docente/solucion` y **se sube a GitHub solo cuando cierra el plazo** de cada cápsula.

---

## A. Configuración inicial (una sola vez)

### 1. Subir el contenido base a `main`

El repositorio ya existe en GitHub, vacío. Desde Ubuntu, con `git` y `gh` configurados ([guía 2](02-git-y-github.md)):

```bash
cd ~
git clone https://github.com/Vikktor93/c-basico-automatas.git
cd c-basico-automatas
# copiar aquí el contenido base (README, Makefile, docs/, capsula-*/, .github/...)
make estricto                 # debe compilar sin advertencias
git add .
git status                    # revisar que no haya ejecutables ni build/
git commit -m "Base: cápsulas 02 a 04, guías y compilación automática"
git push -u origin main
```

> El `-u` solo se usa la primera vez.

### 2. Revisar que GitHub Actions esté activo

**Settings → Actions → General**

| Opción | Valor |
|---|---|
| Actions permissions | **Allow all actions and reusable workflows** |
| Workflow permissions | **Read repository contents and packages permissions** |

En un repositorio **público** los minutos de Actions son gratuitos.

### 3. Agregar a los estudiantes

**Settings → Collaborators → Add people**, con permiso **Write**. Cada estudiante debe **aceptar la invitación** para poder subir su rama.

Para agregar muchos de una vez desde la terminal:

```bash
for u in usuario1 usuario2 usuario3; do
  gh api -X PUT repos/Vikktor93/c-basico-automatas/collaborators/$u -f permission=push
done
```

### 4. Proteger `main` (Ruleset)

**Settings → Rules → Rulesets → New branch ruleset**

| Opción | Valor |
|---|---|
| Ruleset name | `proteger-main` |
| Enforcement status | **Active** |
| Bypass list | **Repository admin**, *Always allow* |
| Target branches | **Default** (`main`) |
| Restrict updates | ✅ Solo quien está en la bypass list puede modificar `main` (incluye hacer *Merge* de un PR) |
| Restrict deletions | ✅ |
| Require a pull request before merging | ✅ Required approvals: **0**. El resto de las opciones adicionales, sin cambios |
| Block force pushes | ✅ |
| Lo demás | Sin marcar |

> En repositorios **privados** con cuenta gratuita, GitHub no aplica los rulesets, salvo con el beneficio docente de GitHub Education.

### 5. Comprobar el flujo con una rama de prueba

Antes de la clase, simula ser un estudiante:

```bash
git checkout -b estudiante/prueba-docente
# completar capsula-02/hola.c con un nombre
git commit -am "Cápsula 02: prueba"
git push -u origin estudiante/prueba-docente
gh pr create --draft --base main --title "Entrega - Prueba Docente" --fill
```

En el PR deben aparecer tres checks: `capsula-02` en ✓ y `capsula-03`, `capsula-04` en ✗ (todavía con TODO). Luego cierra el PR y borra la rama:

```bash
gh pr close estudiante/prueba-docente --delete-branch
git checkout main
git branch -D estudiante/prueba-docente
```

---

## B. Ciclo de cada cápsula

```
 Preparar solución  →  Publicar cápsula  →  Plazo abierto  →  Revisar PRs  →  Cierra plazo  →  Publicar solución
 (local, sin push)     (main)              (estudiantes)     (checks)                          (git push + tag)
```

### 1. Preparar la solución (antes de la clase)

**Primera vez:** crear la rama a partir de `main`.

```bash
git checkout main
git pull
git checkout -b docente/solucion
```

**Cápsulas siguientes:** continuar sobre la misma rama.

```bash
git checkout docente/solucion
git merge main               # trae la cápsula nueva, si ya está en main
```

Resolver los TODO y probar:

```bash
make estricto DIR=capsula-03
make probar DIR=capsula-03
```

Guardar **sin subir**:

```bash
git add capsula-03/
git commit -m "Solución cápsula 03"
```

> **No ejecutes `git push` todavía.** Si la rama nunca se ha subido, un `git push` sin `-u origin docente/solucion` es rechazado, lo que sirve como protección extra.

### 2. Revisar las entregas (plazo abierto)

En GitHub → pestaña **Pull requests** → un PR en borrador por estudiante (`Entrega - Nombre Apellido`). En la lista, cada PR muestra **✓ o ✗** según la compilación automática.

| Pestaña | Para qué |
|---|---|
| **Conversation** | Plantilla con las cápsulas marcadas y los comentarios |
| **Commits** | Historial (`Cápsula 02`, `Cápsula 03`...) |
| **Checks** | Resultado por cápsula. **Details** muestra la advertencia o la diferencia de salida |
| **Files changed** | Todo lo que cambió respecto a `main`. Clic en `+` junto a una línea para comentar |

> **Nunca presiones *Merge*.** Como estás en la bypass list, GitHub te lo permitiría.

**Ver el estado de todos los PR desde la terminal:**

```bash
gh pr list --state open
gh pr checks 12               # checks del PR número 12
```

**Ejecutar el código de un estudiante en tu computador:**

```bash
git status                    # primero, no tener cambios sin commit
git fetch
git checkout estudiante/maria-perez
make probar
git checkout docente/solucion # volver a tu solución
```

O, más simple, con `gh`:

```bash
gh pr checkout 12
make probar
```

### 3. Publicar la solución (cerró el plazo)

**Primera vez:**

```bash
git checkout docente/solucion
git push -u origin docente/solucion
```

**Siguientes cápsulas:**

```bash
git checkout docente/solucion
git push
```

Marcar la versión con una **etiqueta (tag)** por cápsula. Así queda fija aunque la rama siga creciendo:

```bash
git tag capsula-03
git push origin capsula-03
```

> **No abras un Pull Request** para `docente/solucion`. Es solo una rama de referencia. El ruleset protege solo `main`, por lo que este push no tiene restricciones.

**Si la subiste antes de tiempo**, retírala de GitHub (queda intacta en tu computador):

```bash
git push origin --delete docente/solucion
```

### 4. Avisar a los estudiantes

- Que la solución de la cápsula está publicada en `docente/solucion` (sección D de su guía).
- Los comentarios pendientes en sus PR.

---

## C. Agregar una cápsula nueva a `main`

Por ejemplo, la cápsula 05:

```bash
git checkout main
git pull
mkdir capsula-05
# crear capsula-05/README.md, el esqueleto .c y capsula-05/prueba.sh
make estricto DIR=capsula-05     # el esqueleto debe compilar sin advertencias
git add capsula-05/
git commit -m "Base: cápsula 05"
git push                         # funciona porque estás en la bypass list
```

Agrega la cápsula a la lista de `.github/pull_request_template.md` en el mismo commit.

**El workflow no se modifica:** detecta solo las carpetas `capsula-*` y crea un check por cada una.

Llevar el cambio a tu solución:

```bash
git checkout docente/solucion
git merge main
```

Avisar a los estudiantes que ejecuten la **sección C** de su guía (`git merge main` en su rama).

### Cómo escribir `prueba.sh`

Usa como modelo las existentes:

| Cápsula | Qué revisa |
|---|---|
| `capsula-02/prueba.sh` | Que la salida empiece con un texto y no sea el original |
| `capsula-03/prueba.sh` | Que no diga `TODO` y tenga un mínimo de líneas |
| `capsula-04/prueba.sh` | Que la salida sea idéntica a `esperado.txt` (con `diff`) y que `respuesta.md` tenga texto |
| `capsula-05/prueba.sh` | Lo anterior, más: que no use `<string.h>` y que las funciones respondan bien con **otros casos** |
| `capsula-06/prueba.sh` | Salida, funciones con otros casos y respuesta |

**Probar las funciones con otros casos** (cápsulas 05 y 06): el script compila el `.c` del estudiante junto a un `main` de prueba. El `main` del estudiante se renombra con `#define main main_estudiante` antes de incluir su archivo, para que no choque. Así se detecta a quien imprime la salida esperada «a mano» sin implementar las funciones.

Reglas:

- El script empieza con `cd "$(dirname "$0")/.."` para ejecutarse desde la raíz.
- Termina con `exit 1` si algo falla y muestra un mensaje que el estudiante entienda.
- El esqueleto de `main` debe **fallar** la prueba (por eso imprime `TODO`) y **compilar sin advertencias**.

> **Durante el semestre, `main` nunca recibe la solución.** Si se fusionara, los estudiantes tendrían conflictos al hacer `git merge main`. `main` solo recibe material común: cápsulas nuevas, guías y correcciones de esqueletos.

---

## D. Al final del semestre (opcional)

- **Para reutilizar el repositorio con otro curso:** no fusionar. `main` queda como plantilla y las soluciones quedan en `docente/solucion` y en los tags.
- **Para limpiar las ramas de los estudiantes:** **Settings → Branches** o, desde la terminal, `git push origin --delete estudiante/nombre-apellido`.

---

## Resumen de comandos

| Momento | Comando |
|---|---|
| Crear rama de solución (una vez) | `git checkout -b docente/solucion` |
| Guardar solución | `git add capsula-NN/` y `git commit -m "Solución cápsula NN"` |
| Ver PRs y su estado | `gh pr list` y `gh pr checks <número>` |
| Probar la entrega de un estudiante | `gh pr checkout <número>` y `make probar` |
| Publicar solución (primera vez) | `git push -u origin docente/solucion` |
| Publicar solución (siguientes) | `git push` |
| Etiquetar cápsula | `git tag capsula-NN` y `git push origin capsula-NN` |
| Retirar solución de GitHub | `git push origin --delete docente/solucion` |
| Agregar cápsula | En `main`: carpeta nueva, commit y `git push`; luego en tu rama `git merge main` |
