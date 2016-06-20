.SUFFIXES: .c .o

CC=g++
SRCS0=test0.cpp
SRCS1=test.cpp
SRCS2=test2.cpp
SRCS3=Mytest.cpp
OBJS0=$(SRCS0:.c=.o)
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
OBJS3=$(SRCS3:.c=.o)

EXE0=test0
EXE1=test
EXE2=test2
EXE3=Mytest

all:$(OBJS0) $(OBJS1) $(OBJS2) $(OBJS3)
	$(CC) -o $(EXE0) $(OBJS0)  -O0 -g -gdwarf-2 -pg
	$(CC) -o $(EXE1) $(OBJS1)  -O0 -g -gdwarf-2 -pg
		$(CC) -o $(EXE2) $(OBJS2)  -O0 -g -gdwarf-2 -pg
			$(CC) -o $(EXE3) $(OBJS3)  -O0 -g -gdwarf-2 -pg
.c.o:
	$(CC) -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*
