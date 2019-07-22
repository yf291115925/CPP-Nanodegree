#include <iostream>
#include <string>
// Declaring function:
// Prototype of this function
// has input parameters of constant referenced pointer to
// char data type
// Note: Notice that function doesn't have any return values.

void addSpaces(const char * &str1) {
    std::cout<<"str1 addrs is: "<< &str1<<std::endl;

    // we are declaring new pointer for storage of new spaces (characters)
    char *temp = new char(sizeof(str1)*2);
    // Because we are going to move our input pointer
    // during our modification we need to remember our start address
    char *start = temp;
    // moving our pointer to the end of array of character
    while(*str1 != '\0'){
        // using pointer arithmetics
        // copying value of str1 to memory location where temp is pointing
        // after that we are moving through array with these two pointers
        *temp++ = *str1++;
        // after saving the string value to new allocated space
        // we are adding space character and moving
        // one more place to prepare our pointer to new string value
        *temp++ = ' ';
    }
    // resetting our original pointer to start address
    str1 = start;
}



int main() {
    std::string str = "Hello World";
    const char* ptr = str.c_str();
    std::cout<<"string is: "<<ptr<<std::endl;
    std::cout<<"string addrs is: "<< &ptr<<std::endl;

    addSpaces(ptr);
    // Our string has been modified without any return value
    // key difference was that we used reference to send our
    // array of characters to this function
    // in this way we are ensuring that all of our changes
    // are going to affect our sent data and not copy input
    // parameters of function
    std::cout<<"string is: "<<ptr<<std::endl;
    return 0;
    /* OUTPUT:
        string is: Hello World
        string is: H e l l o   W o r l d
    */
}
