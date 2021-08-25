#include <stdlib.h>
int stringtoint(char *str,int len){ //this function converts all the numbers in the temp string when you want to print a line 	
	char *temp = calloc(len,sizeof(char)); // this holds the numbers of your input 
	int startPos = 2; //starts at 2 since the space and the p would fill up 0 and 1 in the array 
	int counter = 0;
	while(str[startPos] != '\n'){
		temp[counter] = str[startPos];
		startPos++;
		counter++;
	}
	
	return atoi(temp);
	//return return_Val;
}
