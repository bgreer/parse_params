

#define TAGTYPE_BOOL 0
#define TAGTYPE_INT 1
#define TAGTYPE_FLOAT 2
#define TAGTYPE_STRING 3


typedef struct
{
	char *name; /* text to look for */
	int type;   /* what to do about it */
	void *ret;  /* pointer for possible return of data */
} tag;


int parse_params (int argc, char **argv, int numtags, tag* t);

