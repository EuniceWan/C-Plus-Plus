#include "hexapawn.h"
#include <UnitTest++/UnitTest++.h>


TEST(new_chessboard)
{
    int a=3;
    int b=5;
    hexapawn h(a, b);
    CHECK_EQUAL('W',h.p[0][0].which);
    CHECK_EQUAL('W',h.p[0][1].which);
    CHECK_EQUAL('W',h.p[0][2].which);
    CHECK_EQUAL('S',h.p[1][0].which);
    CHECK_EQUAL('S',h.p[1][1].which);
    CHECK_EQUAL('S',h.p[1][2].which);
    CHECK_EQUAL('S',h.p[2][0].which);
    CHECK_EQUAL('S',h.p[2][1].which);
    CHECK_EQUAL('S',h.p[2][2].which);
    CHECK_EQUAL('S',h.p[3][0].which);
    CHECK_EQUAL('S',h.p[3][1].which);
    CHECK_EQUAL('S',h.p[3][2].which);
    CHECK_EQUAL('B',h.p[4][0].which);
    CHECK_EQUAL('B',h.p[4][1].which);
    CHECK_EQUAL('B',h.p[4][2].which);

    CHECK_EQUAL(a, h.player_ch1.size());
    CHECK_EQUAL(a, h.player_ch2.size());

    for (int i=0;i<h.player_ch1.size();++i) {
        CHECK_EQUAL(true, h.player_ch1[i].chess);
        CHECK_EQUAL(true, h.player_ch2[i].chess);
    }

    for (int j=0;j<a;++j){
        CHECK(h.player_ch1[j].u==h.p[0][j].u);
        CHECK(h.player_ch1[j].v==h.p[0][j].v);
    }
    for (int j=0;j<a;++j){
        CHECK(h.player_ch2[j].u==h.p[4][j].u);
        CHECK(h.player_ch2[j].v==h.p[4][j].v);
    }
}

TEST(player1_move){
    int a=3;
    int b=3;
    hexapawn h(a, b);
    CHECK_EQUAL(-1, h.index);

    h.player1_move();
    CHECK_EQUAL(2, h.index);
    CHECK_EQUAL(9, h.temp_o_n.size());
    CHECK_EQUAL('a', h.temp_o_n[0]._ori.u);
    CHECK_EQUAL(1, h.temp_o_n[0]._ori.v);
    CHECK_EQUAL('a', h.temp_o_n[0]._new.u);
    CHECK_EQUAL(2, h.temp_o_n[0]._new.v);

    CHECK_EQUAL('b', h.temp_o_n[1]._ori.u);
    CHECK_EQUAL(1, h.temp_o_n[1]._ori.v);
    CHECK_EQUAL('b', h.temp_o_n[1]._new.u);
    CHECK_EQUAL(2, h.temp_o_n[1]._new.v);

    CHECK_EQUAL('c', h.temp_o_n[2]._ori.u);
    CHECK_EQUAL(1, h.temp_o_n[2]._ori.v);
    CHECK_EQUAL('c', h.temp_o_n[2]._new.u);
    CHECK_EQUAL(2, h.temp_o_n[2]._new.v);

    h.player2_move();
    CHECK_EQUAL(2, h.index);
    CHECK_EQUAL(9, h.temp_o_n.size());
    CHECK_EQUAL('a', h.temp_o_n[0]._ori.u);
    CHECK_EQUAL(3, h.temp_o_n[0]._ori.v);
    CHECK_EQUAL('a', h.temp_o_n[0]._new.u);
    CHECK_EQUAL(2, h.temp_o_n[0]._new.v);

    CHECK_EQUAL('b', h.temp_o_n[1]._ori.u);
    CHECK_EQUAL(3, h.temp_o_n[1]._ori.v);
    CHECK_EQUAL('b', h.temp_o_n[1]._new.u);
    CHECK_EQUAL(2, h.temp_o_n[1]._new.v);

    CHECK_EQUAL('c', h.temp_o_n[2]._ori.u);
    CHECK_EQUAL(3, h.temp_o_n[2]._ori.v);
    CHECK_EQUAL('c', h.temp_o_n[2]._new.u);
    CHECK_EQUAL(2, h.temp_o_n[2]._new.v);
}

TEST(do_move) {
    int a=8;
    int b=6;
    hexapawn h(a, b);

    CHECK_EQUAL('h', h.player_ch1[7].u);
    CHECK_EQUAL(1, h.player_ch1[7].v);

    CHECK_EQUAL(true, h.p[0][7].chess);

    h.player1_move();
    h.choose=7;
    h.player1_domove();

    CHECK_EQUAL('h', h.player_ch1[7].u);
    CHECK_EQUAL(2, h.player_ch1[7].v);

    CHECK_EQUAL(false, h.p[0][7].chess);
    CHECK_EQUAL(true, h.p[1][7].chess);

}

TEST(do_move2)
{
    int a=8;
    int b=6;
    hexapawn h(a, b);

    CHECK_EQUAL('f', h.player_ch1[5].u);
    CHECK_EQUAL(1, h.player_ch1[5].v);

    CHECK_EQUAL(true, h.p[0][5].chess);

    h.player2_move();
    h.choose=5;
    h.player2_domove();

    CHECK_EQUAL('f', h.player_ch2[5].u);
    CHECK_EQUAL(5, h.player_ch2[5].v);

    CHECK_EQUAL(true, h.p[4][5].chess);
    CHECK_EQUAL(false, h.p[5][5].chess);
}

TEST(eat1){
    int a=3;
    int b=3;
    hexapawn h(a, b);
    h.player1_move();
    h.choose=0;
    h.player1_domove();

    CHECK_EQUAL('b', h.player_ch2[1].u);
    CHECK_EQUAL(3, h.player_ch2[1].v);
    CHECK_EQUAL(true, h.player_ch2[1].chess);

    CHECK_EQUAL('a', h.player_ch1[0].u);
    CHECK_EQUAL(2, h.player_ch1[0].v);
    CHECK_EQUAL(true, h.player_ch1[0].chess);

    CHECK_EQUAL(true, h.p[2][1].chess);
    CHECK_EQUAL('B', h.p[2][1].which);
    CHECK_EQUAL(true, h.p[1][0].chess);
    CHECK_EQUAL('W', h.p[1][0].which);

    h.player2_move();
    h.choose=0;
    h.player2_domove();

    CHECK_EQUAL('a', h.player_ch2[1].u);
    CHECK_EQUAL(2, h.player_ch2[1].v);
    CHECK_EQUAL(true, h.player_ch2[1].chess);

    CHECK_EQUAL('a', h.player_ch1[0].u);
    CHECK_EQUAL(2, h.player_ch1[0].v);
    CHECK_EQUAL(false, h.player_ch1[0].chess);

    CHECK_EQUAL(false, h.p[2][1].chess);
    CHECK_EQUAL('S', h.p[2][1].which);
    CHECK_EQUAL(true, h.p[1][0].chess);
    CHECK_EQUAL('B', h.p[1][0].which);

    CHECK_EQUAL('b', h.player_ch1[1].u);
    CHECK_EQUAL(1, h.player_ch1[1].v);

    CHECK_EQUAL(true, h.p[0][1].chess);
    CHECK_EQUAL('W', h.p[0][1].which);

    h.player1_move();
    h.choose=0;
    h.player1_domove();

    CHECK_EQUAL('a', h.player_ch1[1].u);
    CHECK_EQUAL(2, h.player_ch1[1].v);
    CHECK_EQUAL(false, h.player_ch2[1].chess);

    CHECK_EQUAL(false, h.p[0][1].chess);
    CHECK_EQUAL('S', h.p[0][1].which);
    CHECK_EQUAL(true, h.p[1][0].chess);
    CHECK_EQUAL('W', h.p[1][0].which);
}

