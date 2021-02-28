#include<chessboard.hh>
#include<utility>
#include<vector>
#include<locale>
 int main(){
    setlocale(LC_ALL,"");//eneble unicode support 
    initscr();
    start_color();
    WINDOW*win=newwin(26,50,3,3); //height,width,(topleft coordinate of window)
    box(win,0,0);    
    ChessBoard c(win,3,6,COLOR_PAIR(1)); //pointer to win ,chess_cell_ht,chess_cell_wd
    //---------------INITIALISING CHESS PIECES________________________
    init_pair(1,COLOR_BLACK,COLOR_WHITE);//colour for white cell                                       
    init_pair(2,COLOR_RED,COLOR_BLACK);//white piece in black cell              
    init_pair(3,COLOR_RED,COLOR_WHITE); //white piece in white cell             
    init_pair(4,COLOR_BLUE,COLOR_BLACK);//black piece in black cell             
    init_pair(5,COLOR_BLUE,COLOR_WHITE); //black piece in white cell

    knight LN(true,1,0),RN(true,6,0),ln(false,1,7),rn(false,6,7);//params:is_white,ycellindex ,xcellindex
    rook  LR(true,0,0),RR(true,7,0),lr(false,0,7),rr(false,7,7);
    bishop LB(true,2,0),RB(true,5,0),lb(false,2,7),rb(false,5,7);
    pawn *P[8],*p[8];
    king K(true,3,0),k(false,4,7);
    queen Q(true,4,0),q(false,3,7);
    //____________________init_chess_grid_____________________________________________
    std::pair<char,piece*>empty_cell=std::make_pair(' ',nullptr);
    std::vector<std::vector< std::pair<char , piece*> > >chess_grid(8,std::vector<std::pair<char,piece*>>(8,empty_cell));
    chess_grid[0][1]=std::make_pair('N',&LN);chess_grid[0][6]=std::make_pair('N',&RN);
    chess_grid[7][1]=std::make_pair('n',&ln);chess_grid[7][6]=std::make_pair('n',&rn);
    
    chess_grid[0][0]=std::make_pair('R',&LR);chess_grid[0][7]=std::make_pair('R',&RR);
    chess_grid[7][0]=std::make_pair('r',&lr);chess_grid[7][7]=std::make_pair('r',&rr);
    
    
    chess_grid[0][2]=std::make_pair('B',&LB);chess_grid[0][5]=std::make_pair('B',&RB);
    chess_grid[7][2]=std::make_pair('b',&lb);chess_grid[7][5]=std::make_pair('b',&rb);

    chess_grid[0][3]=std::make_pair('K',&K);chess_grid[7][4]=std::make_pair('k',&k);
    chess_grid[0][4]=std::make_pair('Q',&Q);chess_grid[7][3]=std::make_pair('q',&q);

    for(int i=0;i<=7;i++){
        P[i]=new pawn(true,i,1);
        p[i]=new pawn(false,i,6);
        chess_grid[1][i]=std::make_pair('P',P[i]);
        chess_grid[6][i]=std::make_pair('p',p[i]);
    }
//-------------------------------------------------------------------------------
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                int attr=0;
                if(chess_grid[i][j].second!=nullptr){
                    if((chess_grid[i][j].second)->is_white){
                        attr=((i+j)%2==0?COLOR_PAIR(3):COLOR_PAIR(2));
                    }
                    else{
                         attr=((i+j)%2==0?COLOR_PAIR(5):COLOR_PAIR(4));

                    }
                    (chess_grid[i][j].second)->print_piece(win,attr,i,j,c.chess_cell_sizey,
                                                c.chess_cell_sizex,(chess_grid[i][j].second)->getrow());
                }
            }
        }
    refresh();
    wgetch(win);
    endwin();
return 0;
}
