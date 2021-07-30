#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "dictionary.h"
#include "decode.h"
#include "encode.h"

int main(int argc, char *argv[]) {
	char *_encode = "-c";
	char *_mul_encode1 = "-dc";
	char *_mul_encode2 = "--cdir";
	char *_decode = "-x";
	char *_mul_decode1 = "-dx";
	char *_mul_decode2 = "--xdir";
	char *_help1 = "-h";
	char *_help2 = "--help";

	char *help = "Usage: ./project [OPTION]... [FILE]...\n\
	Mandatory arguments \n\
  	-c		Compress the given file\n\
	-dc, --cdir	Compress the directory given as command line argument into '<directory>.jay' format \n\
					Usage: ./project -dc <DIRECTORY> \n\
  	\n\
	-x		Decompress the given file\n\
	-dx, --xdir	Decompress the directory given as command line argument into '<directory>' without the '.jay' format \n\
					Usage: ./project -dx <DIRECTORY> \n\
    \n\
	-h, --help	Display this help and exit \n";
	
	dict d;
	
	/* Return when command line arguments are equal to 1 or greater than 3 */
	if(argc == 1 || argc > 3) {
		printf("Incorrect Usage.\n");
		printf("Try './project --help' or './project -h' for more information\n"); 
		exit(1);
	}
	
	/* Display the help and exit */
	if((argc == 2) && (!strcmp(argv[1], _help1) || !strcmp(argv[1], _help2))) {
		printf("%s", help);
		return 0;
	}
	
	/* ./project -c <FILENAME> */
	if((argc == 3) && (!strcmp(argv[1], _encode))) {
		e_init(&d);
		encode(&d, argv[2], argv[2], FIL);
		return 0;
	}	
	
	/* ./project -x <FILENAME> */
	else if((argc == 3) && (!strcmp(argv[1], _decode))) {
		d_init(&d);
		decode(&d, argv[2], argv[2]);
		return 0;
	}

	/* Encoding the directory given as command line argument */	
	/* ./project -dc <DIR> */
	/* ./project --cdir <DIR> */
	if((argc == 3) && ((!strcmp(argv[1], _mul_encode1)) || (!strcmp(argv[1], _mul_encode2)))) {
		char *s;
		if(!strcmp(argv[2], ".") || !strcmp(argv[2], "./")) 
			s = getcwd(argv[2], 128); /* Get the complete path of current directory */
		else {
			s = (char *) malloc (sizeof(char) * 128);
			strcpy(s, argv[2]);
		}
		dir_encode(s, s, DIRECT);
		printf("\n\nCompression on Folder '%s' Done.\n", argv[2]);
		return 0;
	}

	/* Decoding the given ".jay" format diectory given as command line argument */
	/* ./project -dx  <DIR> */
	/* ./project --xdir <DIR> */
	if((argc == 3) && ((!strcmp(argv[1], _mul_decode1)) || (!strcmp(argv[1], _mul_decode2)))) {
		char *token, *ext1 = "jay", *ext2 = "jay/";
		char direc[128], flag = 'r';
		strcpy(direc, argv[2]);	
		token = strtok(direc, ".");
		while(token != NULL) {
			if(!strcmp(token, ext1) || !strcmp(token, ext2))
				flag = 's'; /* Flag is set */
			else
				flag = 'r';
			token = strtok(NULL, ".");
		}
		if(flag == 'r') {
			printf("Incorrect format\n");
			exit(1);		
		}
		dir_decode(argv[2], argv[2]);
		return 0;
	}

	printf("Incorrect Usage.\n");
	printf("Try './project --help' or './project -h' for more information\n"); 
	return 0;	
}


