CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = main.o map.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) map.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
