#include "def.h"

CheckPrefix(Key, Word)
char *Key,    /* Possible New Key */
*Word;   /* The Key Stored in the B-Tree */
{

	if(strlen(Key) > strlen(Word)){
		return(2);
	}
	else{
		int i;
		for(i=0; i<strlen(Key); i++){
			if (Key[i] < Word[i]){
				return(1);
			}
				
			if (Key[i] > Word[i]){
				return(2);
			}
				
		}
		return 0;
	}
	// You will probably want to fill this in
}


