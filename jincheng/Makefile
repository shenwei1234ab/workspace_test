CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Helloworld3.o

LIBS =

TARGET =	Helloworld3

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
