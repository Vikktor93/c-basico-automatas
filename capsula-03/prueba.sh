#!/usr/bin/env bash
# Prueba de la cápsula 03: ficha.c debe imprimir los cuatro datos.
set -u
cd "$(dirname "$0")/.."

bin=build/capsula-03/ficha
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
if grep -q "TODO" <<< "$salida"; then
    echo "✗ La salida todavía dice TODO: completa ficha.c y borra esa línea"
    exit 1
fi
lineas=$(grep -c . <<< "$salida")
if [ "$lineas" -lt 4 ]; then
    echo "✗ Se esperaban al menos 4 líneas (nombre, inicial, edad, promedio); hay $lineas"
    exit 1
fi

echo "✓ Cápsula 03 correcta:"
echo "$salida"
