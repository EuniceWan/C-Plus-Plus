#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
#include "hexapawn.h"

void hexapawn::new_chessboard() {
    for (int i=p.size()-1;i>=0;--i) {
        for (int j=0;j<p[i].size();++j) {
            char car='a';
            char car_2=car+j;
            p[i][j].u=car_2;
            p[i][j].v=i+1;
            if(i==p.size()-1) {
                p[i][j].which = 'B';
                p[i][j].chess=true;
            }
            if(i==0) {
                p[i][j].which = 'W';
                p[i][j].chess=true;
            }
        }
    }
}

void hexapawn::new_chess() {
    for(int j=0;j<n;++j){
        player_ch1[j].v=1;
        player_ch1[j].u=p[0][j].u;
        player_ch1[j].chess=true;
        player_ch2[j].v=m;
        player_ch2[j].u=p[0][j].u;
        player_ch2[j].chess=true;
    }
}

void hexapawn::play() {
    while(true) {
        draw_board();
        if (count % 2 == 1) {
            player1_move();
            player1_showselection();
            player1_domove();

        }
        else {
            player2_move();
            player2_showselection();
            player2_domove();

        }
    }
}

hexapawn::hexapawn(int & n_n, int & n_m) :temp_o_n(3*n_n),player_ch1(n_n),player_ch2(n_n),p(n_m,std::vector<hexapawn::For_showing>(n_n)){
    n=n_n;
    m=n_m;
    new_chessboard();
    new_chess();
}

void hexapawn::draw_board() {
    for (int i = 1; i <= m*2+3; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            char car = 'a';
            char car_2 = car + j - 2;
            if (i == 1 || i == m * 2 + 3) {
                if (j == 1)
                    std::cout << "   |";
                else if (j == n + 2)
                    std::cout << "   " << std::endl;
                else {
                    std::cout << " " << car_2 << " |";
                }
            } else {
                if (i % 2 == 0 && j != n + 2)
                    std::cout << "---+";
                else if (i % 2 == 0 && j == n + 2) {
                    std::cout << "---" << std::endl;
                }
                else if(j==1){
                    std::cout <<" "<< m-(i-3)/2<<" |";
                }
                else if (j==n+2){
                    std::cout <<" "<< m-(i-3)/2<<" "<<std::endl;
                }
                else{
                    int new_i=(2*m+3-i)/2-1;
                    int new_j=j-2;
                    if(p[new_i][new_j].chess){
                        std::cout<<" "<<p[new_i][new_j].which<<" |";
                    }
                    else std::cout << "   |";
                }
            }
        }
    }
}

void hexapawn::player1_move() {
    index = -1;
    std::cout << "player 1's move:" << std::endl;
    for (int k = 0; k < player_ch1.size(); ++k) {
        if (player_ch1[k].chess == true) {
            //convert posn
            int i = player_ch1[k].v - 1;
            int j = (int) player_ch1[k].u - 97;
            if (j - 1 >= 0 && p[i + 1][j - 1].which=='B') {
                index += 1;
                std::cout << index << ": " << p[i][j].u << p[i][j].v << "-" << p[i + 1][j - 1].u
                          << p[i + 1][j - 1].v << std::endl;
                temp_o_n[index]._ori.u = p[i][j].u;
                temp_o_n[index]._ori.v = p[i][j].v;
                temp_o_n[index]._new.u = p[i + 1][j - 1].u;
                temp_o_n[index]._new.v = p[i + 1][j - 1].v;
            }
            if (!p[i + 1][j].chess) {
                index += 1;
                std::cout << index << ": " << p[i][j].u << p[i][j].v << "-" << p[i + 1][j].u << p[i + 1][j].v
                          << std::endl;
                temp_o_n[index]._ori.u = p[i][j].u;
                temp_o_n[index]._ori.v = p[i][j].v;
                temp_o_n[index]._new.u = p[i + 1][j].u;
                temp_o_n[index]._new.v = p[i + 1][j].v;
            }
            if (j + 1 <= player_ch1.size() && p[i + 1][j + 1].which=='B') {
                index += 1;
                std::cout << index << ": " << p[i][j].u << p[i][j].v << "-" << p[i + 1][j + 1].u
                          << p[i + 1][j + 1].v << std::endl;
                temp_o_n[index]._ori.u = p[i][j].u;
                temp_o_n[index]._ori.v = p[i][j].v;
                temp_o_n[index]._new.u = p[i + 1][j + 1].u;
                temp_o_n[index]._new.v = p[i + 1][j + 1].v;
            }
        }
    }
    if (index == -1) {
        std::cout << "Player 2 win!" << std::endl;
        exit(0);
    }

}

void hexapawn::player1_showselection() {

    std::cin >> choose;
    while (choose < 0 || choose > index) {
        std::cout << "You choose wrong move, please choose the new move again" << std::endl;
        std::cin >> choose;
    }


}

void hexapawn::player1_domove() {
    int oi = temp_o_n[choose]._ori.v - 1;
    int oj = (int) temp_o_n[choose]._ori.u - 97;
    int ni = temp_o_n[choose]._new.v - 1;
    int nj = (int) temp_o_n[choose]._new.u - 97;

    // j doesn't change, go straight
    if (oj == nj) {
        for (int i = 0; i < player_ch1.size(); ++i) {
            if (player_ch1[i].u == temp_o_n[choose]._ori.u && player_ch1[i].v == temp_o_n[choose]._ori.v) {
                player_ch1[i].v += 1;
                if (player_ch1[i].v == m) {
                    std::cout << "Player 1 win!" << std::endl;
                    exit(0);
                }
                p[oi][oj].chess = false;
                p[oi][oj].which = 'S';
                p[ni][nj].chess = true;
                p[ni][nj].which = 'W';
            }
        }
    } else {
        for (int i = 0; i < player_ch1.size(); ++i) {
            if (player_ch1[i].u == temp_o_n[choose]._ori.u && player_ch1[i].v == temp_o_n[choose]._ori.v) {
                player_ch1[i].v = temp_o_n[choose]._new.v;
                player_ch1[i].u = temp_o_n[choose]._new.u;
                if (player_ch1[i].v == m) {
                    std::cout << "Player 1 win!" << std::endl;
                    exit(0);
                }
                p[oi][oj].chess = false;
                p[oi][oj].which = 'S';
                for(int j=0;j<player_ch2.size();++j){
                    if (player_ch2[j]                                                                                                                                                                                          .u == temp_o_n[choose]._new.u &&
                        player_ch2[j].v == temp_o_n[choose]._new.v) {
                        player_ch2[j].chess = false;
                    }
                }
                p[ni][nj].which = 'W';
            }
        }
    }
    count++;

}


void hexapawn::player2_move() {
    index = -1;
    std::cout << "player 2's move:"<< std::endl;
    for (int k = 0; k < player_ch2.size(); ++k) {
        if (player_ch2[k].chess == true) {
            int i = player_ch2[k].v - 1;
            int j = (int) player_ch2[k].u - 97;
            if (j - 1 >= 0 && p[i - 1][j - 1].which=='W') {
                index += 1;
                std::cout << index << ": " << p[i][j].u << p[i][j].v << "-" << p[i - 1][j - 1].u
                          << p[i - 1][j - 1].v << std::endl;
                temp_o_n[index]._ori.u = p[i][j].u;
                temp_o_n[index]._ori.v = p[i][j].v;
                temp_o_n[index]._new.u = p[i - 1][j - 1].u;
                temp_o_n[index]._new.v = p[i - 1][j - 1].v;
            }
            if (!p[i - 1][j].chess) {
                index += 1;
                std::cout << index << ": " << p[i][j].u << p[i][j].v << "-" << p[i - 1][j].u << p[i - 1][j].v
                          << std::endl;
                temp_o_n[index]._ori.u = p[i][j].u;
                temp_o_n[index]._ori.v = p[i][j].v;
                temp_o_n[index]._new.u = p[i - 1][j].u;
                temp_o_n[index]._new.v = p[i - 1][j].v;
            }
            if (j + 1 <= player_ch2.size() && p[i - 1][j + 1].which=='W') {
                index += 1;
                std::cout << index << ": " << p[i][j].u << p[i][j].v << "-" << p[i - 1][j + 1].u
                          << p[i - 1][j + 1].v << std::endl;
                temp_o_n[index]._ori.u = p[i][j].u;
                temp_o_n[index]._ori.v = p[i][j].v;
                temp_o_n[index]._new.u = p[i - 1][j + 1].u;
                temp_o_n[index]._new.v = p[i - 1][j + 1].v;
            }
        }
    }
    if (index == -1) {
        std::cout << "Player 1 win!" << std::endl;
        exit(0);
    }


}

void hexapawn::player2_showselection() {
    std::cin >> choose;
    while (choose < 0 || choose > index) {
        std::cout << "You choose wrong move, please choose the new move again" << std::endl;
        std::cin >> choose;
    }
}

void hexapawn::player2_domove() {
    int oi = temp_o_n[choose]._ori.v - 1;
    int oj = (int) temp_o_n[choose]._ori.u - 97;
    int ni = temp_o_n[choose]._new.v - 1;
    int nj = (int) temp_o_n[choose]._new.u - 97;
    if (oj == nj) {
        for (int i = 0; i < player_ch2.size(); ++i) {
            if (player_ch2[i].u == temp_o_n[choose]._ori.u && player_ch2[i].v == temp_o_n[choose]._ori.v) {
                player_ch2[i].v -= 1;
                if (player_ch2[i].v == 1) {
                    std::cout << "Player 2 win!" << std::endl;
                    exit(0);
                }
                p[oi][oj].chess = false;
                p[oi][oj].which = 'S';
                p[ni][nj].chess = true;
                p[ni][nj].which = 'B';
            }
        }
    } else {
        for (int i = 0; i < player_ch2.size(); ++i) {
            if (player_ch2[i].u == temp_o_n[choose]._ori.u && player_ch2[i].v == temp_o_n[choose]._ori.v) {
                player_ch2[i].v = temp_o_n[choose]._new.v;
                player_ch2[i].u = temp_o_n[choose]._new.u;
                if (player_ch2[i].v == 1) {
                    std::cout << "Player 2 win!" << std::endl;
                    exit(0);
                }
                p[oi][oj].chess = false;
                p[oi][oj].which = 'S';
                for(int j=0;j<player_ch1.size();++j){
                    if (player_ch1[j].u == temp_o_n[choose]._new.u &&
                        player_ch1[j].v == temp_o_n[choose]._new.v) {
                        player_ch1[j].chess = false;
                    }
                }
                p[ni][nj].which = 'B';
            }
        }
    }
    count++;
}










