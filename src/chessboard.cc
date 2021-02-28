#include<chessboard.hh>
ChessBoard::ChessBoard(WINDOW* win,int ht , int wd,int attr):w(win),chess_cell_sizey(ht),
                        chess_cell_sizex(wd),cell_attr(attr){
    //chess_cell_sizeuy=ht;
    //chess_cell_sizex=wd;   
    board_ht=chess_cell_sizey*8+2;
    board_wd=chess_cell_sizex*8+2;
    this->w=win;
    //bool is_white=true;
    print_chess_board();
    //lwr.print_piece(w,COLOR_PAIR(5),0,0,this->chess_cell_sizey,this->chess_cell_sizex,lwr.getrow());//WINDOW*,attr,cellindx_y,cell_indx_x 
}
void ChessBoard::print_chess_board(){
    bool startw_white=true;
    for(int i=1;i<=8;i++){//row
        for(int j=1;j<=4;j++){//coli
            if(startw_white)
                 print_chess_cell((i-1)*this->chess_cell_sizey+1,
                            (j-1)*(2*this->chess_cell_sizex)+1,this->cell_attr );
            else
                 print_chess_cell((i-1)*this->chess_cell_sizey+1,
                            (j-1)*(2*this->chess_cell_sizex)+1+this->chess_cell_sizex,this->cell_attr);
        }
        startw_white=!(startw_white);
    }
    return ;
}
void ChessBoard::print_chess_cell( int posy,
        int posx,int attr){
    wattr_on(w,attr,0);
           for(int j=0;j<this->chess_cell_sizey;j++){
                 mvwprintw(this->w,posy+j,posx,cellrow);
            }
    wattr_off(w,attr,0);
return ;
}


