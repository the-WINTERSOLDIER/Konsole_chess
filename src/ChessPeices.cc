/*class  piece{
    private:
        const int chess_piece_wd=4;
        const int chess_piece_ht=3;
        const int indx_y;//position relative to topleft corner of chess cell
        const int indx_x;
        int cell_indx_x;
        int cell_indx_y;
        //▙▟▙▟ ▜▐▌▛  ▙➕▟  ▜▛  ▗▄▄▙   ┳i
        //▐██▌ ▐▟▙▌  ▐▓▓▌  ██  ▝▘▓▞  ▐▓▌ 
        //▟██▙ ▟▓▓▙  ▟▓▓▙ ▟██▙ ▄▟▓▙ ▟▓▓▓▙
        const char *rook[3]={"▙▟▙▟" , "▐██▌"," ▟██▙"};
        const char *king[3]={};
    const char *queen[3]={};
        const char * bishop[3]={};
        virtual void set_cell_indx();
    public:
        piece():indx_x(1),indx_y(1){}
        virtual void get_cell_indx();
        virtual const char** getrow();
        int move_to(const int &y,const int &x);
        bool is_valid_cell_indx();
        bool is_cell_empty();
        bool is_cell_occupied();//return true iof occupied by ally 
                                //return false if occupied by enemy

};*/
#include<ChessPeices.hh>
piece::piece(bool piece_color,int y,int x):indx_y(0),indx_x(1),cell_indx_x(x),cell_indx_y(y),is_first_move(false),is_white(piece_color){

}
void piece::set_cell_indx(const int & y, const int &x){
    this->cell_indx_y=y;
    this->cell_indx_x=x;
    return;
}
void piece::get_cell_indx(int &y ,int &x)const {
    y=this->cell_indx_y;
    x=this->cell_indx_x;
    return;
}
bool piece::get_piece_color()const {return this->is_white;}
int move_to(const int &y,const int &x){
//check if the destination position is one of all
//possible position of the piece's
return 0;
}
void piece::print_piece(WINDOW*w,int attr,int y,int x,int cell_ht,int cell_wd,const char *const pc[]){
   wattr_on(w,attr,0);
    for(int i=0;i<this->chess_peice_ht;i++){
     //   std::cout<<std::endl<<y*cell_ht+i+this->indx_y+1<<" "<<x*cell_wd+this->indx_x+1;
            mvwprintw(w,y*cell_ht+i+this->indx_y+1,
                        x*cell_wd+this->indx_x+1,pc[i]);
    }
    wattr_off(w,attr,0);
}
piece:: ~piece(){}
rook :: ~rook(){}
rook :: rook (bool piece_color,int y,int x):piece(piece_color,y,x){}
const char *const* rook::getrow() const{ return this->pc;}
const char*const * piece::getrow()const {return nullptr;} 


knight :: knight (bool piece_color,int y,int x):piece(piece_color,y,x){}
const char *const* knight::getrow() const{ return this->pc;}
knight:: ~knight(){}

bishop :: bishop (bool piece_color,int y,int x):piece(piece_color,y,x){}
const char *const* bishop::getrow() const{ return this->pc;}
bishop ::~bishop(){}

king :: king (bool piece_color,int y,int x):piece(piece_color,y,x){}
const char *const* king::getrow() const{ return this->pc;}
king:: ~king(){}

queen :: queen (bool piece_color,int y,int x):piece(piece_color,y,x){}
const char *const* queen::getrow() const{ return this->pc;}
queen:: ~queen(){}

pawn :: pawn (bool piece_color,int y,int x):piece(piece_color,y,x){}
const char *const* pawn::getrow() const{ return this->pc;}
pawn:: ~pawn(){}



