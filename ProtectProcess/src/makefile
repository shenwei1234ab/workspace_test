.SUFFIXES: .c .o

CC=g++
CBSJ=ProtectTest.cpp
CBSJ2=ProtectClient.cpp
OBJS=$(CBSJ:.c=.o)
OBJS2=$(CBSJ2:.c=.o)
EXXX=ProtectTest
EXXX2=ProtectClient

start:$(OBJS)
	$(CC) -o $(EXXX) $(CBSJ) -O0 -g -gdwarf-2 -pg
	$(CC) -o $(EXXX2) $(CBSJ2) -O0 -g -gdwarf-2 -pg
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(EXXX)
