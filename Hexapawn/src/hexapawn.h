 #pragma once

#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>

class hexapawn{


struct base{
    char u; //the character
    int v; //the native number
    bool chess=false; //if there is a chess here
};

struct Move{
    base _ori;
    base _new;
};

struct For_showing{
    char u; //the character
    int v; //the native number
    bool chess=false; //if there is a chess here
    char which='S'; //show it is Player1's chess or 2's
};

public:
    hexapawn(int&, int&);

    void play();

private:
    std::vector<std::vector<For_showing>> p;
    std::vector<Move> temp_o_n;
    std::vector<base> player_ch1;
    std::vector<base> player_ch2;
    int choose=-1;
    int count=1;
    int index=-1;
    int n;
    int m;

    void new_chessboard();

    void new_chess();

    void draw_board();

    void player1_move();

    void player2_move();

    void player1_showselection();
    
    void player1_domove();

    void player2_showselection();

    void player2_domove();

    friend class Testnew_chessboard;

    friend class Testplayer1_move;

    friend class Testdo_move;

    friend class Testdo_move2;

    friend class Testeat1;
};
