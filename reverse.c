#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv) {
	char *in;
	char *out;
	printf("File reversal begun.\n");
	if ( argc != 3 ) {
		printf("Invalid arguments.\n");
		return -1;
	}
	if ( access( argv[1], F_OK ) == -1 ) {
		printf("Input file does not exist.\nCheck spelling and try again.\n");
		return -1;
	}
	/*printf("%i \n", argc);
	for ( int i = 0; i < argc; i++ ) {
		printf("%s \n", argv[i]);
	}*/
	struct stat st;
	stat(argv[1], &st);
	int size = st.st_size;
	//printf("Size: %i\n", size);
	read_file( argv[1], &in );
	out = (char *) malloc( size*sizeof(char) );
	for ( int i = 0; i < size; i++ ) {
		out[i] = in[size - ( i + 1 )];
	}
	write_file( argv[2], out, size);
	printf("File reversal completed.\n");
}
