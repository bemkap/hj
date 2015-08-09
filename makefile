CC   = g++
FLAGS= -Wall -lGL -lGLU -lglut
BIN  = hj
SRC  = $(wildcard *.cc)
HEA  = $(wildcard *.hh)
OBJ  = $(SRC:.cc=.o)

$(BIN): $(OBJ) $(HEA)
	$(CC) $(FLAGS) -o $(BIN) $(OBJ)

%.o: %.cc
	$(CC) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(BIN) $(OBJ)
