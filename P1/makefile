CPP = g++ -std=c++11 -O2 -Wall
BIN = ./BIN
SRC = ./SRC
OBJ = ./OBJ
DOC = ./DOC
INC = ./INC

all: $(BIN)/BeneficioOptimo_DyV $(BIN)/BeneficioOptimo_It

$(BIN)/BeneficioOptimo_DyV: $(OBJ)/BeneficioOptimo_DyV.o
	$(CPP) -o $(BIN)/BeneficioOptimo_DyV $(OBJ)/BeneficioOptimo_DyV.o

$(BIN)/BeneficioOptimo_It: $(OBJ)/BeneficioOptimo_It.o
	$(CPP) -o $(BIN)/BeneficioOptimo_It $(OBJ)/BeneficioOptimo_It.o

$(OBJ)/BeneficioOptimo_DyV.o: $(SRC)/BeneficioOptimo_DyV.cpp
	$(CPP) -I$(INC) -c $(SRC)/BeneficioOptimo_DyV.cpp -o $(OBJ)/BeneficioOptimo_DyV.o

$(OBJ)/BeneficioOptimo_It.o: $(SRC)/BeneficioOptimo_It.cpp
	$(CPP) -I$(INC) -c $(SRC)/BeneficioOptimo_It.cpp -o $(OBJ)/BeneficioOptimo_It.o

# ----------------------------------------------- #

doxy:
	doxygen $(DOC)/doxPractica.txt
	mv html $(DOC)/HTML
	mv latex $(DOC)/LaTeX

# ----------------------------------------------- #

clean:
	rm -rf $(DOC)/HTML $(DOC)/LaTeX $(OBJ)/*.o $(BIN)/*

