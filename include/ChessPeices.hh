#ifndef CHESSPEICE_H
#define CHESSPEICE_H
#include<utility>
#include<ncursesw/ncurses.h>
class piece{  
    private:
        const int chess_peice_wd=4;
        const int chess_peice_ht=3;
        const int indx_y;//position relative to topleft corner of chess cell
        const int indx_x;
        int cell_indx_x;
        int cell_indx_y;
        //vector<pair<int , int > >marked_positions;//list of all the position that are under attack by this peice
        //▙▟▙▟ ▜▐▌▛  ▙➕▟  ▜▛  ▗▄▄▙   ▐▌
        //▐██▌ ▐▟▙▌  ▐▓▓▌  ██  ▝▘▓▞  ▐▓▓▌ 
        //▟██▙ ▟▓▓▙  ▟▓▓▙ ▟██▙ ▄▟▓▙  ▟▓▓▙
       // const char *king[3]=    {" ▙➕▟" , "▐▓▓▌", " ▟▓▓▙"};
       // const char *queen[3]=   {"▜▐▌▛","▐▟▙▌","▟▓▓▙"} ;
       // const char * bishop[3]= {" ▜▛ "," ██ ","▟██▙" };
       // const char * knight[3]= {"▗▄▄▙","▝▘▓▞","▄▟▓▙"};
       // const char * pawn[3]=   {" ▐▌ ","▐▓▓▌","▟▓▓▙"};
        void set_cell_indx(const int &y,const int &x);
    public:
        bool is_first_move;
        const bool is_white;//true: peice is white ; otherwise  its bleack
        virtual ~piece(); 
        piece(bool  piece_color,int y,int x);//y,x initial cell coordinate
        void get_cell_indx(int &y,int &x) const;
        virtual const char* const* getrow() const ;
        bool get_piece_color()const ;
        int move_to(const int &y,const int &x);//before moving a piece ensure
        void print_piece(WINDOW*w,int attr,int y,int x,int cell_ht,int cell_wd,const char *const pc[]);//WINDOW*,attr,cellindx_y,cell_indx_x
       
        /*
        bool is_valid_cell_indx();
        bool is_cell_empty();
        bool is_cell_occupied();//return false  if occupied by ally 
                                //return true if occupied by enemy
        */
};
class rook:public piece{
    private:
        const char *pc[3]=    {"▙▟▙▟" , "▐██▌","▟██▙"};
    public: 
       ~rook();
        rook(bool piece_color,int y,int x);
         const char* const* getrow()const;
};
class knight:public piece{
    private:
        const char *pc[3]=   {"▗▄▄▙","▝▘█▞","▄▟█▙"};
    public: 
        ~knight();
        knight(bool piece_color,int y,int x);
        const char * const * getrow()const;
};

class bishop :public piece{
    private:
         const char * pc[3]= {" ▜▛ "," ██ ","▟██▙" };
    public: 
        ~bishop();
        bishop(bool piece_color,int y,int x);
        const char * const * getrow()const;
};

class king :public piece{
    private:
        const char *pc[3]=    {"▙➕▟" , "▐██▌", "▟██▙"};
    public: 
        ~king();
        king(bool piece_color,int y,int x);
        const char * const * getrow()const;
};


class queen :public piece{
    private:
         const char *pc[3]=   {"▜▐▌▛","▐▟▙▌","▟██▙"} ;
    public: 
        ~queen();
        queen(bool piece_color,int y,int x);
        const char * const * getrow()const;
};


class  pawn:public piece{
    private:
         const char * pc[3]=   {" ▐▌ ","▐██▌","▟██▙"};
    public: 
        ~pawn();
        pawn(bool piece_color,int y,int x);
        const char * const * getrow()const;
};
#endif
