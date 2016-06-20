.SUFFIXES: .c .o

CC=g++
SRCS1=FileTest.cpp
SRCS2=NonBlockingRead.cpp

OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)



EXE1=FileTest
EXE2=NonBlockingRead



all:$(OBJS1) $(OBJS2) 
	$(CC) -o $(EXE1) $(OBJS1) -g 
	$(CC) -o $(EXE2) $(OBJS2) -g 
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
