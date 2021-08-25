/* THIS FILE IS UNDER THE GNU GPL V 0x3
 * ALL FILES IN THIS REPO ARE UNDER IT AS WELL.
 * 
 *					      */
#include <stdlib.h>
#include <string.h>
#include "baed.h"
int main(int argc, char *argv[]){
	char **data; /*holds buffer*/
	char userin[250];
	int op = 0; /*holds the return value from op check repersents a action a user wants*/
	int lines = 0;
	int newlines = 0;/*counts newlines resets every ten lines*/
	int userline = 0; /*used later in program when user does actions on lines*/
	size_t bytes = 0;
	FILE *fp = NULL;
	checkfile(argv[1]);
	bytes  = getsize(argv[1]);
	fp = fopen(argv[1],"r");
	lines = linecount(fp,bytes);
	fclose(fp);
	fp = fopen(argv[1],"r"); /*had to repon file since it started where the linecount function last ended*/
	data = calloc(lines + 11,sizeof(char*));
	loadarray(fp,data,bytes,lines);
	fclose(fp);
	printf("%ldB,%dL\n",bytes,lines);
	while(1){
		if(newlines == 10){
			/* Past 20 lines this crashes I need to find out why or implement a better system*/
			char **tmp = NULL;
			newlines = 0;
			tmp = realloc(data,sizeof(char*)*lines+11);
			if(tmp == NULL){
				puts("Failed to Allocate memory for line buffer.You are unable to add more lines.");
				
			}
			else{
			data = tmp;
			tmp = NULL;
			}
				
		}
		fgets(userin,250,stdin);
		op = opcheck(userin);
		if(op == WRITE_RET){
			fp = fopen(argv[1],"w");
			printarray(fp,data);
			fclose(fp);	
			bytes = getsize(argv[1]);
			printf("%ldB,%dL\n",bytes,lines);
		}	
		else if(op == EXIT_RET){
			exit(0);
		}
		else if(op == PRINTALL_RET) printarray(stdout,data);	
		else if(op == PRINT_RET){
			userline = stringtoint(userin,strlen(userin) - 3);
			if(userline - 1> lines - 1){
				puts("Invaild Line");
			}
			else{
				printf("%s",data[userline - 1]);
			}
		}
		else if(op == UNDO_RET){
			undo(data,&lines);
			newlines = newlines - 1;
		}
		else if(op == EDIT_RET){
			userline = stringtoint(userin,lines);
			if(userline > lines) puts("Invaild Line!");
			else{
				printf("%s",data[userline - 1]);
				fgets(userin,250,stdin);
				repline(userin,data,userline,lines);
			}		
		}
		else if(op == PRINTLINES_RET) printf("%dL\n",lines);
		else{
			newlines++;
			lines++;
			data[lines - 1] = strdup(userin);
			data[lines] = NULL;
		}
	}
}

