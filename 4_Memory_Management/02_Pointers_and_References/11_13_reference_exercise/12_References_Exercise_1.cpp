/*
LAB 1
Objectives 1
In this lab we are going to introduce a concept of references. We are going to make a function which
will have simple task. To swap two variables. This task couldn't be fulfilled without references.

In this case, if we look closely we have two input parameters which needs to be modified as a result
of execution of this function. We are going to create a function which will have two generic input parameters,
used via template arguments. After that we are going to pass these paremeters via reference.
Because we are sending these values with their corresponding info about their place in memory,
we will directly affect these arguments from the function.

Steps 1
    Create function swap.
    Use template arguments, create generic type T which will be type of both input parameters
    Declare input parameters by reference
    Create function logic to swap two variable data
    Logic is going to swap variables without usage of the helper ( temp ) variable
    return type of function is void ( doesn't return value)
    Print out value of variables before and after function execution
    exit main function
*/


#include <iostream>
template<typename myType>
void swap(myType &var1, myType &var2){

    var1 +=var2;
    var2 = var1 - var2;
    var1 = var1 - var2;
}

int main() {

    float var1 = 23.2;
    float var2 = 14.83;

    std::cout << "Values before swap: " << var1 << " " << var2 << std::endl;
    swap(var1, var2);
    std::cout << "Values after swap: " << var1 <<  " " << var2 << std::endl;

    return 0;
}
