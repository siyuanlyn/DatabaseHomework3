CC = gcc
CFLAGS= -g
OBJ= main.o PrintTree.o CompareKeys.o\
	CreatePosting.o FetchPage.o InsertKeyInLeaf.o InsertTree.o\
	UpdatePostingsFile.o PropagatedInsertion.o \
	SplitPage.o FindInsertionPosition.o InsertKeyInNonLeaf.o\
	FlushPage.o FreePage.o CreateRoot.o FindNumPagesInTree.o\
	FindPageNumOfChild.o SplitRoot.o \
	treesearch.o search.o searchLeaf.o getpostings.o \
	setparms.o dbopen.o dbclose.o insert.o buildIndex.o\
	hashtab.o getNewPageNum.o fillIn.o \
	scanTree.o scanLeaf.o printKey.o printOcc.o\
        getrec.o freerec.o initializePostingsFile.o isfull.o \
	postStats.o printTreeInOrder.o deleteKey.o strdist.o \
	prefix_search.o prefix_searchLeaf.o prefix_treesearch.o \
	CheckPrefix.o FindPrefixPosition.o \
	ss_search.o ss_searchLeaf.o ss_treesearch.o \
	CheckSubstring.o

GENUTILOBJ= strsave.o ffsize.o strtolow.o
OBJ1= getword.o iscommon.o binsearch.o check_word.o pr_msg.o
ALLOBJ = $(OBJ) $(OBJ1) $(GENUTILOBJ)
SRC= main.c PrintTree.c CompareKeys.c\
	CreatePosting.c FetchPage.c InsertKeyInLeaf.c InsertTree.c\
	UpdatePostingsFile.c PropagatedInsertion.c \
	SplitPage.c FindInsertionPosition.c InsertKeyInNonLeaf.c\
	FlushPage.c FreePage.c CreateRoot.c FindNumPagesInTree.c\
	FindPageNumOfChild.c SplitRoot.c \
	treesearch.c search.c searchLeaf.c getpostings.c \
	setparms.c dbopen.c dbclose.c insert.c buildIndex.c\
	hashtab.c getNewPageNum.c fillIn.c \
	scanTree.c scanLeaf.c printKey.c  printOcc.c\
        getrec.c freerec.c initializePostingsFile.c isfull.c \
	postStats.c printTreeInOrder.c deleteKey.c strdist.c \
	prefix_search.c prefix_searchLeaf.c prefix_treesearch.c \
	CheckPrefix.c FindPrefixPosition.c \
	ss_search.c ss_searchLeaf.c ss_treesearch.c \
	CheckSubstring.c

GENUTILSRC= strsave.c ffsize.c strtolow.c
SRC1= getword.c iscommon.c binsearch.c check_word.c pr_msg.c
ALLSRC = $(SRC) $(SRC1) $(GENUTILSRC)
ALLDFN =  def.h defn.g comwords.h # array.h

main: $(ALLOBJ)
	${CC} $(CFLAGS) $(ALLOBJ) -lm -o main

$(OBJ): def.h

$(OBJ) $(OBJ1): defn.g

printout: *.h *.g *.c 
	pr $? | qpr 
	touch printout

spotless: cleanup cleanupo
	\rm -f main

cleanupo:
	\rm -f *.o

clean: cleanupo

cleanup:
	\rm -f TEXTFILE POSTINGSFILE B-TREE_FILE

version: $(ALLSRC) def.h comwords.h defn.g makefile README.version parms main DOC
	tar cvf version $(ALLSRC) def.h comwords.h defn.g makefile README.version parms main DOC

all.tar: $(ALLSRC) def.h comwords.h defn.g makefile parms DOC/* test.inp
	tar cvfh all.tar $(ALLSRC) def.h comwords.h  defn.g  test.inp \
	makefile parms DOC

test.out: main test.inp parms
	cat test.inp | main > test.out

checkin:
	ci -l $(REV) $(ALLSRC) $(ALLDFN) makefile parms 

checkout:
	co -l $(REV) $(ALLSRC) $(ALLDFN) makefile parms 
