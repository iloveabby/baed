#include <stdio.h>
#include <stdlib.h>
#include "baed.h"

void loadarray(FILE *fp,char **output,size_t size,size_t array_size){
	int count = 0;
	char *temparray = malloc(size + 1);
	while(fgets(temparray,size + 1,fp) != NULL && count < array_size){
		output[count] = strdup(temparray);
		count++;
	}
	output[count] = NULL;/* data array is null terminated*/
	return; 
}
