#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include<ncurses.h>
class ChessBoard{
    private :
        WINDOW*w;
        const int board_wd=34;
        const int board_ht=42;
        const int chess_cell_sizey=4;
        const int chess_cell_sizex=5;
        void print_chess_cell(int attr,int posy,
                 int posx,const bool &is_white);
        void print_chess_board( int attr);
    public: 
        ChessBoard()=delete;
        ChessBoard& operator=(const ChessBoard &)=delete;
        ChessBoard(const ChessBoard &)=delete;
        ChessBoard(WINDOW * win);
};

#endif
