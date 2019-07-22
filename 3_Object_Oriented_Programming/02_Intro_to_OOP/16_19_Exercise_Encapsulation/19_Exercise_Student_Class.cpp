// Example Solution for Student class
#include <iostream>

// creation of class Student
 class Student {

     // private attributes of class
     private:
         std::string name;
         int year;
         double gpa;

     public:     
         // public constructor for Student
         Student(std::string n, int y, double g){

             name = n;
             year = y;
             gpa = g;
         }

         // declare public getter functions

         // gets student name
         std::string GetName(){
             return name;
         }

         // get year of study
         int GetYear(){
             return year;
         }
         // get student's GPA
         int GetGPA(){
             return gpa;
         }

         // Declare public setter functions

         // sets student's name
         void SetName(std::string n){
             name = n;
         }
         // sets year of study
         void SetYear(int y){
             year = y;
         }
         // sets student's GPA
         void SetGPA(int g){
             gpa = g;
         }
 };

// main function
int main(){
    // Test instantiation and getters / setters
    Student student("Stephen", 4, 4.0);
    std::cout << student.GetName() << "\n";
   
}