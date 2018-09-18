#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char **argv){
	char* buffer;
	int size = read_file(argv[1], &buffer);
	reverse_file(buffer, size);
	write_file(argv[2], buffer, size);
	return(1);
}
