/*
Templates
With templates, the idea is to pass a data type as a parameter so that you don’t need
to write the same function code for operating on different data types.

=> Templates 的核心觀念是, 把data type 當成參數, 這樣你不需要針對不同data types 寫一樣的function 內容

For example, you might need a function that has to accept many different data
types in order for it to perform some operations or other actions on those data types.

舉例來說, 你需要一個function 可以接受不同的data type, 為了能對這些不同data type 表現出一些運算和動作


Some of these actions can be dividing, sorting, etc.

Rather than writing and
maintaining the multiple function declarations, each accepting slightly different arguments,
you can write one function and pass the argument types as parameters.

鄉對於你些一大堆針對稍微不同的input 參數, 都分別宣告各自function--> 先前的overloading
你可以寫一個function 且傳入很多種參數型別

At compile time, the compiler then expands the code using the types that are passed as parameters.

在 compile time 時, comiler 會只展開那些針對你傳入的資料型別的代碼


So if you write:

    template <typename Type>
      Type Sum(Type a, Type b) {
        return a+b;
    }

    int main() {
      std::cout << Sum<double>(20.0, 13.7) << std::endl;


The compiler adds the following internally:

double Sum(double a, double b) {
    return a+b;
}


Or in this case:

    std::cout << Sum<char> (‘Z’, ’j’) << std::endl;

The compiler adds:

    char Sum(char a, char b) {
        return a+b;
    }



=>上面展現了, compiler 會針對你的input, 只展開適合你的code


In this example, you’ll notice that we use the keyword template to specify which
function is generic.

Generic code is the term used for code that is independent to types.
=>所謂的Generic code , 是指這段code 跟 input types 獨立


It is mandatory to put the template<> tag just above your function to specify and mark
which implementation is generic.

主要就是把 template<> 放在你要做的function 上面

Besides template, you'll use the keyword typename, where you specify what mark is used to
indicate where the type is passed in a function prototype.

此外, 你要用一個 typename or class 去指定哪邊要傳入type 到你的func 中
ex: template <typename XXX> or template <class XXX>
=> typename 使用較多

後面的 XXX 可以隨便取, 它會對應到下面你實做code 裡面, 到時候就翻譯成這個 XXX

ex:
    template <typename XXX>
      XXX Sum(XXX a, XXX b) {
        return a+b;
    }

你在寫真的function 就要用 XXX 去寫, 呼叫時, 自然會指定XXX 是怎樣的type, code 就會展開了




In stead of typename, C++ also
supports the keyword class ( template <class T>), but using typename is preferred.
Like normal parameters, you can specify the default arguments to templates.

Have a look at the example below in the notebook demonstrating the use of templates.



*/
#include<iostream>
#include <typeinfo>

//template<class T, class U = int>
template<typename T, typename U = int>

class ClassA  {
    public:
        T x;
        U y;
        ClassA() {
            std::cout << "Constructor Called" << "\n";
            std::cout << "x type:"<< typeid(x).name() << std::endl;
            std::cout << "y type:"<< typeid(y).name() << std::endl;

        }
};

template <typename Type>
  Type Sum(Type a, Type b) {
    return a+b;
}

template <typename Type, typename T2>
  Type Sum2(Type a, T2 b) {
    return a+b;
}

int main()
{
    ClassA<char,char> aobject01;  // This will call A<char, char>
    /*
    Constructor Called
    x type:c
    y type:c
    */
    ClassA<char> aobject02;  // This will call A<char, int>
    /*
    Constructor Called
    x type:c
    y type:i
    */

    //testing
    std::cout << Sum<double>(20.0, 13.7) << std::endl;
    //前面不用加 double 也可以, 但因為sum 宣告都用T, 因此兩個數字需要同個type
    std::cout << Sum(20.0, 13.7) << std::endl;
    std::cout << Sum(20, 13) << std::endl;
    //呼叫 sum2 可接受兩種不同type 就可以了
    std::cout << Sum2(20.1, 13) << std::endl;


}
