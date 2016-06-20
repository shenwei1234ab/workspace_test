CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Test2.o

LIBS =

TARGET =	Test2

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
