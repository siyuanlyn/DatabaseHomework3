/*
   It returns the page-number of the next page
   in the btree file
 */





#include "def.h"
extern FILE *fpbtree;

PAGENO getNewPageNum() {
    PAGENO new;
    long ffsize();

    new = (PAGENO) ffsize(fpbtree)/PAGESIZE + 1;
    return(new);
}
