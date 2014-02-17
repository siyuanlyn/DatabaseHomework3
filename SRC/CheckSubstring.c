#include "def.h"
#include <stdio.h>

CheckSubstring(Key, Word)
char *Key,    /* Possible New Key */
*Word;   /* The Key Stored in the B-Tree */
{
	if(strstr(Word, Key) != NULL){
		return(0);
	}
	else{
		return(1);
	}
}
