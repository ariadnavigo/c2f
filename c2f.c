/* See LICENSE file for copyright and license details. */

#include <sline.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

#define CELS2FAHR(temp) temp * 9 / 5 + 32
#define FAHR2CELS(temp) (temp - 32) * 5 / 9

#define INPUT_SIZE 16

enum {
	CELS_MODE,
	FAHR_MODE
};

enum {
	OUT_LONG,
	OUT_SHORT
};

static void die(const char *fmt, ...);
static void cleanup(void);
static void usage(void);

static int sline_mode;

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
cleanup(void)
{
	if (sline_mode > 0)
		sline_end();
}

static void
usage(void)
{
	die("usage: c2f [-fs]");
}

int 
main(int argc, char *argv[])
{
	int opt, mode, out_mode;
	char input[INPUT_SIZE];
	float temp, res;
	char *endptr;

	atexit(cleanup);

	mode = CELS_MODE;
	out_mode = OUT_LONG;
	while ((opt = getopt(argc, argv, ":fs")) != -1) {
		switch (opt) {
		case 'f':
			mode = FAHR_MODE;
			break;
		case 's':
			out_mode = OUT_SHORT;
			break;
		default:
			usage();
			break;
		}
	}

	if ((sline_mode = isatty(STDIN_FILENO)) > 0) {
		if (sline_setup(0) < 0)
			die("sline: %s.", sline_errmsg());
		sline_set_prompt((mode == FAHR_MODE) ? "ºF: " : "ºC: ");
		sline(input, INPUT_SIZE, NULL);
		sline_end();
	} else {
		fgets(input, INPUT_SIZE, stdin);
		if (input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';
	}

	temp = strtof(input, &endptr);
	if (endptr[0] != '\0')
		die("%s is not a number.", input);

	if (mode == FAHR_MODE)
		res = FAHR2CELS(temp);
	else
		res = CELS2FAHR(temp);

	printf("%." OUTPUT_PREC "f", res);
	if (out_mode == OUT_SHORT)
		goto skip_unit;

	if (mode == FAHR_MODE) 
		printf("ºC");
	else
		printf("ºF");
	
skip_unit:
	putchar('\n');

	return 0;
}
