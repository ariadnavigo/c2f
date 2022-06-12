# c2f - Celsius/Fahrenheit converter

c2f is a shell script that converts temperature units between Celsius and 
Fahrenheit. This little script was born from the utter shock of discovering 
that ``units(1)`` doesn't do this conversion.

## Usage

c2f accepts this syntax:

```
$ c2f [-f] num
```

By default, c2f converts ``num`` from Celsius into Fahrenheit. To convert the
other way around, namely from Fahrenheit into Celsius, use the ``-f`` option.

The result is printed to standard output.

## License

c2f is published under an MIT/X11/Expat-type License. See ``LICENSE`` file for 
copyright and license details.
