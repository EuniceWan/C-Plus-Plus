#pragma once

#include <cstddef>
#include <vector>

namespace ipd
{

// A union-find object representing disjoint sets of `size()` objects.
class Union_find
{


public:
    // Creates a new union-find of `n` objects.
    Union_find(size_t n);

    // Returns the number of objects in the union-find.
    size_t size() const;

    // Unions the sets specified by the two given objects.
    void do_union(size_t, size_t);

    // Finds the set representative for a given object.
    size_t find(size_t);

private:
    std::vector<size_t> parent_;
    std::vector<size_t> rank_;

    // initialize parent[] and rank[]
   // void makeSet(size_t);

};

}
