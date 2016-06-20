.SUFFIXES: .c .o

CC=g++
SRCS1=libeventTest.cpp
OBJS1=$(SRCS1:.c=.o)


EXE1=libeventTest

all:$(OBJS1)   $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg -levent
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
