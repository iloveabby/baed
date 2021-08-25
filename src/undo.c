#include "baed.h"
void undo(char **ar,int *lines){
	ar[*lines -1] = NULL;
	*lines = *lines - 1;

}
