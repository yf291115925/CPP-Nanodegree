/*

Exercise: Comparison Operator with template
This lab demonstrates how a simple comparison between two variables of unknown
type can work using templates.


In this case, by defining a template that performs
a comparison using the > operator, you can compare two variables of any type
(both variables must be of the same type, though)
as long as the operator > is defined for that type.

=> 雖然 運算子 > 可以利用 template 對付任何型別
但這個case 中左右兩邊仍然要同樣型別, 比竟是比大小


*/

#include <iostream>
#include <typeinfo>

// Here we will create the template
template <class T>
T ReturnMax(T a, T b)
{
   if(a > b)
       return a;
   else
       return b;
}

int main()
{
    int num1 = 50;
    int num2 = 10;

    // The ReturnMax will work for both int and double values

    // Return the larger of two integers
    // 這邊call function 時 也沒有指定 type, 直接丟進去
    int res = ReturnMax(num1, num2);
    std::cout << "Bigger one is: " << res << "\n";
    std::cout << "res type:"<< typeid(res).name() << std::endl;

    double n1 = 45.65;
    double n2 = 100.45;
    // Return the larger of two doubles
    double res2 = ReturnMax(n1, n2);

    std::cout << "Bigger one is: " << res2 << "\n";
    std::cout << "res2 type:"<< typeid(res2).name() << std::endl;

}
