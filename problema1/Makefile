SRC_DIR						= src
OBJ_DIR 					= obj
BIN_DIR						= bin
CSV_DIR						= csv
EPS_DIR						= eps

MAKE	 = Makefile

BIN_MAIN 		= $(BIN_DIR)/problema1
BIN_MEDIR 	= $(BIN_DIR)/medir_problema1

OBJ_MAIN 			= $(OBJ_DIR)/main.o
OBJ_MEDIR 		= $(OBJ_DIR)/medir.o
OBJ_RESOLVER	= $(OBJ_DIR)/resolver.o

SRC_MAIN 			= $(SRC_DIR)/main.cpp
SRC_MEDIR 		= $(SRC_DIR)/medir.cpp
SRC_RESOLVER 	= $(SRC_DIR)/resolver.cpp

HDRS	= $(SRC_DIR)/problema1.h $(SRC_DIR)/utils.h

CXX     	= g++
CXXFLAGS	= -g -Wall -Wno-unused-parameter -Wextra
LDFLAGS 	= -lrt

all: crear_carpetas $(BIN_MAIN) $(BIN_MEDIR)

$(BIN_MAIN): $(OBJ_MAIN) $(OBJ_RESOLVER)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BIN_MEDIR): $(OBJ_MEDIR) $(OBJ_RESOLVER)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_MAIN): $(SRC_MAIN) $(SRC_RESOLVER) $(HDRS) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_MEDIR): $(SRC_MEDIR) $(SRC_RESOLVER) $(HDRS) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_RESOLVER): $(SRC_RESOLVER) $(HDRS) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: crear_carpetas clean clean_bin clean_csv clean_eps

crear_carpetas:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(CSV_DIR)
	@mkdir -p $(EPS_DIR)

clean:
	rm -rf $(OBJ_DIR)

clean_bin:
	rm -rf $(BIN_DIR)

clean_csv:
	rm -rf $(CSV_DIR)

clean_eps:
	rm -rf $(EPS_DIR)