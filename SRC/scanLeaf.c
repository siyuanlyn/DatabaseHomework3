/*
    Applies function "f" to every key in page "p"
 */
#include "def.h"

scanLeaf(p, f)
struct PageHdr *p;
int (*f)();
{
    struct KeyRecord *keyptr;

    /* traverse all keys in this page */
    keyptr = p->KeyListPtr;
    while (keyptr != NULL) {
        f(keyptr);
        keyptr = keyptr->Next;
    }
}
