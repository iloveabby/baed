#include "baed.h"
void printarray(FILE *stream,char **array){
	int count = 0;
	while(array[count] != NULL){
		fprintf(stream,"%s",array[count]);
		count++;
	}	
	return;
}
