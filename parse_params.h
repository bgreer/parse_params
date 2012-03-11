#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Types of tags that can be parsed */
#define TAGTYPE_BOOL 0
#define TAGTYPE_INT 1
#define TAGTYPE_FLOAT 2
#define TAGTYPE_STRING 3

/* Return values for error */
#define PARSE_ERROR -1
#define TAGERR_NAME -2
#define TAGERR_TYPE -3
#define TAGERR_DATA -4

/* The basic struct that defines what to look for and what to do when you find it */
typedef struct
{
	char *name; /* text to look for */
	int type;   /* what to do about it */
	void *data;  /* pointer for possible return of data */
} tag;


int parse_params (int argc, char **argv, int numtags, tag* t);
int parse_params_action (char **argv, int ii, tag t);

