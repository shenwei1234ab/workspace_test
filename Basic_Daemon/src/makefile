.SUFFIXES: .c .o

CC=g++
SRCS1=DaemonTest.cpp
SRCS2=SessionTest.cpp
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=DaemonTest
EXE2=SessionTest


all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -g
	$(CC) -o $(EXE2) $(OBJS2) -g
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
