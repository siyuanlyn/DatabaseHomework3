/* modified by christos, Sept. 2009, 
 * - to check for input buffer overflows
 * - to check for page-numbers out of range in printPage()
 * */

/* main driver for btree-based text retreival system
 * modified by Frank Andrasco 1990
*/

#include "def.h"
#include <time.h>

/* modified by Sanjay, Oct 2000, Commented
 * out options "b","d"; added new option T 
 * for inorder traversal
 * */

/* modified by christos, Nov. 23 '91 */
/* this array containts the (growing) sizes of the
 * postings records */

long LISTSIZE[100];

extern FILE *fpbtree, *fppost, *fptext;
int btWriteCount=0,	/* number of writes on B-tree */
    btReadCount=0,	/* number of reads on B-tree */
    pWriteCount=0,	/* number of writes on postings */
    pReadCount=0;	/* number of reads on postings */
int iCount=0;		/* number of inserted words */
int sqCount=0;		/* number of successful queries */
int uqCount=0;		/* number of unsucc. queries */

main () {
    char    word[MAXWORDSIZE],word1[MAXWORDSIZE],word2[MAXWORDSIZE],low[MAXWORDSIZE], high[MAXWORDSIZE];
    char    cmd[MAXWORDSIZE];		/* string to hold a command */
    char    fname[MAXWORDSIZE];		/* name of input file */
    PAGENO	i;
	int ranking;
    int goOn;
    int printKey(), printOcc();

    setparms();	/* reads the pagesize and the number of ptrs/postigs_record */
    dbopen();	/* opens or creates the three files (btree, postings, text) */

    goOn = TRUE;
    while( goOn) {
        printf("\n\t*** These are your commands .........\n");
        printf("\t\"C\" to scan the tree\n");
		printf("\t\"i\" to insert\n");
        printf("\t\"M\" to search and print instances of the key as a substring\n");
        printf("\t\"p\" to print a btree page\n");
        printf("\t\"P\" to search and print instances of the key as a prefix\n");
        printf("\t\"s\" to search, and print the key\n");
        printf("\t\"S\" to search, and print the key, posting list pairs\n");
        printf("\t\"T\" to print the btree in inorder format\n");
        printf("\t\"x\" to exit\n");
        /* printf("\"d\" to display statistics, \"c\" to clear them,\n"); */
        scanf("%s", cmd);
	    assert( strlen(cmd) < MAXWORDSIZE);
        switch( cmd[0]) {
        case 'C':
            printf("\n*** Scanning... \n");
            scanTree(printOcc);
            break;
        case 'i':
            printf("\tgive input file name: ");
            scanf("%s", fname);
	    assert( strlen(fname) < MAXWORDSIZE);
            printf("\n*** Inserting %s\n", fname);
            insert(fname);
            break;
        case 's':
            printf("enter search-word: ");
            scanf("%s", word);
	    assert( strlen(word) < MAXWORDSIZE);
	    printf("\n*** Searching for word %s \n", word);
            search(word, FALSE);
            break;
        case 'S':
            printf("enter search-word: ");
            scanf("%s", word);
	    assert( strlen(word) < MAXWORDSIZE);
	    printf("\n*** Searching for word %s \n", word);
            search(word, TRUE);
            printf("%d pages read\n", btReadCount);
            btReadCount = 0;
            break;
        case 'P':
            printf("enter search-prefix: ");
            scanf("%s", word);
	    assert( strlen(word) < MAXWORDSIZE);
	    printf("\n*** Searching for prefix %s \n", word);
            prefix_search(word, FALSE);
            printf("%d pages read\n", btReadCount);
            btReadCount = 0;
            break;
        case 'M':
            printf("enter search-substring: ");
            scanf("%s", word);
	    assert( strlen(word) < MAXWORDSIZE);
	    printf("\n*** Searching for substring %s \n", word);
            ss_search(word, FALSE);
            printf("%d pages read\n", btReadCount);
            btReadCount = 0;
            break;
        case 'p':
            printf("pagenumber=?\n");
            scanf("%s", cmd);
	    assert( strlen(cmd) < MAXWORDSIZE);
            i = (PAGENO) atoi(cmd);
            printPage(i,fpbtree);
            break;
        case 'T':
            printf("\n*** Printing tree in order .........\n");
            PrintTreeInOrder(ROOT,0);
            break;
        case 'x':
            printf("\n*** Exiting .........\n");
            goOn = FALSE;
            break;
        default:
            printf("\n*** Illegal command \"%s\"\n", cmd);
            break;
        }
    }

    dbclose();
    return(0);
    /* PrintTree();  */
}
