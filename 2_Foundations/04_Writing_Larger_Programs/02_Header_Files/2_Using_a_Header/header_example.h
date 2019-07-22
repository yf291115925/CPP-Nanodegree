// The header file with just the function declarations.
// When you click the "Run Code" button, this file will
// be saved as header_example.h.


//include guard
#ifndef HEADER_EXAMPLE_H
#define HEADER_EXAMPLE_H

//don't need variable names, just variable types.
void OuterFunction(int);
void InnerFunction(int);

#endif


/*
NOTE:
The function declarations in the header file don't need variable names, just variable types.
You can put names in the declaration, however, and doing this often makes the code easier to read.
The #include statement for the header used quotes " " around the file name, and not angle brackets <>.
We have stored the header in the same directory as the .cpp file, and the quotes tell the preprocessor
to look for the file in the same directory as the current file - not in the usual set of directories where libraries are typically stored.

Finally, there is a preprocessor directive:
    #ifndef HEADER_EXAMPLE_H
    #define HEADER_EXAMPLE_H
at the top of the header, along with an #endif at the end. This is called an "include guard".
Since the header will be included into another file, and #include just pastes contents into a file,
the include guard prevents the same file from being pasted multiple times into another file.
This might happen if multiple files include the same header, and then are all included into the same main.cpp, for example.
The ifndef checks if HEADER_EXAMPLE_H has not been defined in the file already. If it has not been defined yet,
then it is defined with #define HEADER_EXAMPLE_H, and the rest of the header is used. If HEADER_EXAMPLE_H has already been defined,
then the preprocessor does not enter the ifndef block. Note: There are other ways to do this.
Another common way is to use an #pragma oncepreprocessor directive, but we won't cover that in detail here. See this Wikipedia article for examples.

*/
