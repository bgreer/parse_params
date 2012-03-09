#include <stdlib.h>
#include "parse_params.h"

int main (int argc, char **argv)
{
	int i;
	/* initialize a struct with that to look for */
	tag t;

	t.name = "-m";
	t.type = TAGTYPE_BOOL;

	i = parse_params(argc, argv, 1, &t);

	printf("\nreturn value = %d\n", i);

	return EXIT_SUCCESS;
}
