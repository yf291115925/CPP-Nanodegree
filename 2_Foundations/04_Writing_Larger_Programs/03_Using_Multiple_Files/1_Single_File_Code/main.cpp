/*
Single File Code
In the previous concept, you saw some example code that wouldn't compile because the functions were out of order:
*/


#include <iostream>
#include <vector>
using std::vector;
using std::cout;


int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    //pass reference
    AddOneToEach(v);
    
    for (auto i: v) {
        total += i;
    }
    return total;
}

void AddOneToEach(vector<int> &v) {
    for (auto& i: v) {
        i++;
    }
}

int main() {
    vector<int> v{1, 2, 3, 4};
    //call by value
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}

/*
In the last exercise of the notebook, you were to separate that code into a header .h file and a .cpp file. But what if
you wanted to use completely separate files for each of the functions?
For example, you might want to do this if the functions were going to belong to different classes or libraries.
*/
