#!/usr/bin/env bash
# Prueba de la cápsula 06:
#   1. la salida coincide con esperado.txt
#   2. las funciones responden bien con OTROS datos (no solo los de main)
#   3. respuesta.md tiene una respuesta
set -u
cd "$(dirname "$0")/.."

dir=capsula-06
bin=build/$dir/punteros
if [ ! -x "$bin" ]; then
    echo "✗ No existe $bin: compila primero con make"
    exit 1
fi

# 1. Salida de main
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

# 2. Funciones con otros casos. Se compila punteros.c junto a un main de
#    prueba (el main del estudiante se renombra para que no choque).
prueba=build/$dir/prueba_funciones
cat > "$prueba.c" <<'EOF'
#define main main_estudiante
#include "punteros.c"
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
    int x = 7, y = -3;
    intercambiar(&x, &y);
    revisar(x == -3 && y == 7, "intercambiar(&x, &y) con x=7, y=-3 debe dejar x=-3, y=7");

    int z = 5;
    intercambiar(&z, &z);
    revisar(z == 5, "intercambiar(&z, &z) debe dejar z igual");

    int c = 99, u = 99;
    contar_simbolos("", &c, &u);
    revisar(c == 0 && u == 0, "contar_simbolos(\"\") debe dejar 0 ceros y 0 unos, aunque traigan 99");

    c = 99; u = 99;
    contar_simbolos("0a1b00", &c, &u);
    revisar(c == 3 && u == 1, "contar_simbolos(\"0a1b00\") debe dar 3 ceros y 1 uno (ignora a y b)");

    const char *w = "abcabc";
    revisar(buscar(w, 'a') == w,     "buscar(\"abcabc\", 'a') debe retornar w (la primera a)");
    revisar(buscar(w, 'c') == w + 2, "buscar(\"abcabc\", 'c') debe retornar w + 2, un puntero DENTRO de w");
    revisar(buscar(w, 'z') == NULL,  "buscar(\"abcabc\", 'z') debe retornar NULL");
    revisar(buscar("", 'a') == NULL, "buscar(\"\", 'a') debe retornar NULL");
    return fallas == 0 ? 0 : 1;
}
EOF
if ! gcc -std=c11 -w -I"$dir" "$prueba.c" -o "$prueba"; then
    echo "✗ No se pudo compilar la prueba de funciones: ¿cambiaste el nombre o los parámetros de intercambiar, contar_simbolos o buscar?"
    exit 1
fi
if ! "$prueba"; then
    echo "✗ Tus funciones fallan con datos distintos a los de main (detalle arriba)"
    exit 1
fi

# 3. Respuesta escrita
palabras=$(sed -n '/^## Tu respuesta/,$p' "$dir/respuesta.md" | tail -n +2 | sed 's/<!--.*-->//g' | wc -w)
if [ "$palabras" -lt 15 ]; then
    echo "✗ Falta responder $dir/respuesta.md (debajo de «## Tu respuesta»)"
    exit 1
fi

echo "✓ Cápsula 06 correcta: salida, funciones y respuesta"
