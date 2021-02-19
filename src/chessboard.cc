#include<chessboard.hh>

ChessBoard::ChessBoard(WINDOW* win){
    this->w=win;
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    //bool is_white=true;

    print_chess_board(COLOR_PAIR(2));
}
void ChessBoard::print_chess_board(int  attr){
    bool startw_white=true;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=4;j++){
            print_chess_cell(attr,(i-1)*4+1,(j-1)*10+1,startw_white);
        }
        startw_white=!(startw_white);
    }
}
void ChessBoard::print_chess_cell( int  attr,int posy,
        int posx,const bool & is_white){
    const char * cellrow="     ";
    wattr_on(w,attr,0);
        if(is_white){
            for(int j=0;j<this->chess_cell_sizey;j++){
                mvwprintw(this->w,posy+j,posx,cellrow);
            }
        }
        else{
            for(int j=0;j<this->chess_cell_sizey;j++){
                mvwprintw(this->w,posy+j,posx+this->chess_cell_sizex,cellrow);
            }
        }
    wattr_off(w,attr,0);
return ;
}


