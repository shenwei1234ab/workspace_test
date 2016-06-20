.SUFFIXES: .c .o

CC=g++
SRCS1=thread1.cpp
OBJS1=$(SRCS1:.c=.o)


EXE1=thread1

all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -g -lpthread
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
