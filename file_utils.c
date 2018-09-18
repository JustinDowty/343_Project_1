#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file( char* filename, char** buffer){
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	*buffer = malloc(size * sizeof(char));
	char *b = *buffer;
	if(buffer == NULL){
		fprintf( stderr, "ERROR ALLOCATING MEMORY" );
		return(-1);
	}
	FILE *input = fopen(filename, "r");
	if(input == NULL){
		fprintf( stderr, "ERROR OPENING FILE FOR READ" );
		return(-1);
	}
	int ctr = 0;
	char ch;
	while( fscanf ( input, "%c", &ch ) != EOF ){
		b[ctr] = ch;
		ctr++;
	}
	return(size);
}

int reverse_file(char *buffer, int size){
	char *b = malloc(size * sizeof(char));
	if(b == NULL){
		fprintf( stderr, "ERROR ALLOCATING MEMORY" );
		return(-1);
	}
	int ctr1 = 0;
	int ctr2 = size - 1;
	while(ctr1 < size){
		b[ctr1] = buffer[ctr2];
		ctr1++;
		ctr2--;
	}
	b[ctr1] = '\0';
	buffer = b;
	return(1);
}

int write_file( char* filename, char* buffer, int size){	
	FILE *out = fopen(filename, "w");
	if(out == NULL){
		fprintf( stderr, "ERROR OPENING FILE FOR WRITE" );
		return(-1);
	}
	int ctr = 0;
	while(ctr < size){
		fputc ( buffer[ctr], out );
		ctr++;
	}
	free(buffer);
	return(1);
}
