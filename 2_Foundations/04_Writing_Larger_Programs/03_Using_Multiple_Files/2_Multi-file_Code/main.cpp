/*


Multi-file Code
In the next few cells these functions have been separated into several different files.


The structure of the included files is as follows:

    vect_add_one --> increment_and_sum -->main
*/


//vect_add_one 和 increment_and_sum 現在都拆去各自的.cpp .h 比較清楚
#include <iostream>
#include <vector>

//照上面的架構, main 要去call increment_and_sum(), 因此由main 來include
#include "increment_and_sum.h"


using std::vector;
using std::cout;

/*
IDEA:
    1. .h 就是負責pre-宣告的, 不用想太多, 就是把proto type 宣告在那邊, 有要call 這些function 的人自然要去include 這個.h
    2. .cpp 只是把sub-function 寫過去而已, 分成不同檔案比較清楚, 一樣, 這些cpp 有用到哪些fun 自己include 對應的.h
    3. compiler 讀了.h 中的 define 後就沒有error了, 它會去.cpp 裡面找真正的define 是因為build command 有 提供 xxx.cpp 它才知道要去裡面看,
        最後它才在increment_and_sum.cpp 找到當時你在 increment_and_sum.h 裡面定義的function 內容, 所以如果你最後沒有implement .h 中的function
        會有link error

    g++ -std=c++17 ./main.cpp ./increment_and_sum.cpp ./vect_add_one.cpp


    If you look carefully at the files above, you will see several things:

    a.vect_add_one.h is included in increment_and_sum.cpp.

        This is becuase AddOneToEach is used in IncrementAndComputeVectorSum.
        Including the vect_add_one.h header means that the AddOneToEach function declaration is pasted into  increment_and_sum.cpp,
        so no compiler error will occur when the AddOneToEach function is used.

    b.Only the header file needs to be included in another file.

        As long as the header file is included, the corresponding function declarations will be included. When the compiler finds an undefined function,
        it has already seen the function's declaration. This means the compiler can continue on without error until
        it finds the definition of the function, regardless of where that definition is.

    c.Some libraries, like <vector> are included in mutliple files.

        Each file is compiled alone and must have all the declarations and libraries necessary to compile,
        so the necessary libraries must be included. This is another reason why include guards are important -
        if multiple headers were included in main, each with the same #include <vector> statement,
        you wouldn't want the vector header pasted multiple times into the code.


*/


int main()
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}
