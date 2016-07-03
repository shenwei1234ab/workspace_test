.SUFFIXES: .c .o

CC=g++
SRCS1=main.cpp main2.cpp
OBJS1=$(SRCS1:.c=.o)


EXE1=mianshiTest

all:$(OBJS1)  
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2   -pg -std=c++0x
	
.c.o:
	$(CC) -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
