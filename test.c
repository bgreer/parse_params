#include <stdlib.h>
#include "parse_params.h"

int main (int argc, char **argv)
{
	int returnval;

	/* initialize a struct with that to look for */
	tag t[3];

	int flag;
	t[0].name = "-m";
	t[0].type = TAGTYPE_BOOL;
	t[0].data = &flag;

	char filename[10];
	t[1].name = "-file";
	t[1].type = TAGTYPE_STRING;
	t[1].data = filename;

	float init;
	t[2].name = "-init";
	t[2].type = TAGTYPE_FLOAT;
	t[2].data = &init;

	returnval = parse_params(argc, argv, 3, t);

	printf("\nreturn value = %d\n", returnval);

	printf("\n%d\n%s\n%f\n", flag, filename, init);

	return EXIT_SUCCESS;
}
