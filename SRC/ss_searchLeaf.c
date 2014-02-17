#include "def.h"
int ss_searchLeaf( PagePtr, key)
struct PageHdr *PagePtr;
char *key;
{
	struct KeyRecord *KeyListTraverser;
    int               InsertionPosition;     /* Position for insertion */
    int     FindInsertionPosition();
    int               Count, Found, i;

    Count = 0;
    int wordsFound = 0;
    /* Find insertion position */
    KeyListTraverser = PagePtr->KeyListPtr;
    while(KeyListTraverser != NULL){
			
			if(CheckSubstring(key, KeyListTraverser->StoredKey) == 0){
				printf("Substring found in %s\n", KeyListTraverser->StoredKey);
				wordsFound++;
			}
			KeyListTraverser = KeyListTraverser->Next;
			if(KeyListTraverser == NULL){
				if(PagePtr->PgNumOfNxtLfPg > (PAGENO)0){
					PAGENO NextPageNo= PagePtr->PgNumOfNxtLfPg;
					struct PageHdr *NextPage;
					NextPage = FetchPage(NextPageNo);
					PagePtr = NextPage;
					KeyListTraverser = NextPage->KeyListPtr;
				}
			}
		}
	if(wordsFound != 0){
		printf("\"%s\" is in %d words\n", key, wordsFound);
	}
	
	else{
		return(NONEXISTENT);
	}
}
