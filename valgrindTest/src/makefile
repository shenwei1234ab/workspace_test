.SUFFIXES: .c .o

CC=g++
CBSJ=valgrindTest.cpp
OBJS=$(CBSJ:.c=.o)
EXXX=valgrindTest

start:$(OBJS)
	$(CC) -o $(EXXX) $(CBSJ) -O0 -g -gdwarf-2 -pg 
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(EXXX)
