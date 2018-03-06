#include "mst.h"


namespace ipd
{
    // compare weight of w1 and w2 and gives true or false, it will be used in the sort function in the kruskal function
    // strategy : decision tree
    bool less(const WU_edge & w1, const WU_edge & w2) {
        return w1.w< w2.w;
    }

    // Computes a minimum spanning forest by Kruskal's algorithm.
    // strategy : iteration and decision tree
    WU_graph kruskal(const WU_graph& g){

        std::vector<WU_edge> result= get_all_edges(g);  // result is vector of <WU_edge> which has all edges of a graph
        Union_find abc(g.size()); // make g.size number of Union_finds
        WU_graph a(g.size()); // make a graph which has number of g.size vertices.

        sort(result.begin(),result.end(),less); // sort result with the less function

        size_t num_vertex=0; // num_vertex is 0

        for(size_t i=0;i<result.size();i++)
        {


            if(abc.find(result[i].u) != abc.find(result[i].v)) //if result[i].u and result[i].v don't belong to same tree
                                                                // which means that they are not in the same Union_find
            {

                abc.do_union(result[i].u,result[i].v); // do_union(result[i].u,result[i].v)

                a.add_edge(result[i].u,result[i].v,result[i].w); // add weight to the graph

                ++num_vertex; // increase 1 each iteration

                //mst should have v-1 edge
                //if edge >= v-1 ,break
                if(num_vertex >=g.size()-1)
                    break;
            }
        }

        return a; // return a new graph

    }
}
