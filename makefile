CC      = g++
CPPFLAGS= -I/usr/include/libdrm -I/usr/include/lua5.2 -Wall -g -std=c++11
LDFLAGS = -lGLEW -lGLU -lGL -lglfw -llua5.2 -lm -lboost_filesystem -lboost_system -lSOIL
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
