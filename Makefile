CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = loadbalancer
SRCS = main.cpp loadbalancer.cpp webserver.cpp request.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

# build the executable from object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# run the executable
run: $(TARGET)
	./$(TARGET)