.SUFFIXES: .c .o

CC=g++
SRCS1= test_srv_func.c test_svc.c
SRCS2=test_clnt_func.c test_clnt.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXE1=test_server
EXE2=test_client

all:$(OBJS1)  $(OBJS2) 
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg
	$(CC) -o $(EXE2) $(OBJS2)  -O0 -g -gdwarf-2 -pg
.c.o:
	$(CC)  -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
