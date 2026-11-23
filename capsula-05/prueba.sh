#!/usr/bin/env bash
# Prueba de la cápsula 05:
#   1. cadenas.c no usa <string.h>
#   2. la salida coincide con esperado.txt
#   3. las funciones responden bien con OTRAS cadenas (no solo las de main)
#   4. respuesta.md tiene una respuesta
set -u
cd "$(dirname "$0")/.."

dir=capsula-05
bin=build/$dir/cadenas
if [ ! -x "$bin" ]; then
    echo "✗ No existe $bin: compila primero con make"
    exit 1
fi

# 1. Sin <string.h>
if grep -Eq '^[[:space:]]*#[[:space:]]*include[[:space:]]*<string\.h>' "$dir/cadenas.c"; then
    echo "✗ cadenas.c incluye <string.h>: implementa largo recorriendo la cadena hasta '\\0'"
    exit 1
fi

# 2. Salida de main
salida=$("$bin")
codigo=$?
if [ "$codigo" -ne 0 ]; then
    echo "✗ main retornó $codigo; debe retornar 0"
    exit 1
fi
if ! diff -u --label esperado --label "tu programa" "$dir/esperado.txt" - <<< "$salida"; then
    echo "✗ La salida no coincide con $dir/esperado.txt (diferencias arriba)"
    exit 1
fi

# 3. Funciones con otros casos. Se compila cadenas.c junto a un main de
#    prueba (el main del estudiante se renombra para que no choque).
prueba=build/$dir/prueba_funciones
cat > "$prueba.c" <<'EOF'
#define main main_estudiante
#include "cadenas.c"
#undef main

static int fallas = 0;
static void revisar(int ok, const char *caso)
{
    if (!ok) {
        printf("✗ Falla: %s\n", caso);
        fallas++;
    }
}

int main(void)
{
    revisar(largo("a") == 1,                     "largo(\"a\") debe ser 1");
    revisar(largo("abcdefghijklmnopqrstuvwxyz") == 26, "largo del abecedario debe ser 26");
    revisar(largo("ab\0cd") == 2,                "largo(\"ab\\0cd\") debe ser 2: la cadena termina en el primer '\\0'");
    revisar(contar("banana", 'a') == 3,          "contar(\"banana\", 'a') debe ser 3");
    revisar(contar("banana", 'x') == 0,          "contar(\"banana\", 'x') debe ser 0");
    revisar(contar("", 'a') == 0,                "contar(\"\", 'a') debe ser 0");
    revisar(en_alfabeto("abba", "ab"),           "en_alfabeto(\"abba\", \"ab\") debe ser true");
    revisar(!en_alfabeto("abc", "ab"),           "en_alfabeto(\"abc\", \"ab\") debe ser false");
    revisar(!en_alfabeto("cab", "ab"),           "en_alfabeto(\"cab\", \"ab\") debe ser false (el símbolo malo está al inicio)");
    revisar(en_alfabeto("", "ab"),               "en_alfabeto(\"\", \"ab\") debe ser true");
    revisar(!en_alfabeto("a", ""),               "en_alfabeto(\"a\", \"\") debe ser false (Σ vacío)");
    return fallas == 0 ? 0 : 1;
}
EOF
if ! gcc -std=c11 -w -I"$dir" "$prueba.c" -o "$prueba"; then
    echo "✗ No se pudo compilar la prueba de funciones: ¿cambiaste el nombre o los parámetros de largo, contar o en_alfabeto?"
    exit 1
fi
if ! "$prueba"; then
    echo "✗ Tus funciones fallan con cadenas distintas a las de main (detalle arriba)"
    exit 1
fi

# 4. Respuesta escrita
palabras=$(sed -n '/^## Tu respuesta/,$p' "$dir/respuesta.md" | tail -n +2 | sed 's/<!--.*-->//g' | wc -w)
if [ "$palabras" -lt 15 ]; then
    echo "✗ Falta responder $dir/respuesta.md (debajo de «## Tu respuesta»)"
    exit 1
fi

echo "✓ Cápsula 05 correcta: salida, funciones y respuesta"
