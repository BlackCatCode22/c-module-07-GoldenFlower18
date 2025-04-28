CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRCS = main.cpp Animal.cpp Zoo.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = zookeeper_challenge

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run