
/* closes the three files (btree, postings & text files) */

#include <stdio.h>
#include "def.h"


extern FILE *fppost, *fpbtree, *fptext;

dbclose() {
    fclose(fppost);
    fclose(fpbtree);
    fclose(fptext);
}
