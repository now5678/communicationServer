SRC = test.cpp
TARGET = app
CXX = g++
FLAG = -Wall -g
OBJS = $(SRC:.cpp=.o)
%.o : %.cpp
	$(CXX) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(FLAG) $^ -o $@
.PHONY: clean
clean:
	rm -r *.o $(TARGET)
