# c2f - Celsius/Fahrenheit converter

c2f converts temperature units between Celsius and Fahrenheit. c2f was born 
from the utter shock of discovering that ``units(1)`` doesn't do this 
conversion.

## Build

c2f requires:

* A POSIX-like system
* A C99 compiler

Build by using:

```
$ make
```

Customize the build process by changing ``config.mk`` to suit your needs.

## Usage

c2f accepts this syntax:

```
$ c2f [-fs]
```

By default, c2f converts from Celsius into Fahrenheit, reading the temperature
from standard input. The result is printed to standard output.

```
$ echo '28' | c2f
28.00ºC = 82.40ºF
```

To convert the other way around, namely from Fahrenheit into Celsius, use the 
``-f`` option.

```
$ echo '70' | c2f -f
70.00ºF = 21.11ºC
```

By using the ``-s`` option, c2f will only print the final result:

```
$ echo '19' | c2f -s
66.20ºF
```

Decimal precision in output is controlled by setting the ``OUTPUT_PREC`` macro 
in a file named ``config.h``. If not present, the default in ``config.def.h``
is used.

## License

c2f is published under an MIT/X11/Expat-type License. See ``LICENSE`` file for 
copyright and license details.
