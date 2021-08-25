#include "baed.h"


int opcheck(char *str){
	if(str[0] == '~' &&  str[1] == WRITE_CHAR) return WRITE_RET;
	else if(str[0] == '~' && str[1] == EXIT_CHAR) return EXIT_RET;
	else if(str[0] == '~' && str[1] == PRINTALL_CHAR) return PRINTALL_RET;
	else if(str[0] == '~' && str[1] == PRINT_CHAR) return PRINT_RET;
	else if(str[0] == '~' && str[1] == UNDO_CHAR) return UNDO_RET;
	else if(str[0] == '~' && str[1] == EDIT_CHAR) return EDIT_RET;
	else if(str[0] == '~' && str[1] == INSERT_CHAR) return INSERT_RET;
	else if(str[0] == '~' && str[1] == PRINTLINES_CHAR) return PRINTLINES_RET;
	return 0;
}
