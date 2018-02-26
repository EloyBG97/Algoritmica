BIN = ./BIN
SRC = ./SRC
OBJ = ./OBJ
INC = ./INC
CPP = g++ -Wall -std=c++11 -O2

all: $(BIN)/ViajanteComercio

$(BIN)/ViajanteComercio: $(OBJ)/TDASolucion.o $(OBJ)/main.o
	$(CPP) -o $(BIN)/ViajanteComercio $(OBJ)/TDASolucion.o $(OBJ)/main.o
	
$(OBJ)/TDASolucion.o: $(INC)/TDASolucion.h $(SRC)/TDASolucion.cpp
	$(CPP) -c $(SRC)/TDASolucion.cpp -o $(OBJ)/TDASolucion.o -I$(INC)
	
$(OBJ)/main.o: $(INC)/TDASolucion.h $(SRC)/main.cpp
	$(CPP) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)
	
clean:
	rm -f $(BIN)/* $(OBJ)/*
