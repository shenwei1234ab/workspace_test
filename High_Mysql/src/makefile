.SUFFIXES: .c .o

CC=g++
SRCS1=mysqlTest.cpp
OBJS1=$(SRCS1:.c=.o)
EXE1=mysqlTest

all:$(OBJS1) 
	$(CC) -o $(EXE1) $(OBJS1) -O0 -g -gdwarf-2 -pg -lpthread -I/usr/include/ -L/usr/lib64/mysql -lmysqlclient
.c.o:
	$(CC) -Wall -g -o $@ -c $< 
clean:
	
