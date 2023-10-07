#include "lexer.h"



bool isKeyword(char* string)
{
/* strcmp() compares two strings and returns an integer value 0 (false) when the strings are equal, returns true otherwise.
strcmp() doesn't seek equality, it actually seeks a difference between the two strings it compares, so it returns true if there 
is a difference and false if there isn't a difference. This is why to test for equality we use !strcmp() rather than strcmp(). */

    if (!strcmp(string, "accessor") || !strcmp(string, "and") ||
        !strcmp(string, "array") || !strcmp(string, "begin") ||
        !strcmp(string, "bool") || !strcmp(string, "case") 
        || !strcmp(string, "character")|| !strcmp(string, "constant") 
        || !strcmp(string, "else")|| !strcmp(string, "elseif") 
        || !strcmp(string, "end") || !strcmp(string, "exit") 
        || !strcmp(string, "function") || !strcmp(string, "if") 
        || !strcmp(string, "in")|| !strcmp(string, "integer") 
        || !strcmp(string, "interface")|| !strcmp(string, "is") 
        || !strcmp(string, "loop") || !strcmp(string, "module")
        || !strcmp(string, "mutator") || !strcmp(string, "natural") 
        || !strcmp(string, "null") || !strcmp(string, "of")
        || !strcmp(string, "or") || !strcmp(string, "other")
        || !strcmp(string, "out") || !strcmp(string, "positive")
        || !strcmp(string, "procedure") || !strcmp(string, "range")
        || !strcmp(string, "return") || !strcmp(string, "struct")
        || !strcmp(string, "subtype") || !strcmp(string, "then")
        || !strcmp(string, "type") || !strcmp(string, "when")
        || !strcmp(string, "while")
    ){
        return (true);
    }
    else{
        return (false);
    }
}

void parse(char* line)
{
    char* token = strtok(line, " ");
    // int len = strlen(token);
    // int left = 0, right = token[len]-1;
    if(isKeyword(token) == true){
        printf("%s (keyword)\n", token);
    }
    token = strtok(NULL, " ");
    while(token != NULL){
        if(isKeyword(token) == true){
            printf("%s (keyword)\n", token);
        }
        token = strtok(NULL, " ");
    }

    return;
}

void readFile(char* file)
{
    FILE *fptr;
    char buffer[255];

    fptr = fopen(file, "r");

    while(fgets(buffer, 255, fptr) != NULL)
    {   
            parse(buffer);
    }

    fclose(fptr);
}
/*
accessor and array begin bool case character constant else elsif end exit function
if in integer interface is loop module mutator natural null of or other out
positive procedure range return struct subtype then type when while
*/