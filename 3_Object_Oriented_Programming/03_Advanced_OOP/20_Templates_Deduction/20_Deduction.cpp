/*
Exercise: Deduction
=> 有點抓不到重點, 有點像是, template func 可以收很多沒指定type 的 input, 它會自己推論出適合的

In this example, you will see the difference between total and partial deduction.

=> Total 和 partial deduction 是不同的

Deduction occurs when you instantiate an object without explicitly identifying the types.

=> Deduction 發生在你宣告一個object 時沒有給出明確的type


Instead, the compiler "deduces" the types.
相對的, 由compiler 推論出 types


This can be helpful for writing code that is
generic and can handle a variety of inputs.

這樣可以幫助你寫更多generic 的 code




OBJECTIVES
Declare a generic conditional function
Use it in conditional sorting
Declare another function which is used for processing generic types (this case is print())


*/


#include <iostream>
#include <algorithm>
#include <vector>

// template function comparison of two numbers
template <typename T>
bool func(T x, T y)
{
    return (x < y);
}

// template for printing
template <typename T>
void print(std::vector<T> v)
{
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

//main function
int main()
{
std::vector<double> v = {9,3,2,32.32,10.323,10.0003,4.9789};
std::vector<char> v2 = {'a','Z','M','x','Y','c','U'};

print(v);
// Deducing function return type
// 利用 Deducing 的功能, func 可以值耶收 v, 去做 v item 的比較
std::sort(v.begin(), v.end(), func<double>);
print(v);


// For input parameters as PrintVector we have total deduction,without specification
// 對於print 來說, 也是 deducing 了, print(v2) 中沒有給出type, print 自己推論出合適的型別
print(v2);
// this will support any type of that which has defined support for (in this case) < operator
std::sort(v2.begin(), v2.end(), func<char>);
print(v2);
}
