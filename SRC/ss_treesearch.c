#include "def.h"

int ss_treesearch( PageNo, key)
PAGENO PageNo;
char *key;
{
	POSTINGSPTR result;
    PAGENO           ChildPage;
    struct KeyRecord *KeyListTraverser;  /* Pointer to list of keys */
    struct PageHdr   *PagePtr;
    PAGENO	FindPageNumOfChild();
    struct PageHdr   *FetchPage();

    PagePtr = FetchPage(PageNo);

    if (IsLeaf(PagePtr)) {
        result = ss_searchLeaf(PagePtr, key);
    }
    /* The root page contains zero keys */
    else if ((IsNonLeaf(PagePtr)) && (PagePtr->NumKeys == 0))  {
        /* keys, if any, will be stored in Page# 2
           THESE PIECE OF CODE SHOULD GO soon! **/
        result = ss_treesearch(FIRSTLEAFPG,key);
    } else if ((IsNonLeaf(PagePtr)) && (PagePtr->NumKeys > 0))  {
        KeyListTraverser = PagePtr->KeyListPtr;
        ChildPage = KeyListTraverser->PgNum;
        result = ss_treesearch(ChildPage,key);
    }
    /* -christos-: free the space of PagePtr - DONE! */
    FreePage(PagePtr);
    return ( result);
}
