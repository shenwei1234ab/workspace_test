.SUFFIXES: .c .o

CC=g++
SRCS1=rtime.c time_clnt.c
SRCS2=time_proc.c time_svc.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=rtime 
EXE2=time_server

all:$(OBJS1)  $(OBJS2) 
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg
	$(CC) -o $(EXE2) $(OBJS2)  -O0 -g -gdwarf-2 -pg 
.c.o:
	$(CC)  -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
