#ifndef CHESSBOARD_H
#define CHESSBOARD_H
//#include<ncursesw/ncurses.h>

#include<ChessPeices.hh>

class ChessBoard{
    private :
       const char* cellrow=         "      "; 
        WINDOW*w;
        int board_wd;
        int board_ht;
     //   chess_cell c;
      //  const int chess_cell_sizey;
      //  const int chess_cell_sizex;
        void print_chess_cell(int posy, int posx,int attr);  
        void print_chess_board( );
    public: 
       const int chess_cell_sizey=  3;
       const int chess_cell_sizex=  6;
        int cell_attr; //holds COLOR_PAIR(int) info for white chess cell 
        ChessBoard()=delete;
        ChessBoard& operator=(const ChessBoard &)=delete;
        ChessBoard(const ChessBoard &)=delete;
        ChessBoard(WINDOW * win, int cell_ht , int cell_wd,int attr);
                               
};

#endif
