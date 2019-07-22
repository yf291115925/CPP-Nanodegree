#include <iostream>
#include <cmath>
 // Partial example solution (no surface area or error checking)

class Pyramid {

    private:
        // private class attributes
        double base_length;
        double base_width;
        double height;

    public:
        // constructor for "Pyramid"
        Pyramid (double bl, double bw, double h){

            base_length = bl;
            base_width = bw;
            height = h;
        }

        // getter methods
        double getBaseLength(){
            return base_length;
        }
            // gets base width
        double getBaseWidth(){
            return base_width;
        }
          // gets base height
        double getHeight(){
            return height;
        }
        // public method that finds volume of pyramid
        double returnVolume(){
            // formula for calculating volume of pyramid
            return (base_length*base_width*height) / 3;
        }
};

int main(){
    Pyramid p(1, 1, 1);
    std::cout << p.returnVolume() << std::endl;
}