CXX= g++
CXXFLAGS = -c  -Wall
SRC= ./src/
INCLUDE = ./include
chessboard.o: $(SRC)chessboard.cc $(SRC)ChessPeices.o
			$(CXX) $(CXXFLAGS) -o $(SRC)chessboard.o -I$(INCLUDE) $(SRC)ChessPeices.o $(SRC)chessboard.cc  -lncursesw 
ChessPeices.o: $(SRC)ChessPeices.cc
			$(CXX) $(CXXFLAGS) -o $(SRC)ChessPeices.o -I$(INCLUDE) $(SRC)ChessPeices.cc  -lncursesw 
main.o: $(SRC)main.cc $(SRC)chessboard.o
		$(CXX) -Wall -o main.o  -I$(INCLUDE) $(SRC)ChessPeices.o  $(SRC)chessboard.o $(SRC)main.cc -lncursesw
		
clean:
	rm $(SRC)chessboard.o $(SRC)ChessPeices.o


