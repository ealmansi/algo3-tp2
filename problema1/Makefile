SRC_DIR						= src
OBJ_DIR 					= obj
BIN_DIR						= bin

MAKE	 = Makefile

BIN_MAIN 		= $(BIN_DIR)/main
BIN_MEDIR 	= $(BIN_DIR)/medir

OBJ_MAIN 			= $(OBJ_DIR)/main.o
OBJ_MEDIR 		= $(OBJ_DIR)/medir.o
OBJ_RESOLVER	= $(OBJ_DIR)/resolver.o

SRC_MAIN 			= $(SRC_DIR)/main.cpp
SRC_MEDIR 		= $(SRC_DIR)/medir.cpp
SRC_RESOLVER 	= $(SRC_DIR)/resolver.cpp

HDR	= $(SRC_DIR)/problema1.h

CXX     	= g++
CXXFLAGS	= -g -Wall -Wno-unused-parameter -Wextra
LDFLAGS 	= -lrt

all: crear_carpetas $(BIN_MAIN) $(BIN_MEDIR)

$(BIN_MAIN): $(OBJ_MAIN) $(OBJ_RESOLVER)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BIN_MEDIR): $(OBJ_MEDIR) $(OBJ_RESOLVER)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_MAIN): $(SRC_MAIN) $(SRC_RESOLVER) $(HDR) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_MEDIR): $(SRC_MEDIR) $(SRC_RESOLVER) $(HDR) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_RESOLVER): $(SRC_RESOLVER) $(HDR) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: crear_carpetas clean clean_ejecutables

crear_carpetas:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)

clean_ejecutables:
	rm -rf $(BIN_DIR)