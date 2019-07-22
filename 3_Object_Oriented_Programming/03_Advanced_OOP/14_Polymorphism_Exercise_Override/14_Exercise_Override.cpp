/*
單純的function operload, 跟以前沒啥不同

Using function overload you can achieve the same thing. Consider the following example:

OBJECTIVES
    Create class Point
    Create coordinates for the point x and y as two variables of type double and a constructor to initialise them.
    Use print() function to implement overload.
    Overload function with zero, one, and two parameters.
    Check that when you invoke p.print() without any parameters, the original function is called.
    After that you can invoke it with parameters and the overloaded function will be called instead

*/
// Example solution of function overload
// include iostream for printing
#include<iostream>
// Define Point class
class Point {
    // Declare private attributes x and y
    private:
        int x, y;
    // Define public constructor
    // Define operator overload
    // Define Print() function
    // Overload Print() function to take 1 or 2 input params
    public:
        Point(int xc = 0, int yc = 0) : x(xc), y(yc) {}

        Point operator + (Point const &obj) {
            Point res;
            res.x = Point::x + obj.x;
            res.y = Point::y + obj.y;
            return res;
        }

        // Print function
        void Print() {
            std::cout << "{ x: " << Point::x << ", y: " << Point::y << " }" << "\n";
        }
        // Overloaded function, they are same print function, but they’re overloaded with number // of input parameters
        void Print(int x) {
            std::cout << "{ x: " << x << ", y: " << Point::y << " }" << "\n";
        }
        void Print(int x, int y) {
            std::cout << "{ x: " << x << ", y: " << y << " }" << "\n";
        }
};
// Test in main()
int main() {
    Point p1(10, 5), p2(2, 4);
    Point p = p1 + p2; // An example call to "operator +"
    p.Print();
    p.Print(66);
    p.Print(66, 77);
    p.Print();
}
