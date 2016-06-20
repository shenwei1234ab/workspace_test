.SUFFIXES: .c .o

CC=g++
SRCS1=test.cpp
OBJS1=$(SRCS1:.c=.o)


EXE1=test

all:$(OBJS1)  
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg
	
.c.o:
	$(CC) -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
