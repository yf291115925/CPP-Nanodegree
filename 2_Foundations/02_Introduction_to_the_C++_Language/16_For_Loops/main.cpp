#include <iostream>
using std::cout;

int main() {
    /* For Loop with an Index Variable */
    for (int i=0; i < 5; i++) {
        cout << i << "\n";
    }


    /* The Increment Operator */
    auto i = 1;

    // Post-increment assigns i to c and then increments i.
    auto c = i++;

    cout << "Post-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";
    cout << "The value of i is: " << i << "\n";
    cout << "\n";

    // Reset i to 1.
    i = 1;

    // Pre-increment increments i, then assigns to c.
    c = ++i;

    cout << "Pre-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";
    cout << "The value of i is: " << i << "\n";
    cout << "\n";

    // Decrement i;
    i--;
    cout << "Decrement example:" << "\n";
    cout << "The value of i is: " << i << "\n";


    /* For Loop with a Container */
    // C++ offers several ways to iterate over containers. 
    // One way is to use an index-based loop as above. 
    // Another way is using a "range-based loop", which you will see frequently in the rest of this course.
    vector<int> a {1, 2, 3, 4, 5};
    for (int i: a) {
        cout << i << "\n";
    }
}
