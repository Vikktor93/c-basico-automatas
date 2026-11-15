# 1. Preparar el entorno de C

Guía paso a paso para dejar listo tu computador: **WSL2 + Ubuntu + gcc + VS Code**. Es lo mismo que muestran las cápsulas 01 y 02.

> Si usas **macOS**, salta a la [sección macOS](#si-usas-macos). Si usas **Linux**, salta al [paso 4](#paso-4-instalar-las-herramientas-de-c).

---

## ¿Por qué WSL y no MinGW?

| Lo que necesitamos | MinGW (Windows) | WSL + Ubuntu |
|---|---|---|
| `regex.h` (Laboratorio 1) | No | Sí |
| `pthreads` completo | Parcial | Sí |
| Valgrind | No | Sí |
| Mismo entorno que Sistemas Operativos | No | Sí |

**WSL** (Windows Subsystem for Linux) es un Linux real que corre dentro de Windows, sin máquina virtual aparte ni arranque dual.

> **Cuidado: «ya tengo gcc».** Si escribes `gcc --version` en PowerShell y responde `gcc.exe (MinGW-W64 ...)`, ese gcc es de Windows y **no sirve** para el curso. Puede quedar instalado: no interfiere con WSL.

---

## Paso 1: revisar si ya tienes WSL

Abre **PowerShell** y escribe:

```powershell
wsl -l -v
```

| Si aparece... | Entonces |
|---|---|
| Un error o una lista vacía | No tienes WSL: el paso 2 lo instala todo |
| Solo `docker-desktop` | Tienes WSL2 (lo instaló Docker), pero falta Ubuntu: paso 2 |
| `Ubuntu` | Ya está: salta al paso 4 |

## Paso 2: instalar Ubuntu

Abre PowerShell **como administrador** (clic derecho en el menú Inicio → *Terminal (administrador)*) y escribe:

```powershell
wsl --install -d Ubuntu
```

1. Si pide **reiniciar**, reinicia. Al volver, Ubuntu termina de instalarse solo.
2. Se abre una ventana de Ubuntu que pide crear un **usuario y contraseña de Linux**. Son distintos de los de Windows.
3. **La contraseña no se ve al escribirla.** No aparecen asteriscos: es normal. Escríbela y presiona Enter.

> **Anota la contraseña.** Ubuntu la pide cada vez que usas `sudo`.

Si el comando falla: ejecuta `wsl --update` y repite, o instala **Ubuntu** desde Microsoft Store.

## Paso 3: dejar Ubuntu como predeterminado

Necesario si tienes **Docker Desktop**; si no, no hace daño:

```powershell
wsl --set-default Ubuntu
wsl -l -v
```

Debes ver el asterisco junto a Ubuntu:

```
  NAME              STATE      VERSION
* Ubuntu            Running    2
  docker-desktop    Stopped    2
```

## Paso 4: instalar las herramientas de C

Abre Ubuntu (menú Inicio → **Ubuntu**, o escribe `wsl` en PowerShell) y ejecuta:

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install -y build-essential gdb valgrind manpages-dev
```

| Paquete | Qué trae |
|---|---|
| `build-essential` | `gcc`, `make` y las bibliotecas estándar de C |
| `gdb` | El depurador: ejecutar paso a paso |
| `valgrind` | Detector de errores de memoria |
| `manpages-dev` | El manual de las funciones de C (`man 3 printf`) |

## Paso 5: verificar

Dentro de Ubuntu:

```bash
gcc --version
make --version
```

`gcc --version` debe decir algo como `gcc (Ubuntu 13.3.0-...) 13.3.0`, **sin** `.exe` ni MinGW. El número puede variar.

---

## Paso 6: instalar VS Code y conectarlo a WSL

1. Descarga VS Code de <https://code.visualstudio.com> e instálalo **en Windows** (no dentro de Ubuntu).
2. Abre VS Code, ve a Extensiones (`Ctrl+Shift+X`) e instala:
   - **WSL** (Microsoft)
   - **C/C++** (Microsoft). Si aparece el botón **Install in WSL: Ubuntu**, úsalo.
3. Cierra VS Code.

## Paso 7: abrir una carpeta desde Ubuntu

En la terminal de Ubuntu:

```bash
mkdir -p ~/prueba-c
cd ~/prueba-c
code .
```

- La primera vez, VS Code descarga **VS Code Server** dentro de Ubuntu. Abajo dice *Starting VS Code in WSL (Ubuntu): Descargando servidor...*. Normalmente tarda 1 a 3 minutos.
- Cuando termina, en la **esquina inferior izquierda** aparece **`WSL: Ubuntu`**. Eso confirma que VS Code usa el gcc de Ubuntu.

> **Error común:** abrir la carpeta desde el menú de Windows. Sin `WSL: Ubuntu`, VS Code no usa el gcc de Ubuntu. Parte siempre desde la terminal con `code .`

> Si la descarga del servidor pasa de 10 minutos, revisa [problemas frecuentes](05-problemas-frecuentes.md#vs-code-se-queda-en-starting-vs-code-in-wsl).

## Paso 8: primer programa

En VS Code, crea `hola.c`:

```c
#include <stdio.h>

int main(void)
{
    printf("Hola, mundo\n");
    return 0;
}
```

Abre la terminal integrada (`Ctrl+ñ` o menú **Terminal → New Terminal**) y compila:

```bash
gcc -Wall -Wextra -g hola.c -o hola
./hola
```

| Parte | Qué hace |
|---|---|
| `gcc` | El compilador: traduce tu código C a un programa ejecutable |
| `-Wall` | Activa las advertencias principales (pese al nombre, no son todas) |
| `-Wextra` | Suma advertencias adicionales que `-Wall` no incluye |
| `-g` | Guarda información de depuración: líneas y nombres de variables |
| `hola.c` | El archivo de entrada: tu código fuente |
| `-o hola` | El nombre del ejecutable que se crea. Sin `-o`, se llama `a.out` |

> **Cuidado:** escribir `-o hola.c` reemplaza tu código fuente por el ejecutable.

Si ves `Hola, mundo`, tu entorno está listo. Sigue con [Configurar Git y GitHub](02-git-y-github.md).

---

## La terminal mínima

| Comando | Qué hace | Ejemplo |
|---|---|---|
| `pwd` | Muestra en qué carpeta estás | `pwd` |
| `ls` | Lista los archivos | `ls -l` |
| `cd` | Cambia de carpeta | `cd c-basico-automatas` |
| `mkdir` | Crea una carpeta | `mkdir prueba` |
| `cp` | Copia un archivo | `cp hola.c copia.c` |
| `mv` | Mueve o renombra | `mv copia.c otro.c` |
| `rm` | Borra, **sin papelera** | `rm otro.c` |

Atajos: `cd ..` sube una carpeta, `cd ~` vuelve a tu carpeta personal, `Tab` completa nombres y `↑` repite comandos.

**¿Dónde están mis archivos?**

- Tu carpeta de Linux es `~` (`/home/tu-usuario`). **Trabaja aquí**: es más rápido y evita problemas de permisos.
- Tu disco C de Windows está en `/mnt/c/Users/...`. Úsalo solo para traer archivos hacia `~`.
- `explorer.exe .` abre la carpeta actual en el Explorador de Windows.

---

## Si usas macOS

En la Terminal de macOS:

```bash
xcode-select --install
```

- `gcc` es en realidad `clang`, otro compilador de C. Para este curso funciona igual, incluido `regex.h`.
- Valgrind no está disponible en Macs con chip Apple: usaremos `-fsanitize=address`, que detecta los mismos errores.
- Instala VS Code y la extensión **C/C++**. No necesitas la extensión WSL.

Luego sigue con [Configurar Git y GitHub](02-git-y-github.md). En macOS instala `gh` con Homebrew (`brew install gh`).
