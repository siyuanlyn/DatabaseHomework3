/*********************************************************************
*                                                                    *
*    This function inserts a 
	(key, offset)
     entry in the B-tree, even if it is empty initially.
     If the B-Tree does exist, the key is
*    sent to PropagatedInsertion for insertion and any               *
*    possible page splits are handled there by recursively           *
*    propagating down and then up the tree.  If PropagatedInsertion  *        
*    returns the value NULL, this function terminates, otherwise     *
*    the root must be split (SplitRoot()).                           *
*                                                                    *
*********************************************************************/



#include "def.h"

extern FILE *fpbtree;
extern int iCount;	/* counts the number of inserted words */

InsertTree(Key,TextOffset)
TEXTPTR  TextOffset;
char    *Key;
{
    struct upKey *MiddleKey;
    char              Ch;
    KEYLEN	    keyLen;
    struct upKey *PropagatedInsertion();


    /* Print an error message if the key is too long */
    keyLen = strlen(Key);
    if ( (keyLen > MAXWORDSIZE) ||
            (keyLen > (PAGESIZE -
                       sizeof(struct PageHdr) -
                       sizeof(POSTINGSPTR) - sizeof(KEYLEN))) ) {
        printf ("ERROR: key is too long-operation aborted\n");
        printf ("offending key:\"%s\"\n", Key);
        return;
    }

    /* insert key */
    MiddleKey = PropagatedInsertion (ROOT,Key,TextOffset);

    /* The Root Must be Split */
    if (MiddleKey != NULL)
        SplitRoot(ROOT,MiddleKey);

    iCount++;
}
