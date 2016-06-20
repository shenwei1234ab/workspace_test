.SUFFIXES: .c .o

CC=g++
CBSJ=DaemonnTest1.cpp
OBJS=$(CBSJ:.c=.o)
EXXX=DaemonnTest1

start:$(OBJS)
	$(CC) -o $(EXXX) $(CBSJ) -g
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(EXXX)
