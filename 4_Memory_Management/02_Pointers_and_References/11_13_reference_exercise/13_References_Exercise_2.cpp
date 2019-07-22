/*
LAB 2
Objectives 2
In this lab we are going to use declaration of references to reflect variable changes.
We are going to use two variables, of different data types for storage of data, and then
declare their references to track their changes. After that we are going compare it.

Steps 2
    Declare one integer and one double variable
    Declare two references of same type
    Use initial variables and assign them upon initialization to corresponding references
    Check references, write them out
    Change, modify variables
    Write references again
*/
#include <iostream>

using namespace std;

void pass_reference(int &input){
    cout << "input : " << input  << endl;
    cout << "input addr: " << &input  << endl;

}

void pass_pointer(int *input){
    cout << "input : " << input  << endl;
    //input 是 pointer, 本身是需要一個空間的, 有他自己的位置
    cout << "input addr: " << &input  << endl;
    cout << "*input : " << *input  << endl;

}

int main () {
   int    x=0;
   double y=0;

   int&    ref_x = x;
   double& ref_y = y;


   cout << "Value of x reference : " << ref_x  << endl;
   cout << "Value of y reference : " << ref_y  << endl;


   x = 5;
   y = 11.7;

   cout << "Value of x reference : " << ref_x  << endl;
   cout << "Value of y reference : " << ref_y  << endl;


   cout << "x : " << x  << endl;
   cout << "x addr: " << &x  << endl;

   pass_reference(x);
   pass_pointer(&x);

   return 0;
}
