// Partial example solution for Car class 
// getters and setters for brand only
#include <string>
#include <cstring>
#include <iostream>
// Define Car class
class Car {
    // Define private attributes
    private:
        int horse_power;
        int weight;
        char *brand;
    // Declare public getter and setter
    public:
        void SetBrand(std::string brand_name);
        std::string GetBrand() const;
};

// Define setter
void Car::SetBrand(std::string brand_name) {
    // Initialization of char array
    Car::brand = new char[brand_name.length() + 1];
    // copying every character from string to char array;
    strcpy(Car::brand, brand_name.c_str());
}

// Define getter
std::string Car::GetBrand() const {
    std::string result = "Brand name: ";
    // Specifying string for output of brand name
    result += Car::brand;
    return result;
};

// Test in main()
int main() {
    Car car;
    car.SetBrand("peugeot");
    std::cout << car.GetBrand() << "\n";
}