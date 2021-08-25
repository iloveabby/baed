#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int linecount(FILE *fp,size_t size){
	int lines = 0;
	int count = 0;
	char *text = malloc(size + 1);
	fread(text,sizeof(char),size,fp);
	while(count < size){
		if(text[count] == '\n'){
			lines++;
		}
		count++;
	}
	free(text);
	return lines;	
}
