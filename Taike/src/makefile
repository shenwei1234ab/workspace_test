.SUFFIXES: .c .o

CC=g++
CBSJ=lession37.cpp
CBSJ2=lession40.cpp
CBSJ3=lession42.cpp
CBSJ4=lession44.cpp
CBSJ5=lession45.cpp

OBJS=$(CBSJ:.c=.o)
OBJS2=$(CBSJ2:.c=.o)
OBJS3=$(CBSJ3:.c=.o)
OBJS4=$(CBSJ4:.c=.o)
OBJS5=$(CBSJ5:.c=.o)

EXXX=lession37
EXXX2=lession40
EXXX3=lession42
EXXX4=lession44
EXXX5=lession45
start:$(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5)
	$(CC) -o $(EXXX) $(CBSJ) -g -std=c++11
	$(CC) -o $(EXXX2) $(CBSJ2) -g -std=c++11
	$(CC) -o $(EXXX3) $(CBSJ3) -g -std=c++11
	$(CC) -o $(EXXX4) $(CBSJ4) -g -std=c++11
	$(CC) -o $(EXXX5) $(CBSJ5) -g -std=c++11
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	rm -f $(EXXX) 
