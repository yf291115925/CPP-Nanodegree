// Include iostream for printing
#include <iostream>
#include <cmath>

// Define class Sphere
class Sphere {
public:
    // Define public constructor
    Sphere(int radius)
    {
        if(radius >= 0) {
            radius_ = radius;
            volume_ = pi * 4 / 3 * pow(radius_, 3);
        }
    }
    
    // Define an accessor for the radius
    int radius() const { return radius_; }
    
    // Define an accessor for the volume
    double volume() const { return volume_; }
    
    constexpr double pi = 3.14159;

private:
    // Define private attributes
    int radius_ {0};
    double volume_ {0};
};
    
// Test in main()
int main(void)
{
    Sphere s(5);
    std::cout << s.radius() << "\n";
    std::cout << s.volume() << "\n";
}