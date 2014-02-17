#include "defn.g"
#include "comwords.h"

/* returns TRUE (=1) if 'word' is in the list
   of common words
 */

iscommon( word )
char *word;
{
    int pos;

    if( (pos = binsearch( word, comwords, NO_COMMON_WORDS ) ) == ERROR)
        return(FALSE);
    else
        return( TRUE );
}
