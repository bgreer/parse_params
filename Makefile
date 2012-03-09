

test : test.c parse_params.c parse_params.h
	gcc -o test test.c parse_params.c parse_params.h
