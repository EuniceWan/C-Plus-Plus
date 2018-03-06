#pragma once

#include "WU_graph.h"
#include "Union_find.h"

namespace ipd
{
    // compare weight of w1 and w2 and gives true or false, it will be used in the sort function in the kruskal function
    bool less(const WU_edge &, const WU_edge & );

    // Computes a minimum spanning forest by Kruskal's algorithm.
    WU_graph kruskal(const WU_graph&);




}
