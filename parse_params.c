#include "parse_params.h"

int parse_params (int argc, char **argv, int numtags, tag* t)
{
	int ii, ij, status, count;

	/* Check validity of tags */
	for (ii=0; ii<numtags; ii++)
	{
		if (strcmp(t[ii].name,"")==0)
			return TAGERR_NAME;
		if (t[ii].type > TAGTYPE_STRING)
			return TAGERR_TYPE;
		if (t[ii].data == NULL)
			return TAGERR_DATA;
	}

	/* Loop through command to find tags */
	count = 0;
	for (ii=1; ii<argc; ii++)
	{
		/* Loop through each provided tag */
		for (ij=0; ij<numtags; ij++)
		{
			/* Check parameter against tag */
			if (strcmp(t[ij].name, argv[ii])==0)
			{
				status = parse_params_action(argv, ii, t[ij]);
				if (status<0) return status;
				ii += status;
				ij = numtags;
				count++;
			}
		}
	}
	return count;
}

/* Given a match of tag t and argv[ii], do something */
int parse_params_action (char **argv, int ii, tag t)
{
	int skip;
	skip = 0;
	switch (t.type)
	{
		case TAGTYPE_BOOL:
			*((int*)t.data) = 1;
			break;
		case TAGTYPE_INT:
			if (argv[ii+1]==NULL) return PARSE_ERROR;
			*((int*)t.data) = atoi(argv[ii+1]);
			skip = 1;
			break;
		case TAGTYPE_FLOAT:
			if (argv[ii+1]==NULL) return PARSE_ERROR;
			*((float*)t.data) = atof(argv[ii+1]);
			skip = 1;
			break;
		case TAGTYPE_STRING:
			if (argv[ii+1]==NULL) return PARSE_ERROR;
			strcpy((char*)t.data, argv[ii+1]);
			skip = 1;
			break;
	}
	return skip;
}
