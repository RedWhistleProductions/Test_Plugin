BIN_FILE="main"
BIN_OBJ_DIR="./src/obj"

LIB_FILE="lib.so"
LIB_OBJ_DIR="./lib/obj"


#create the .so file first
g++ -c -Wall -Werror -fpic ./lib/*.cpp
mv *.o ./lib/obj
g++ -shared -o ./Debug/${LIB_FILE} ./lib/obj/*.o

# create the exe
g++ -c -Wall -Werror -fpic ./src/*.cpp
mv *.o ./src/obj
g++ -o ./Debug/main ./src/obj/*.o -ldl

