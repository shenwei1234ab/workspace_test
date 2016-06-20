.SUFFIXES: .c .o

CC=g++
SRCS1=Client.cpp
SRCS2=Server.cpp
SRCS3=NonBlockingClient.cpp  
SRCS4=NonBlockingServer.cpp  


OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
OBJS3=$(SRCS3:.c=.o)
OBJS4=$(SRCS4:.c=.o)

EXE1=Client
EXE2=Server
EXE3=NonBlockingClient
EXE4=NonBlockingServer
all:$(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)
	$(CC) -o $(EXE1) $(OBJS1) -g -lpthread
	$(CC) -o $(EXE2) $(OBJS2) -g -lpthread
	$(CC) -o $(EXE3) $(OBJS3) -g -lpthread
	$(CC) -o $(EXE4) $(OBJS4) -g -lpthread
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	
