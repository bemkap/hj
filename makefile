CFLAGS  = `pkg-config --cflags gl glu glew lua52` -Wall -g -std=c++11
LDFLAGS = `pkg-config --libs gl glu glew lua52`
LDFLAGS+= -lglut -lboost_filesystem -lboost_system
SRC     = $(wildcard *.cc)
HEA     = $(wildcard *.hh)
OBJ     = $(SRC:.cc=.o)
BIN     = hj

$(BIN): $(OBJ) $(HEA)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(BIN) $(OBJ)

$(LIB): 

%.o: %.cc
	$(CXX) $(CFLAGS) -c $<

.PHONY: run
run:
	./$(BIN)

.PHONY: clean
clean:
	rm -f $(BIN) $(OBJ)
