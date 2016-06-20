.SUFFIXES: .c .o

CC=g++
SRCS1=Mutex1.cpp
SRCS2=Cond.cpp
SRCS3=Mutex3.cpp
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
OBJS3=$(SRCS3:.c=.o)

EXE1=Mutex
EXE2=Cond
EXE3=Mutex3


all:$(OBJS1) $(OBJS2) $(OBJS3) 
	$(CC) -o $(EXE1) $(OBJS1) -g -lpthread
	$(CC) -o $(EXE2) $(OBJS2) -g -lpthread 
	$(CC) -o $(EXE3) $(OBJS3) -g -lpthread 
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
