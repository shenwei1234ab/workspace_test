.SUFFIXES: .c .o

CC=g++
SRCS1=ThreadCreate.cpp 
OBJS1=$(SRCS1:.c=.o)

EXE1=ThreadCreate

all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -g -lpthread
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
