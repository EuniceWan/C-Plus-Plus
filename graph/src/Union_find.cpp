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

        else // if parent of x is samller than parent of y or smae,
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
