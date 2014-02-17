/**************************************************************************
 returns the number of pages currently in the B-tree
**************************************************************************/



#include "def.h"
extern FILE *fpbtree;

PAGENO FindNumPagesInTree() {
    PAGENO num;
    long ffsize();

    num = (PAGENO) ffsize(fpbtree)/PAGESIZE ;
    return(num);
}

