

//需要include vect_add_one 因為有call 到
#include "vect_add_one.h"
int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    //pass reference
    AddOneToEach(v);

    for (auto i: v) {
        total += i;
    }
    return total;
}
