lib:
	gcc -Wall -Werror src/cvec.c -c && ar rcs cvec.a cvec.o 

clean:
	rm -f test cvec.o cvec.a

test: clean lib
	gcc -Wall -Werror -O2 -static testing/test.c cvec.a -o test && ./test