.SUFFIXES: .c .o

CC=g++
SRCS1=ReverseList.cpp
OBJS1=$(SRCS1:.c=.o)

EXE1=ReverseList


all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -g
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
