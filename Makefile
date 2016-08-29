
list: list.o
	gcc list.o -o list

list.o: list.c list.h common.h
	gcc -c -O2 -Wall list.c

.PHONY: clean
clean:
	@rm list.o list
