.SUFFIXES: .c .o

CC=g++
SRCS1=process.cpp
SRCS2=execTest.cpp



OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=process
EXE2=execTest


all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -g
	$(CC) -o $(EXE2) $(OBJS2) -g
	
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
