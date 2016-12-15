#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <argp.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <wchar.h>
#include "permutelib.h"
#include "permutelib.c"

const char *argp_program_version = "permute 0.1.0";
const char *argp_program_bug_address = "<m@eldrewolf.net>";
static char doc[] = "Permute - A simple permutation generator";
static char args_doc[] = "SET_STRING";
static struct argp_option options[] = {
	{"n-tuples",	'n',	"n",	0,	"Produce permutations with repetition" },
	{"k-permute",	'k',	"k",  0,	"Produce k-permutations of a set" },
	{"multiset",	'm',	0,	OPTION_ARG_OPTIONAL, "Produce multiset permutations" },
	{ 0 }
};
struct arguments {
	char *args[1];
	int n, k;
	bool m;
};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;
	int n, k;

	switch (key) {
		case 'n':
			n = atoi(arg);
			if (n <= 0) {
				argp_usage(state);
			}
			arguments->n = n;
			break;
		case 'k':
			k = atoi(arg);
			if (k <= 0) {
				argp_usage(state);
			}
			arguments->k = k;
			break;
		case 'm':
			arguments->m = true;
			break;

		case ARGP_KEY_ARG:
			if (state->arg_num > 0) {
				argp_usage(state);
			}
			arguments->args[state->arg_num] = arg;
			break;

		case ARGP_KEY_END:
			if (state->arg_num < 1) {
				argp_usage(state);
			}
			break;

		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

int
main(int argc, char **argv)
{
	setlocale(LC_CTYPE,"en_US.UTF8");
	
	struct arguments arguments;
	arguments.m = false;

	argp_parse (&argp, argc, argv, 0, 0, &arguments);

	size_t inputLen = strlen(arguments.args[0]);

	if (inputLen > MAX_INPUT) {
		puts("The maximum number of elements is 23");
		return EXIT_FAILURE;
	}
	wchar_t *seq = permute_get_sequence(arguments.args[0], inputLen);
	size_t seqLen = wcslen(seq);

	if (seqLen > 23) {
		puts("The maximum number of elements is 23");
		return EXIT_FAILURE;
	}
	if (arguments.k > 0) {
		puts("k-permutations have not been implemented yet");
		return EXIT_FAILURE;
	}
	if (arguments.m) {
		puts("multiset permutations have not been implemented yet");
		return EXIT_FAILURE;
	}
	if (arguments.n > 0) {
		permute_ntuple(seq, seqLen, (size_t)arguments.n);
	} else {
		permute_heap_nonrecursive(seq, seqLen);
	}
	return EXIT_SUCCESS;
}
