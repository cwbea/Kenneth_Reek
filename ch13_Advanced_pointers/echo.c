/*
** A program to print its command line arguments.
*/
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
/*
** Print arguments until a NULL pointer is reached (argc is
** not used). The program name is skipped. By incrementing argv first in the loop
the programme name is automatically skipped.
*/
	while( *++argv != NULL )
	printf( "%s\n", *argv );
	return EXIT_SUCCESS;
}
