.SUFFIXES: .c .o

CC=g++
SRCS1=FileTest.cpp
OBJS1=$(SRCS1:.c=.o)


EXE1=FileTest

all:$(OBJS1)   $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
