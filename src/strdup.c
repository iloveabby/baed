#include <string.h>
#include <stdlib.h>


char *strdup(char const *str){
	int len =  strlen(str);
	char *output = malloc(len + 1);
	strncpy(output,str,len +1);
	return output;
}
