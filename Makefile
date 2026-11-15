# Makefile - C básico · Autómatas y Lenguajes Formales
#
#   make                      compila todas las cápsulas en build/
#   make DIR=capsula-04       compila solo una cápsula
#   make estricto             compila con -Werror, igual que GitHub
#   make probar               compila y corre las pruebas (prueba.sh)
#   make clean                borra build/

CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -g
DIR    ?= capsula-*

SRC = $(wildcard $(DIR)/*.c)
BIN = $(patsubst %.c,build/%,$(SRC))

all: $(BIN)

build/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

estricto:
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory all CFLAGS="$(CFLAGS) -Werror"

probar: all
	@estado=0; \
	for p in $(wildcard $(DIR)/prueba.sh); do \
	    echo "== $$p"; \
	    bash $$p || estado=1; \
	done; \
	exit $$estado

clean:
	rm -rf build

.PHONY: all estricto probar clean
