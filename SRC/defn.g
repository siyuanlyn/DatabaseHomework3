#include <stdio.h>
#include <ctype.h>

/****************************************/
/* Definitions of constants.		*/
/****************************************/

#define FALSE		0
#define TRUE		1
#define ERROR		(-2)
#define PNULL		(-1)	/* null pointer */
#define EOS		'\0'	/* end of string */
#define ABSIZE		27	/* alphabet size + 1 for the blank */
#define TAG		'\026'	/* ctr-V. Marks the beginning  */
				/*     of a message in the text */
				/*     and sig. files */
#define DOCSTART	((int) TAG)
#define MASK		0377	/* to avoid the sign extension */
				/* during a char-to-int conversion */



/****************************************/
/* Useful macro definitions.		*/
/****************************************/

#define order(c)	( (c) == ' ' ? 0 :	\
			   isdigit(c) ? (c) - '0' + 1 :	\
			   ! isalpha(c) ? ABSIZE :		\
			   islower(c) ? (c) - 'a' + 1 : \
					(c) - 'A' + 1 )
#define max(A, B)	( (A) > (B) ? (A) : (B) )
#define min(A, B)	( (A) < (B) ? (A) : (B) )

#define ck_malloc( ptr, var_name)	( ptr == NULL ? 		 \
					  ( printf("cannot alloc. %s\n", \
					      var_name ) , ERROR) : 	 \
					  TRUE )

#define ck_file( fp, fname)		( fp == NULL ?		\
					  (printf("cannot open %s\n",   \
					      fname ) , ERROR)  :	\
				 	  TRUE )

#define fsize(fp)			( fseek(fp, (long) 0, 2), ftell(fp) )

#define ck_io( status, msg)		( (status) <= 0 ? 		\
					  (printf("i/o error in %s\n", msg), \
					  ERROR) : TRUE )


#define check(status)		if( (status) == ERROR) return( ERROR)

#define DEBUG			/* to enable debugging statements */
#undef DEBUG

/* we don't need ASSERT and botch() - there is assert.h */
/*
#ifdef  DEBUG
#define ASSERT(p)		if( !(p) ) botch("p"); else
#else
#define ASSERT(p)		
#endif
*/
