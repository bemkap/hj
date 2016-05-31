CC      = g++
CPPFLAGS= `pkg-config --cflags glew glfw3 lua5.2` -Wall -g -std=c++11
LDFLAGS = `pkg-config --libs glew glfw3 lua5.2`
LDFLAGS+= -lboost_filesystem -lboost_system -lSOIL
SRC     = $(wildcard *.cc)
HEA     = $(wildcard *.hh)
OBJ     = $(SRC:.cc=.o)
BIN     = hj

$(BIN): $(OBJ) $(HEA)
	$(CC) $(LDFLAGS) $(OBJ) -o $(BIN)

.PHONY: run
run:
	./$(BIN)

.PHONY: clean
clean:
	rm -f $(BIN) $(OBJ)
