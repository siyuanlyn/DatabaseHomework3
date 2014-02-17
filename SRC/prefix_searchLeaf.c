#include "def.h"
int prefix_searchLeaf( PagePtr, key)
struct PageHdr *PagePtr;
char *key;
{
	struct KeyRecord *KeyListTraverser;
    int               InsertionPosition;     /* Position for insertion */
    int     FindPrefixPosition();
    int               Count, Found, i;
    struct PageHdr   *FetchPage();

    Count = 0;
    int PrefixFind = 0;
    struct KeyRecord *SavedKLT;
    /* Find insertion position */
    KeyListTraverser = PagePtr->KeyListPtr;
    InsertionPosition = FindPrefixPosition(KeyListTraverser,key,&Found,
                        PagePtr->NumKeys,Count);

    /* key is already in the B-Tree */
    if (Found == TRUE) {
        for (i = 0; i < InsertionPosition - 1; i++)
            KeyListTraverser = KeyListTraverser->Next;
		printf("Prefix found in %s\n", KeyListTraverser->StoredKey);
		PrefixFind++;
		SavedKLT = KeyListTraverser;
		KeyListTraverser = KeyListTraverser->Next;
		if(KeyListTraverser == NULL){
			struct PageHdr *NextPage = (struct PageHdr *)FetchPage(PagePtr->PgNumOfNxtLfPg);
			// printf("%d\n", PagePtr->PgNumOfNxtLfPg);
			PagePtr = NextPage;
			KeyListTraverser = PagePtr->KeyListPtr;
			// printf("%d\n", KeyListTraverser);
		}
		while(KeyListTraverser != NULL){
			if(CheckPrefix(key, KeyListTraverser->StoredKey) != 0){
				break;
			}
			printf("Prefix found in %s\n", KeyListTraverser->StoredKey);
			PrefixFind++;
			KeyListTraverser = KeyListTraverser->Next;
			if(KeyListTraverser == NULL){
				if(PagePtr->PgNumOfNxtLfPg != NULLPAGENO){
					struct PageHdr *NextPage = FetchPage(PagePtr->PgNumOfNxtLfPg);
					// printf("%d\n", PagePtr->PgNumOfNxtLfPg);
					PagePtr = NextPage;
					KeyListTraverser = PagePtr->KeyListPtr;
					// printf("%d\n", KeyListTraverser);
				}
			}
		}
		printf("\"%s\" is the prefix of %d words\n", key, PrefixFind);
        return(SavedKLT->Posting);
    } else {
        return(NONEXISTENT);
    }
}
