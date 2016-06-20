.SUFFIXES: .c .o

CC=g++
SRCS1=timeClient.c timeClientfunc.c time_xdr.c
SRCS2=timeServer.c timeServerfunc.c time_xdr.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=timeClient 
EXE2=timeServer

all:$(OBJS1)  $(OBJS2) 
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg
	$(CC) -o $(EXE2) $(OBJS2)  -O0 -g -gdwarf-2 -pg 
.c.o:
	$(CC)  -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
