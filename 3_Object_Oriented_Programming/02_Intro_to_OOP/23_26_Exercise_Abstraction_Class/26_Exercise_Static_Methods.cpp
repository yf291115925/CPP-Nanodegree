#include <iostream>
#include <cmath>

class Sphere {
public:
    Sphere(int radius)
    {
        Update_(radius);
    }
    
    int radius() const { return radius_; }
    void radius(int length) { Update_(length); }
    
    double volume() const { return volume_; }

private:
    int radius_ {0};
    double volume_ {0};
    static constexpr double pi_ = 3.14159;
    
    void Update_(int radius)
    {
        if(radius >= 0) {
            radius_ = radius;
            volume_ = pi_ * 4 / 3 * pow(radius_, 3);
        }
    }
};
    
// Test in main()
int main(void)
{
    Sphere s(5);
    std::cout << s.radius() << "\n";
    std::cout << s.volume() << "\n";
    s.radius(3);
    std::cout << s.radius() << "\n";
    std::cout << s.volume() << "\n";
}