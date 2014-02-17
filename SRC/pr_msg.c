#include "defn.g"

/* prints a message from the (text) file,
      'fp'
   starting at
      'start'
    with the TAG character.
 */

pr_msg( start, fp)
long start;
FILE *fp;
{
    int c;
    int i;

    fseek( fp, (long) start, 0);
    c = getc( fp);
    if( c != TAG) {
        printf("pr_msg: WARNING -");
        printf("document does not start with TAG at %ld\n",
               start);
    }

    while( ((c=getc(fp)) != TAG ) &&
            (c!=EOF)) {
        putchar(c);
    }
}
