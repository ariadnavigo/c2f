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

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f c2f ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/c2f
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" c2f.1 \
	    > ${DESTDIR}${MANPREFIX}/man1/c2f.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/c2f.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/c2f \
	   ${DESTDIR}${MANPREFIX}/man1/c2f.1

.PHONY: all options clean install uninstall
