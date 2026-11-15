# 5. Problemas frecuentes

## Entorno

### `gcc --version` dice `gcc.exe (MinGW-W64 ...)`

Lo estás ejecutando en **PowerShell**, es decir, en Windows. Abre Ubuntu (menú Inicio → **Ubuntu**, o escribe `wsl`) y vuelve a probar. Dentro de Ubuntu debe decir `gcc (Ubuntu ...)`.

### `wsl -l -v` muestra solo `docker-desktop`

Docker Desktop instaló WSL2, pero no Ubuntu. Sigue el [paso 2 de la guía de entorno](01-entorno-c.md#paso-2-instalar-ubuntu) y luego `wsl --set-default Ubuntu`.

### VS Code se queda en «Starting VS Code in WSL»

La primera conexión descarga **VS Code Server** dentro de Ubuntu; normalmente tarda 1 a 3 minutos. Si pasa de 10:

1. Mira el avance en **View → Output**, eligiendo **WSL** en el selector del panel.
2. Si está detenido, cierra VS Code y en PowerShell ejecuta `wsl --shutdown`.
3. En Ubuntu borra la descarga incompleta y vuelve a intentar:

```bash
rm -rf ~/.vscode-server
cd ~/c-basico-automatas
code .
```

Causas habituales: VPN, antivirus o una red con proxy (como la de la universidad). Comprueba que Ubuntu tiene internet con `sudo apt update`.

### `man 3 printf` dice «No manual entry»

Falta el manual de C:

```bash
sudo apt install -y manpages-dev
```

---

## Git y GitHub

### GitHub pide usuario y contraseña, y la contraseña no funciona

GitHub ya no acepta la contraseña de la cuenta en la terminal. Inicia sesión con `gh`:

```bash
gh auth login
gh auth setup-git
```

Ver la [guía de Git y GitHub](02-git-y-github.md#paso-4-iniciar-sesión-en-github).

### `gh auth login` no abre el navegador

Pasa a veces en WSL. Copia el código que muestra la terminal, abre tú mismo <https://github.com/login/device> en el navegador de Windows y pégalo ahí.

### `remote: Permission to ... denied` o error 403 al hacer push

No aceptaste la invitación al repositorio. Revisa tu correo o <https://github.com/notifications>, acepta y vuelve a intentar.

### `push declined due to repository rule violations` / `Cannot update this protected ref`

Estás intentando subir a `main`, que está protegida. Revisa en qué rama estás:

```bash
git branch
```

Si hiciste commits en `main` por error, consulta la siguiente sección.

### Hice commits en `main` en vez de en mi rama

```bash
git checkout -b estudiante/nombre-apellido    # crea tu rama con esos commits
git push -u origin estudiante/nombre-apellido
git checkout main
git reset --hard origin/main                  # devuelve main local a como está en GitHub
git checkout estudiante/nombre-apellido
```

> Si tu rama **ya existía**, usa `git checkout estudiante/nombre-apellido` y luego `git merge main` en vez de `-b`. Después sigue con el `reset` de `main`.

### `fatal: The current branch has no upstream branch`

Es tu primer push de esa rama. Usa:

```bash
git push -u origin estudiante/nombre-apellido
```

### `Author identity unknown` / `Please tell me who you are`

Falta configurar tu nombre y correo en Git (dentro de Ubuntu):

```bash
git config --global user.name "Nombre Apellido"
git config --global user.email "tu-correo@ejemplo.cl"
```

### No puedo cambiar de rama: «Your local changes would be overwritten»

Tienes cambios sin guardar. Haz commit primero:

```bash
git add .
git commit -m "WIP: trabajo en progreso"
```

o guárdalos temporalmente:

```bash
git stash            # guarda los cambios a un lado
git checkout <otra-rama>
# ...
git checkout <tu-rama>
git stash pop        # los recupera
```

### Conflicto al hacer merge

Git avisa `CONFLICT` cuando tú y la base cambiaron las mismas líneas.

1. Abre el archivo en VS Code. Verás bloques marcados con `<<<<<<<`, `=======` y `>>>>>>>`.
2. Elige **Accept Current**, **Accept Incoming** o **Accept Both**, o edita a mano.
3. Guarda y termina el merge:

```bash
git add .
git commit -m "Resuelve conflicto con main"
git push
```

Para cancelar el merge y volver a como estabas: `git merge --abort`.

### `git status` muestra muchos archivos modificados que no toqué

Casi siempre es por usar el Git de Windows sobre archivos de Ubuntu (diferencia en los saltos de línea). Usa solo el Git de Ubuntu. Para descartar esos cambios falsos:

```bash
git checkout -- .
```

> **Ojo:** esto también descarta tus cambios reales sin commit. Haz commit de lo tuyo antes.

### Subí un ejecutable por error

```bash
git rm --cached capsula-02/hola
git commit -m "Quita ejecutable"
git push
```

---

## Compilación automática (checks del PR)

### El check de una cápsula está en ✗

Clic en **Details** → abre el paso en rojo:

| Paso que falló | Qué significa | Cómo reproducirlo en tu computador |
|---|---|---|
| *Compilar sin advertencias* | Hay un error o una **advertencia** | `make estricto DIR=capsula-NN` |
| *Ejecutar la prueba* | Compila, pero la salida no es la esperada | `make probar DIR=capsula-NN` |

Es normal ver ✗ en las cápsulas que todavía no haces.

### En mi computador compila, pero en GitHub falla

En tu computador las advertencias se muestran pero no detienen la compilación. GitHub usa `-Werror`, que las convierte en errores. Compila igual que GitHub:

```bash
make estricto DIR=capsula-NN
```

### `prueba.sh: line 2: $'\r': command not found`

El script tiene saltos de línea de Windows. Pasa si lo editaste o copiaste desde Windows. Corrígelo:

```bash
sed -i 's/\r$//' capsula-NN/prueba.sh
```

El `.gitattributes` del repositorio evita esto en los archivos que vienen de GitHub.
