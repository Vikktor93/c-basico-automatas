#!/usr/bin/env bash
# Prueba de la cápsula 02: el saludo debe llevar el nombre del estudiante.
set -u
cd "$(dirname "$0")/.."

bin=build/capsula-02/hola
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
if [[ "$salida" != "Hola, "* ]]; then
    echo "✗ La salida debe empezar con «Hola, ». Se obtuvo: $salida"
    exit 1
fi
if [ "$salida" = "Hola, mundo" ]; then
    echo "✗ Todavía dice «Hola, mundo»: cambia «mundo» por tu nombre"
    exit 1
fi

echo "✓ Cápsula 02 correcta: $salida"
