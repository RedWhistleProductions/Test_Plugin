# Makefile for building main executable and lib.so shared library

BIN_FILE := main
BIN_OBJ_DIR := ./src/obj

LIB_FILE := lib.so
LIB_OBJ_DIR := ./lib/obj

CC := g++
CFLAGS := -c -Wall -Werror -fpic
LDFLAGS := -ldl

.PHONY: all clean

all: $(LIB_FILE) $(BIN_FILE)

$(LIB_FILE): $(wildcard ./lib/*.cpp)
	$(CC) $(CFLAGS) $^
	mv *.o $(LIB_OBJ_DIR)
	$(CC) -shared -o ./Debug/$@ $(LIB_OBJ_DIR)/*.o

$(BIN_FILE): $(wildcard ./src/*.cpp)
	$(CC) $(CFLAGS) $^
	mv *.o $(BIN_OBJ_DIR)
	$(CC) -o ./Debug/$@ $(BIN_OBJ_DIR)/*.o $(LDFLAGS)

clean:
	rm -rf $(LIB_OBJ_DIR)/*.o $(BIN_OBJ_DIR)/*.o ./Debug/$(LIB_FILE) ./Debug/$(BIN_FILE)
