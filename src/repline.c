#include "baed.h"
#include <stdlib.h>
#include <string.h>

void repline(char *str,char**ar,int line,int lines){
	if(line > lines){
		puts("Invaild Line.");
		return;
	}
	if(strcmp(str,ar[line - 1]) == 0) return;
	free(ar[line - 1]);
	ar[line - 1] = strdup(str);
	return;	
}
