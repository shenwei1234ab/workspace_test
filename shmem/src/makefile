.SUFFIXES: .c .o

CC=g++
SRCS1=attachShmem.cpp
SRCS2=createShmem.cpp
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)


EXE1=attachShmem
EXE2=createShmem

all:$(OBJS1)   $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1)
	$(CC) -o $(EXE2) $(OBJS2)
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
