#include <stdlib.h>
#include <unistd.h>
#include "baed.h"



void checkfile(char *filename){
	if(access(filename,F_OK) == -1){
		puts("Error! File doesn't exist.");
		exit(1);
	}
	if(access(filename,R_OK) == -1 &&  access(filename,W_OK) == -1){
		puts("Error! You lack read or wirte access on this file.");
		exit(1);
	}
	else{
		return;
	}
}
