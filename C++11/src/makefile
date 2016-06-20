.SUFFIXES: .c .o

CC=g++
SRCS1=atomic.cpp
SRCS2=Mutex.cpp
SRCS3=ReadAndWriteMutex.cpp


OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
OBJS3=$(SRCS3:.c=.o)


EXE1=atomic
EXE2=Mutex
EXE3=ReadAndWriteMutex

all:$(OBJS1) $(OBJS2) 
	$(CC) -o $(EXE1) $(OBJS1) -g -lpthread  -std=c++11
	$(CC) -o $(EXE2) $(OBJS2) -g -lpthread	-std=c++11
	$(CC) -o $(EXE3) $(OBJS3) -g -lpthread  -std=c++11
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
