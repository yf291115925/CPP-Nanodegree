/*
Object Files
So far in this course, we have refered to running g++ as "compiling".

However, g++ performs several distinct tasks:

    1.The preprocessor runs and executes any statement beginning with a hash symbol: #.
        This takes care of any #include statements, for example, so that all code is in place and ready to compile.
    2.Each file in the source code is compiled into an "object file" (a .o file). Object files are platform-specific machine code that will be used to create an executable.
    3.The object files are "linked" together to make a single executable. In the examples you have seen so far, this executable is a.out, but you can specify whatever name you want.

    It is possible to have g++ perform each of the steps separately by using the -c flag.

        g++ -c main.cpp

    will produce a main.o file, and that file can be converted to an executable with

        g++ main.o


Try these commands in the terminal below:

Save the file. The button will save the file as main.cpp
Compile to an object file using the -c flag. You can list the files in the directory with ls.
After compiling, you should see a main.o somewhere in the directory (along with all the notebook files).

Convert the file to an executable with g++.
Run the executable with ./a.out.

*/


#include <iostream>
using std::cout;

int main()
{
    cout << "Hello!" << "\n";
}


/*
Compiling One File of Many

In the example above, you compiled a single source code file to an object file. That object file was then converted into an executable.
If you wanted to do this with many source code files, and your directory only contained the files for your project, your bash commands might look like the following:

root@abc123defg:/home/workspace# g++ -c *.cpp
root@abc123defg:/home/workspace# g++ *.o
root@abc123defg:/home/workspace# ./a.out
Here, the * operator is a wildcard, so any matching file is selected.

But what if you make changes to the code? In that case, you can compile only that file, and use the existing object files from the other source
files for linking. For example, if you only changed file_3.cpp in your code, and all other object files were already created, you could run:

root@abc123defg:/home/workspace# g++ -c file_3.cpp
root@abc123defg:/home/workspace# g++ *.o
root@abc123defg:/home/workspace# ./a.out
As mentioned previously, this works great for small programs, where all the files are easy to find, and you can remember
which ones you have modified. For larger projects, it is helpful to use a build system which can compile the right files for you and take care of linking.

*/
