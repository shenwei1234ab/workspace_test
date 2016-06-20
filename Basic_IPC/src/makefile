.SUFFIXES: .c .o

CC=g++
SRCS1=Pipe.cpp
SRCS2=FifoRead.cpp 
SRCS3=FifoWrite.cpp



OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
OBJS3=$(SRCS3:.c=.o)

EXE1=Pipe
EXE2=FifoRead
EXE3=FifoWrite


all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -g
	$(CC) -o $(EXE2) $(OBJS2) -g
	$(CC) -o $(EXE3) $(OBJS3) -g
	
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
