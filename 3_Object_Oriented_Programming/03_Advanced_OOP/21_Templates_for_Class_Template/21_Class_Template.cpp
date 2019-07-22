/*
Exercise: Class Template

=> Template  也可以用在 class 上

Classes are the basic building block of OOP in C++. Templates support the creation of generic classes.

Class templates can be used to declare and implement generic attributes
which will be used by generic methods. These templates can be very useful
when building classes that will serve multiple purposes.
可以讓一個class 有多種目標


OBJECTIVES
    Declare class
    Declare generic attributes
    Declare generic methods which are deduced to the same type
    Initialize the program
*/
#include <iostream>
#include <vector>

// generic class definition type T
template <class T>
class Container {
    std::vector<T> arr;
    int s;
    public:
        Container() : s(0){
            arr.clear();
        }

        int size(void) const{
            return Container::s;
        }


        void add(T el){
            Container::s++;
            arr.push_back(el);
        }
        void print(void)
        {
            for (T i : arr) {
                std::cout << i << " ";
            }
            std::cout << "\n" << "Container::size: " << Container::s << "\n";
        }
};


int main()
{
    Container<double> obj; // Partial deduction: element type is specified
    obj.add(2.00329132);
    obj.print();
    obj.add(8.83);
    obj.print();
    // TARGET OUTPUT:
    /*
        2.00329
        Size is:1
        2.00329 8.83
        Size is:2
    */


    //一個class 可以應付多種 data type
    Container<char> obj2; // Partial deduction: element type is specified
    obj2.add('A');
    obj2.print();
    obj2.add('b');
    obj2.print();
    /*

    A
    Container::size: 1
    A b
    Container::size: 2


    */


    return 0;
}
