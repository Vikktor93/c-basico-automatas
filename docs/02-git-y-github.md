# 2. Configurar Git y GitHub en Ubuntu

Guía paso a paso para que puedas clonar el repositorio y subir tus entregas. Se hace **una sola vez** por computador.

> **Regla a seguir:** todo se hace **dentro de Ubuntu**, no en PowerShell. Tu código vive en Ubuntu (`~`), así que también lo maneja el Git de Ubuntu. VS Code conectado a `WSL: Ubuntu` usa ese mismo Git.

**¿Y si ya tengo Git o GitHub Desktop en Windows?** Puedes dejarlos instalados, pero no los uses para este repositorio. Mezclar el Git de Windows con archivos de Ubuntu produce archivos «modificados» que no cambiaste, por la diferencia en los saltos de línea.

---

## Antes de empezar

- [ ] Completaste [Preparar el entorno de C](01-entorno-c.md): `gcc --version` responde dentro de Ubuntu.
- [ ] Tienes una cuenta en **GitHub**. Si no, créala en <https://github.com/signup>. Se recomienda usar tu correo personal.
- [ ] Le diste tu **nombre de usuario de GitHub** al docente.

---

## Paso 1: verificar que Git está instalado

En la terminal de Ubuntu:

```bash
git --version
```

Normalmente ya viene instalado en Ubuntu. Si dice `command not found`:

```bash
sudo apt update
sudo apt install -y git
```

## Paso 2: decirle a Git quién eres

Cada commit lleva tu nombre y correo. Usa el **mismo correo de tu cuenta de GitHub**:

```bash
git config --global user.name "Nombre Apellido"
git config --global user.email "tu-correo@gmail.com"
```

Tres ajustes más, recomendados para el curso:

```bash
git config --global init.defaultBranch main      # la rama principal se llama main
git config --global pull.rebase false            # git pull une con merge (sin preguntar)
git config --global core.editor "code --wait"    # usa VS Code cuando Git pida escribir algo
```

Comprueba la configuración:

```bash
git config --global --list
```

## Paso 3: instalar GitHub CLI (`gh`)

GitHub **ya no acepta tu contraseña** al hacer `git push` desde la terminal. La forma más simple de iniciar sesión desde Ubuntu es la herramienta oficial de GitHub, `gh`:

```bash
sudo apt install -y gh
gh --version
```

## Paso 4: iniciar sesión en GitHub

```bash
gh auth login
```

Responde las preguntas con las flechas y Enter:

| Pregunta | Respuesta |
|---|---|
| *Where do you use GitHub?* (en versiones antiguas: *What account do you want to log into?*) | **GitHub.com** |
| *What is your preferred protocol for Git operations on this host?* | **HTTPS** |
| *Authenticate Git with your GitHub credentials?* | **Yes** |
| *How would you like to authenticate GitHub CLI?* | **Login with a web browser** |

Luego:

1. `gh` muestra un **código de 8 caracteres**, por ejemplo `ABCD-1234`. Cópialo.
2. Presiona Enter. Debería abrirse el navegador de Windows.
   - **Si no se abre** (pasa a veces en WSL), abre tú mismo <https://github.com/login/device> en el navegador.
3. Inicia sesión en GitHub, pega el código y presiona **Authorize**.
4. Vuelve a la terminal. Debe decir `✓ Logged in as tu-usuario`.

## Paso 5: verificar

```bash
gh auth status
```

Debe mostrar `Logged in to github.com account tu-usuario` y `Git operations protocol: https`.

> Si respondiste **No** en *Authenticate Git with your GitHub credentials?*, ejecuta ahora `gh auth setup-git`. Sin esto, `git push` vuelve a pedir contraseña.

## Paso 6: aceptar la invitación al repositorio

El docente te agrega como colaborador del repositorio. La invitación llega a tu correo o aparece en <https://github.com/notifications>.

**Sin aceptarla no podrás subir tu rama.**

Si no encuentras el correo, entra directamente a <https://github.com/Vikktor93/c-basico-automatas/invitations> con tu sesión iniciada y presiona **Accept invitation**.

---

## Resumen

| Paso | Comando |
|---|---|
| Verificar Git | `git --version` |
| Identidad | `git config --global user.name "..."` y `user.email "..."` |
| Instalar gh | `sudo apt install -y gh` |
| Iniciar sesión | `gh auth login` |
| Verificar sesión | `gh auth status` |

Listo. Sigue con el [flujo de trabajo del estudiante](03-flujo-estudiante.md).
