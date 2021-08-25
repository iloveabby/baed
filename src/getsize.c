#include <sys/stat.h>
#include <stddef.h>

size_t getsize(char *filename){
	struct stat st;
	stat(filename,&st);
	return st.st_size;
}
