#include <ctype.h>

/* converts the upper case letters of
   string 's' into lower case
 */
strtolow( s)
char *s;
{
    int i;
    for( i=0; s[i] != '\0'; i++)
        if( isalpha(s[i]) && isupper(s[i]) )
            s[i] = tolower( s[i]);
}
