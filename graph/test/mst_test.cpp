#include "mst.h"
#include "Union_find.h"
#include <UnitTest++/UnitTest++.h>

using namespace ipd;


TEST(mst_element)
{
    WU_graph wg(5);
    wg.add_edge(0,1,3);
    wg.add_edge(0,2,4);
    wg.add_edge(0,4,5);
    wg.add_edge(1,2,2);
    wg.add_edge(1,3,1);
    wg.add_edge(2,3,1);
    wg.add_edge(2,4,1);
    wg.add_edge(3,4,8);

    WU_graph k=kruskal(wg);

    CHECK_EQUAL(3,k.get_edge(0,1));
    CHECK_EQUAL(3,k.get_edge(1,0));
    CHECK_EQUAL(k.NO_EDGE,k.get_edge(0,4));
    CHECK_EQUAL(k.NO_EDGE,k.get_edge(3,4));
    CHECK_EQUAL(k.NO_EDGE,k.get_edge(1,2));
    CHECK_EQUAL(k.NO_EDGE,k.get_edge(0,2));
    CHECK_EQUAL(1,k.get_edge(1,3));
    CHECK_EQUAL(1,k.get_edge(2,3));
    CHECK_EQUAL(1,k.get_edge(2,4));


}

TEST(Kru) {
    WU_graph g(7);
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(1, 6, 14);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);

    WU_graph k = kruskal(g);


    CHECK_EQUAL(2, k.get_edge(3, 6));
    CHECK_EQUAL(2, k.get_edge(6, 3));
    CHECK_EQUAL(6, k.get_edge(4, 5));
    CHECK_EQUAL(6, k.get_edge(5, 4));
    CHECK_EQUAL(7, k.get_edge(1, 2));
    CHECK_EQUAL(7, k.get_edge(2, 1));
    CHECK_EQUAL(9, k.get_edge(5, 6));
    CHECK_EQUAL(9, k.get_edge(6, 5));
    CHECK_EQUAL(9, k.get_edge(1, 3));
    CHECK_EQUAL(9, k.get_edge(3, 1));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(1, 6));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(6, 1));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(2, 3));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(3, 2));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(2, 4));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(4, 2));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(3, 4));
    CHECK_EQUAL(k.NO_EDGE, k.get_edge(4, 3));
}
