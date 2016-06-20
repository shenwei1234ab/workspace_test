.SUFFIXES: .c .o

CC=g++
CBSJ1=ThreadTest.cpp
CBSJ2=AtomicTest.cpp
CBSJ3=YieldTest.cpp
CBSJ4=ProductAndConsumer.cpp
CBSJ5=WaitFor.cpp
CBSJ6=Wait.cpp
CBSJ7=MutexTest.cpp
CBSJ8=AtomicTest2.cpp
CBSJ9=PromiseTest.cpp
CBSJ10=stdFuture.cpp


OBJS1=$(CBSJ1:.c=.o)
OBJS2=$(CBSJ2:.c=.o)
OBJS3=$(CBSJ3:.c=.o)
OBJS4=$(CBSJ4:.c=.o)
OBJS5=$(CBSJ5:.c=.o)
OBJS6=$(CBSJ6:.c=.o)
OBJS7=$(CBSJ7:.c=.o)
OBJS8=$(CBSJ8:.c=.o)
OBJS9=$(CBSJ9:.c=.o)
OBJS10=$(CBSJ10:.c=.o)


EXXX1=ThreadTest
EXXX2=AtomicTest
EXXX3=YieldTest
EXXX4=ProductAndConsumer
EXXX5=WaitFor
EXXX6=Wait
EXXX7=MutextTest
EXXX8=AtomicTest2
EXXX9=PromiseTest
EXXX10=stdFuture


start:$(OBJS)
	$(CC) -o $(EXXX1) $(CBSJ1) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX2) $(CBSJ2) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX3) $(CBSJ3) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX4) $(CBSJ4) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX5) $(CBSJ5) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX6) $(CBSJ6) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX7) $(CBSJ7) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX8) $(CBSJ8) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX9) $(CBSJ9) -g -std=c++11 -lpthread
	$(CC) -o $(EXXX10) $(CBSJ10) -g -std=c++11 -lpthread
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(EXXX)
