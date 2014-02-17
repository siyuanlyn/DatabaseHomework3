#include "def.h"

FindPrefixPosition(KeyListTraverser,Key,Found,NumKeys,Count)
struct KeyRecord *KeyListTraverser;  /* Pointer to the list of keys */
int              *Found,
Count;
NUMKEYS           NumKeys;
char             *Key;       /* The new possible key */
{
	int    Result;
    int CheckPrefix();

    /* -christos- the next block probably provides for
    insertion in empty list (useful for insertion in root
    for the first time! */

    if( NumKeys == 0 ) {
        *Found = FALSE;
        return(Count);
    }

    /* Compare the the possible new key with the key stored in B-Tree */
    Result = CheckPrefix(Key, KeyListTraverser->StoredKey);

    NumKeys = NumKeys - 1;
    Count = Count + 1;

    if (Result == 0)         /* Match found */
    {
        *Found = TRUE;

        return(Count);       /* Location of matched key */
    } else                     /* No match yet */
        *Found = FALSE;

    if (NumKeys > 0) {
        if (Result == 1)     /* New key < stored key */
            return(Count - 1); /* Location before stored key */
        else                 /* New key > stored key: keep searching */
        {
            KeyListTraverser = KeyListTraverser->Next;
            return(FindPrefixPosition(KeyListTraverser,Key,
                                         Found,NumKeys,Count));
        }
    } else   /* this is the last key in the list -- search must terminate */
    {
        if (Result == 1)      /* New key < stored key */
            return(Count - 1);  /* Location before stored key */
        else
            return(Count);      /* New key will be the last key */
    }
}



