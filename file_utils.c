#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file( char* filename, char **buffer ) {
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	FILE *inFile = fopen( filename, "r" );
	*buffer = (char *) malloc( size*sizeof(char) );
	fgets( *buffer, size, inFile );
	fclose( inFile );
	return 0;
}

int write_file( char* filename, char *buffer, int size ) {
	FILE *outFile = fopen( filename, "w" );
	for ( int i = 0; i < size; i++ ) {
		fputc(buffer[i], outFile);
	}
	//fputs( buffer, outFile );
	fclose( outFile );
	return 0;
}

