#ifndef __ENCODE_H
#define __ENCODE_H

#include "dictionary.h"

/* Initializes the dictionary. Puts value from 0 to 255 in the dictionary */
/* Returns the malloced pointer of the dictionary */
void e_init(dict *d);

/* Returns the size of file with nme "file" */
unsigned long fsize(char *file);

/* Opens the input file "fname" and returns the pointer */
FILE *e_open_file(char *fname);

/* Opens the output file "fname" and returns the pointer */
FILE * e_open_op_file(char *fname);

/* Encode should create a file with some extension */
void encode(dict *d, char *fname, char *op_fname, int mode);

/* Encode should create a directory folder with extension */
void dir_encode(char *dir_name, char *op_dir_name, int mode);

/* Returns the code of the string if the string is encountered in the dictionary */
/* Else returns MAX_DICT_LEN */
uint16_t e_search_dict(dict *d, uint8_t *str, uint16_t len);

/* Appends to the dictionary at lim_code of the dictionary */
void e_addto_dict(dict *d, uint8_t *str, uint16_t count);

/* Frees all the malloced pointers */
void e_free_dict(dict *d);

#endif		
