#include "lexer.h"
int main()
{
    readFile("./files/hello_world.ccx");
    // readFile("./files/list.cci");
}

/* The fopen() function is currently failing. Visit the following website to read a full description of the 
fopen() function and possible reasons for fopen() failing. 
https://www.massey.ac.nz/~mjjohnso/notes/59102/docs/fopen.html#:~:text=ERRORS,the%20file%20to%20be%20created.*/

// Update: The seg fault had to do with file permissions