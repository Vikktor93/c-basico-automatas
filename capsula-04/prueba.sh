#!/usr/bin/env bash
# Prueba de la cápsula 04: la salida de paridad debe coincidir con esperado.txt
# y respuesta.md debe tener una respuesta.
set -u
cd "$(dirname "$0")/.."

bin=build/capsula-04/paridad
if [ ! -x "$bin" ]; then
    echo "✗ No existe $bin: compila primero con make"
    exit 1
fi

salida=$("$bin")
codigo=$?

if [ "$codigo" -ne 0 ]; then
    echo "✗ main retornó $codigo; debe retornar 0"
    exit 1
fi
if ! diff -u --label esperado --label "tu programa" capsula-04/esperado.txt - <<< "$salida"; then
    echo "✗ La salida no coincide con capsula-04/esperado.txt (diferencias arriba)"
    exit 1
fi

palabras=$(sed -n '/^## Tu respuesta/,$p' capsula-04/respuesta.md | tail -n +2 | sed 's/<!--.*-->//g' | wc -w)
if [ "$palabras" -lt 15 ]; then
    echo "✗ Falta responder capsula-04/respuesta.md (debajo de «## Tu respuesta»)"
    exit 1
fi

echo "✓ Cápsula 04 correcta: paridad imprime lo esperado y respuesta.md tiene tu respuesta"
