/*

Vector push_back

Now that you are able to process a string, you may want to store the results of the processing in a convenient container for later use.
In the next exercise, you will store the streamed ints from each line of the board in a vector<int>.
To do this, you will add the ints to the back of the vector, using he vector method push_back:
*/


#include <vector>
#include <iostream>
using std::vector;
using std::cout;


/////////////////////
// push_back(data)
/////////////////////
int main() {
    // Initial Vector
    //vector<int> v {1, 2, 3};
    vector v {1, 2, 3}; //works only on c++17 without vector type

    // Print the contents of the vector
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }

    // Push 4 to the back of the vector
    v.push_back(4);

    // Print the contents again
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }

}
