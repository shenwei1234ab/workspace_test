.SUFFIXES: .c .o

CC=g++
SRCS1=Client.cpp pub.cpp
SRCS2=Server.cpp pub.cpp
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=Client
EXE2=Server

all:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1) -g -lpthread
	$(CC) -o $(EXE2) $(OBJS2) -g -lpthread
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
