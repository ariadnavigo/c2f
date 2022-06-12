# See LICENSE file for copyright and license details.

.POSIX:

include config.mk

SRC = c2f.c
OBJ = ${SRC:.c=.o}

all: options c2f

options:
	@echo Build options:
	@echo "CPPFLAGS = ${CPPFLAGS}"
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo

${OBJ}: config.mk

c2f: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f c2f ${OBJ}

.PHONY: all options clean 
