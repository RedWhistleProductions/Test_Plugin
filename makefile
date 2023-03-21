# Makefile for building main executable and lib.so shared library

BIN_FILE := app
BIN_OBJ_DIR := ./src/obj
BIN_RELEASE_DIR := ./Release

LIB_FILE := lib.so
LIB_OBJ_DIR := ./lib/obj
LIB_RELEASE_DIR := ./Release

CC := g++
CFLAGS := -Wall -fpic
LDFLAGS := -ldl

.PHONY: all clean release

all: $(LIB_FILE) $(BIN_FILE)

$(LIB_FILE): $(wildcard ./lib/*.cpp)
	$(CC) $(CFLAGS) -c $^
	mv *.o $(LIB_OBJ_DIR)
	$(CC) -shared -o ./Debug/$@ $(LIB_OBJ_DIR)/*.o

$(BIN_FILE): $(wildcard ./src/*.cpp)
	$(CC) $(CFLAGS) -c $^
	mv *.o $(BIN_OBJ_DIR)
	$(CC) -o ./Debug/$@ $(BIN_OBJ_DIR)/*.o $(LDFLAGS)

release: $(LIB_FILE) $(BIN_FILE)
	mkdir -p $(BIN_RELEASE_DIR) $(LIB_RELEASE_DIR)
	$(CC) $(CFLAGS) -O2 -DNDEBUG -c ./lib/*.cpp
	$(CC) -shared -o $(LIB_RELEASE_DIR)/$(LIB_FILE) *.o
	$(CC) $(CFLAGS) -O2 -DNDEBUG -o $(BIN_RELEASE_DIR)/$(BIN_FILE) ./src/*.cpp $(LDFLAGS) -L$(LIB_RELEASE_DIR) 

clean:
	rm -rf $(LIB_OBJ_DIR)/*.o $(BIN_OBJ_DIR)/*.o ./Debug/$(LIB_FILE) ./Debug/$(BIN_FILE) $(BIN_RELEASE_DIR)/$(BIN_FILE) $(LIB_RELEASE_DIR)/$(LIB_FILE)
