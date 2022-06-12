/* See LICENSE file for copyright and license details. */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

#define INPUT_SIZE 16

enum {
	CELS_MODE,
	FAHR_MODE
};

static void die(const char *fmt, ...);
static void usage(void);

static void
die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);

	vfprintf(stderr, fmt, ap);
	fputc('\n', stderr);

	va_end(ap);

	exit(1);
}

static void
usage(void)
{
	die("usage: c2f [-f]");
}

int 
main(int argc, char *argv[])
{
	int opt, mode;
	char input[INPUT_SIZE];
	float temp, res;
	char *endptr;

	mode = CELS_MODE;
	while ((opt = getopt(argc, argv, ":f")) != -1) {
		switch (opt) {
		case 'f':
			mode = FAHR_MODE;
			break;
		default:
			usage();
			break;
		}
	}

	fgets(input, INPUT_SIZE, stdin);
	if (input[strlen(input) - 1] == '\n')
		input[strlen(input) - 1] = '\0';

	temp = strtof(input, &endptr);
	if (endptr[0] != '\0')
		die("%s is not a number.", input);

	if (mode == FAHR_MODE)
		res = (temp - 32) * 5 / 9;
	else
		res = temp * 9 / 5 + 32;

	printf("%." OUTPUT_PREC "fº%c", temp, (mode == FAHR_MODE) ? 'F' : 'C');
	printf(" = ");
	printf("%." OUTPUT_PREC "fº%c", res, (mode == FAHR_MODE) ? 'C' : 'F');
	putchar('\n');

	return 0;
}
