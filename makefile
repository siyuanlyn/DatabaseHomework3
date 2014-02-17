main: makesub

makesub:
	cd SRC; make; cp main .. ; cp parms ..

load: clean main 
	./main < import_dict.inp   > /dev/null 

print: main
	\rm -f B-TREE_FILE POSTINGSFILE TEXTFILE
	./main < import_dict.inp  > /dev/null
	./main < Tests/test_print.inp > print.mysol

test_prefix: main
	./main < Tests/test_prefix.inp > prefix.mysol 
	diff prefix.mysol Tests/prefix.sol

test_substring: main
	./main < Tests/test_substring.inp > substring.mysol
	diff substring.mysol Tests/substring.sol

test_search: main
	./main < Tests/test_search.inp > search.mysol
	diff search.mysol Tests/search.sol

grade: main
	\rm -f B-TREE_FILE POSTINGSFILE TEXTFILE
	./main < import_dict.inp  > /dev/null
	./main < ../../grade.inp > my_answers.sol
	diff my_answers.sol ../../correct.sol

clean:
	\rm -f B-TREE_FILE POSTINGSFILE TEXTFILE RESULT 
	\rm -f SRC/*.o SRC/*~ main

spotless: clean
	cd SRC; make spotless
	\rm -f main parms all.tar

all.tar: spotless
	tar cvf all.tar DOC README SRC makefile
