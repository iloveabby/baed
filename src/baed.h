#include <stdio.h>
#define WRITE_CHAR 'W'
#define WRITE_RET 1
#define EXIT_CHAR 'Q'
#define EXIT_RET 2
#define PRINTALL_CHAR 'A'
#define PRINTALL_RET 3
#define PRINT_CHAR 'P'
#define PRINT_RET 4
#define UNDO_CHAR 'U'
#define UNDO_RET 5
#define EDIT_CHAR 'E'
#define EDIT_RET 6
#define INSERT_CHAR 'I'
#define INSERT_RET 7
#define PRINTLINES_CHAR  'L'
#define PRINTLINES_RET  8

int linecount(FILE *fp,size_t size);
size_t getsize(char *filename);
char *strdup(char const *str);
void loadarray(FILE *fp,char **output,size_t size,size_t array_size);
int opcheck(char *str);
void printarray(FILE*fp,char **array);
int stringtoint(char *str,int len);
void undo(char **ar,int *lines);
void checkfile(char *filename);
void repline(char *str,char**ar,int line,int lines);
