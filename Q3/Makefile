CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = main.o order.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
order.o: order.cpp order.h
	$(CXX) $(CXXFLAGS) order.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
