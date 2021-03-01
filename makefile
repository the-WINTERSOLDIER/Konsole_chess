

CXX= g++
CXXFLAGS = -c  -Wall
SRC= ./src/
INCLUDE = ./include
all: chessboard.o ChessPeices.o $(SRC)main.cc
		$(CXX) -Wall -o Konsole_chess.o   -I$(INCLUDE) $(SRC)ChessPeices.o  $(SRC)chessboard.o $(SRC)main.cc 	-lncursesw  	
chessboard.o: $(SRC)chessboard.cc 
			$(CXX) $(CXXFLAGS) -o $(SRC)chessboard.o -I$(INCLUDE)  $(SRC)chessboard.cc  -lncursesw 
ChessPeices.o: $(SRC)ChessPeices.cc
			$(CXX) $(CXXFLAGS) -o $(SRC)ChessPeices.o -I$(INCLUDE) $(SRC)ChessPeices.cc  -lncursesw 
clean:
	rm ./Konsole_chess.o $(SRC)chessboard.o $(SRC)ChessPeices.o





