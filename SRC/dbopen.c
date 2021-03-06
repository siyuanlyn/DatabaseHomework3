/* opens or creates the three files (btree, postings & text files) */

/* modified by Frank Andrasco to initialize the first record of postings file*/

#include <stdio.h>
#include "def.h"

FILE *fppost, *fpbtree, *fptext;

dbopen() {
    FILE *fopen();
    if ((fppost = fopen("POSTINGSFILE", "r+")) == NULL) {
        POSTINGSPTR EmptyList = -1;
        int i;
        printf ("Creating postings file...\n");
        fppost = fopen("POSTINGSFILE","w+");

        initializePostingsFile();
    }

    if ((fpbtree = fopen("B-TREE_FILE", "r+")) == NULL) {
        printf ("Creating B-tree file...\n");
        fpbtree = fopen("B-TREE_FILE","w+");
        CreateRoot();	/* an empty root page */
    }
    if ((fptext = fopen("TEXTFILE", "r+")) == NULL) {
        printf ("Creating text file...\n");
        fptext = fopen("TEXTFILE","w+");
        if( fptext == NULL) {
            printf("No write access on TEXTFILE - opening for read only\n");
            fptext = fopen("TEXTFILE", "r");
        }
    }
}
