# c2f - Celsius/Fahrenheit converter

c2f converts temperature units between Celsius and Fahrenheit. c2f was born 
from the utter shock of discovering that ``units(1)`` is terrible at this.

**Be aware this is a project in an early development stage.**

## Basic usage

c2f reads a temperature from standard input, either interactively or from a
pipe, and outputs the converted value to standard output.

```
$ c2f
ºC: 23
73.40ºF
$ c2f -f
ºF: 212
100.00ºC
$ echo 21 | c2f
69.80ºF
```

You may check the ``c2f(1)`` manpage for further usage information. 

## Build

c2f requires:

1. A POSIX-like system
2. A C99 compiler
3. [sline](https://sr.ht/~arivigo/sline)

Build by using:

```
$ make
```

Customize the build process by changing ``config.mk`` to suit your needs.

c2f is configured by setting variables in ``config.h``, using ``config.def.h`` 
as a template.

## Install

You may install c2f by running the following command as root:

```
# make install
```

This will install the binary under ``$PREFIX/bin``, as defined by your 
environment, or ``/usr/local/bin`` by default. The Makefile supports the 
``$DESTDIR`` variable as well.

## Contributing

All contributions are welcome! If you wish to send in patches, ideas, or report
a bug, you may do so by sending an email to the 
[c2f-devel](https://lists.sr.ht/~arivigo/c2f-devel) mailing list.

If interested in getting some news from the project, you may also want to 
subscribe to the low-volume 
[c2f-announce](https://lists.sr.ht/~arivigo/c2f-announce) mailing list!

## License

c2f is published under an MIT/X11/Expat-type License. See ``LICENSE`` file for 
copyright and license details.
