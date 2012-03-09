#include "parse_params.h"

int parse_params (int argc, char **argv, int numtags, tag* t)
{
	int ii, ij, status, count;
	printf("Given %d possible parameters\n", argc-1);
	printf("Looking for %d tags\n", numtags);

	count = 0;
	for (ii=1; ii<argc; ii++)
	{
		printf("parsing '%s'\n", argv[ii]);
		for (ij=0; ij<numtags; ij++)
		{
			if (strcmp(t[ij].name, argv[ii])==0)
			{
				printf("match found\n");
				status = parse_params_action(argv, ii, t[ij]);
				if (status<0) return -1;
				ii += status;
				ij = numtags;
				count++;
			}
		}
	}
	return count;
}

int parse_params_action (char **argv, int ii, tag t)
{
	int skip;
	skip = 0;
	switch (t.type)
	{
		case TAGTYPE_BOOL:
			printf("\tboolean\n");
			break;
		case TAGTYPE_INT:
			printf("\tinteger\n");
			skip = 1;
			break;
		case TAGTYPE_FLOAT:
			printf("\tfloat\n");
			skip = 1;
			break;
		case TAGTYPE_STRING:
			printf("\tstring\n");
			skip = 1;
			break;
	}
	return skip;
}
