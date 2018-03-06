# IPD 

## Summary

In this assignment we implement a ranked, path-compressing
union-find, and then we use it to implement Kruskal’s MST
algorithm.

## Goals

The goals of this assignment are to gain familiarity with union-find and
with graph algorithms, and to practice using and implementing ADTs as
classes.

## Specification

There are two parts to this assignment, union-find and MST.



## design

Union_find : In the private part of the class Union_find, 
		      we add 	std::vector<size_t> parent_, std::vector<size_t> rank_ in order to implement functions.
		      
		      The std::vector<size_t> parent_  presents each Union_find's parent(or ID)
		      The std::vector<size_t> rank_ present each Union_find's size
		      
		         

    Union_find(size_t n) : Creates a new union-find of `n` objects.

    size_t size() const : Returns the number of objects in the union-find.

    void do_union(size_t, size_t) :  Unions the sets specified by the two given objects.

    size_t find(size_t) : Finds the set representative for a given object.
    
    
    
mst : Kruskal's algorithm(Minimum Spanning Tree)
 - Given a graph, mst produce the minimum spanning tree of a graph(which is a new graph).
 - in order to implement the algorithm, we have to use Union_find function and WU_graph function.
 
 
 
 
< Explaining with examples >
 
 1. Union_find
 
 Union_find uf;  - it makes two vectors : parent, rank.
 
 With the two vectors, we tested Union_find, size(), do_union
 
 - check the size of an Union_find.
 TEST(5_element) 
{
    Union_find uf(5);
    CHECK_EQUAL(5,uf.size());
}


 - check the parent(ID) of an Union_find.
TEST(3_element)
{
    Union_find uf(3);
    uf.do_union(0,1);
    CHECK_EQUAL(1,uf.find(0));
}


 - check values of all parent of all elements in an Union_find.
 TEST(10_element)
{
    Union_find uf(10);

    uf.do_union(3,4);
    CHECK_EQUAL(4,uf.find(3));
    uf.do_union(4,9);
    CHECK_EQUAL(uf.find(4),uf.find(9));
    uf.do_union(8,0);
    CHECK_EQUAL(uf.find(0),uf.find(8));
    uf.do_union(2,3);
    CHECK_EQUAL(uf.find(3),uf.find(2));
    uf.do_union(5,6);
    CHECK_EQUAL(uf.find(6),uf.find(5));
    uf.do_union(5,9);
    CHECK_EQUAL(uf.find(5),uf.find(9));
    uf.do_union(7,3);
    CHECK_EQUAL(uf.find(3),uf.find(7));
    uf.do_union(4,8);
    CHECK_EQUAL(4,uf.find(8));
    uf.do_union(6,1);
    CHECK_EQUAL(4,uf.find(1));

}
 
 
 2. mst
 
 With a graph, we tested mst functions.

 - check all values of each edge's weight 
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

We checked all value of each edge's weight, the result showed that we had the mst of a graph.




< Code Explanation >

 
 1. Union_find.cpp
  
  #include "Union_find.h"

namespace ipd
{

    // Creates a new union-find of `n` objects.
    // strategy : decision tree, recursion
    size_t Union_find::find(size_t x)
    {
        if (x!=parent_[x]) // compare x and Parent_[x] and if they are not equal
            parent_[x]=find(parent_[x]); // find parent recursively
        return parent_[x];
    }

    // Unions the sets specified by the two given objects.
    // strategy : decision tree
    void Union_find::do_union(size_t x, size_t y)
    {
        size_t x1= find(x); // x1 is parent of x
        size_t x2= find(y); // x2 is parent of y
        if(x1==x2) // if they are same, they are in the same Union_find
            return;

        if(rank_[x1]>rank_[x2]) { // if parent of x is greater than parent of y
            parent_[x2] = x1; // y will be meged to x's Union_find
        }

        else // if parent of x is samller than parent of y or same,
        {
            parent_[x1]=x2; // x will be merged to y's Union_find

        }

        rank_[x1]=rank_[x1]+rank_[x2];
        rank_[x2]=rank_[x1]+rank_[x2]; // rank is increased
    }

    // Returns the number of objects in the union-find.
    // strategy : function composition
    size_t Union_find::size() const
    {
        return parent_.size();
    }

    // Creates a new union-find of `n` objects.
    // strategy : iteration
    Union_find::Union_find(size_t x)
    {
        for(size_t i=0; i<x;i++)
        {
            parent_.push_back(i); // make a vector of size_t i ex) [0, 1, 2, 3... x-1]
            rank_.push_back(1); // make a vector of 1 ex) [1, 1, 1, ......] n number 1
        }

    }

}



2. mst.cpp


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




<discovery>

1. Soonwon
 - C++ was very difficult, Xiaoyu helped me a lot.
 - I was very surprised when I understood how to use Union_find in order to implement the MST from a graph.
 - I thought there would be a lot of different ways to implement Union_find functions. I want to know them.

2. Xiaoyu
 - When I write the code of Union_find, I build a new function to initialize the parent_ and rank_. I confused why there is a Union_find::Union_find function. But then I knew I should initialize the parent_ and rank_ in this function.
 - This is my first time to use vector in C++, I find the vector is easy to use because it has some built-in functions, for example, sort, push.back… .
 




  
 




