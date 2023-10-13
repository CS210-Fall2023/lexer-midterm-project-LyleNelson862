#include "lexer.h"

// bool startOfComment(char s)
// {
//     if(s == '/')
//         return true;
//     else
//         return false;
// }

// bool midComment(char* s)
// {
//     if(s[1] == '*' && s[2] != '/')
//         return true;
//     else
//         return false;
// }
// bool endOfComment(char* s)
// {
//     if(s[1] == '*' && s[2] == '/')
//         return true;
//     else
//         return false;
// }

// bool isString(char* s)
// {
//     if(s[0] == '"'){
//         return true;
//     }else{
//         return false;
//     }
// }

// bool isCharacter(char s)
// {
//     /* By preceding the quotation mark with \, I've created an escape sequence which will insert
//      a single quote in the char without ending the actual char.*/
//     if(s == '\''){
//         return true;
//     }else{
//         return false;
//     }
// }

bool isKeyword(char* s)
{
/* strcmp() compares two strings and returns an integer value 0 (false) when the strings are equal, returns 
true otherwise. strcmp() doesn't seek equality, it actually seeks a difference between the two strings it compares, 
so it returns true if there is a difference and false if there isn't a difference. This is why to test for equality 
we use !strcmp() rather than strcmp().We need strcmp() because comparing strings with the == operator would 
give a comparison of their object references rather than their literal values. */

    if (!strcmp(s, "accessor") || !strcmp(s, "and") ||
        !strcmp(s, "array") || !strcmp(s, "begin") ||
        !strcmp(s, "bool") || !strcmp(s, "case") 
        || !strcmp(s, "character")|| !strcmp(s, "constant") 
        || !strcmp(s, "else")|| !strcmp(s, "elseif") 
        || !strcmp(s, "end") || !strcmp(s, "exit") 
        || !strcmp(s, "function") || !strcmp(s, "if") 
        || !strcmp(s, "in")|| !strcmp(s, "integer") 
        || !strcmp(s, "interface")|| !strcmp(s, "is") 
        || !strcmp(s, "loop") || !strcmp(s, "module")
        || !strcmp(s, "mutator") || !strcmp(s, "natural") 
        || !strcmp(s, "null") || !strcmp(s, "of")
        || !strcmp(s, "or") || !strcmp(s, "other")
        || !strcmp(s, "out") || !strcmp(s, "positive")
        || !strcmp(s, "procedure") || !strcmp(s, "range")
        || !strcmp(s, "return") || !strcmp(s, "struct")
        || !strcmp(s, "subtype") || !strcmp(s, "then")
        || !strcmp(s, "type") || !strcmp(s, "when")
        || !strcmp(s, "while")
    ){
        return true;
    }
    else{
        return false;
    }
}

/* List of keywords:
accessor and array begin bool case character constant else elsif end exit function
if in integer interface is loop module mutator natural null of or other out
positive procedure range return struct subtype then type when while
*/

bool isOperator(char ch)
{
    if (ch == '.' || ch == '<' || ch == '>' || ch == '(' || ch == ')' 
    || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '|' 
    || ch == '&' || ch == ';' || ch == ',' 
    // || ch == ':'
    || ch == '[' || ch == ']' || ch == '='
    //  || ch == ':=' || ch == '..' || ch == '<<' || ch = '>>' || ch == '<>' || 
    // ch == '<=' || ch == '>=' || ch == '**' || ch == '!= ' || ch == '=>'
    ){
        return true;
    }
    else{
        return false;
    }
}
/* Operators: “.”   “<”   “>”   “(“   “)”  “+”   “-“   “*”   
“/”   “|”   “&”   “;”   “,”   “:” “[“   “]”  “=”   “:=”   “..”  
“<<”   “>>”   “<>”   “<=”   “>=”   “**”   “!=”   “=>”*/
 

 /* I'm trying to make parseString() a function that searches through a token originally ending with " ", and if 
 it finds an operator at some point in the token, then it makes the operator become the end of the token.Afterwards, 
 it should print the newly-cut token and its classification, followed by the operator and its classification.
 */

// void parseString(char* s)
// {
    // for(int i = 0; i < strlen(s); i++)
    // {

    // }
// }

void parseLine(char* line, FILE* outfile)
{
    static int inComment=0;
    int i = 0;
    int start, end;
    int size = strlen(line);
    char* str;

    while(i < size)
    {
        if(line[i]=='/')
        {
            putc(line[i],outfile);
            // fflush(outfile);
            i++;
            if(i < size && line[i] == '*')
            {
                inComment =1;
                putc(line[i],outfile); 
                // fflush(outfile);
                i++;

                while(1)
                {
                    //find end of comment
                    while(i < size && line[i] != '*'){
                        putc(line[i],outfile);
                        // fflush(outfile);
                        i++; 
                    }
                    if(i>=size){
                        return; // This will force the read() function to move on to the next line
                    }
                    // after finding star, display and check if next char is /
                    putc(line[i],outfile);
                    // fflush(outfile);
                    i++;
                    if(i < size && line[i] == '/'){
                        putc(line[i],outfile);
                        inComment =0;
                        fprintf(outfile, " (comment)\n");
                        // fflush(outfile);
                        return;
                    }
                }                       
            } else{//no *, so I have operator
                 if (i>=size){
                        return;
                    }
                fprintf(outfile, " (operator)\n");//later change print to filre
                // fflush(outfile);
            }
        }
        // else if(isalpha(line[i]))
        // {
        //     str = "";
        //     while (isalpha(line[i])){
        //         strncat(str, &line[i], 1);
        //         i++;
        //     }

        //     // str = strncpy(line[i], line+start, end-start);
        //     // int j = end-start;
        //     // line[j] = NULL;
        //     if(isKeyword(str) == true){
        //         fprintf(outfile, " (keyword)\n");
        //     }          
        //     else{
        //         fprintf(outfile, " (identifier)\n");
        //     }
        // }

    //    else if(isString(line[i]) == true){
    //         printf("%s (string)\n", token);
    //     }
        /*
        else if(isCharacter(line[i]) == true){
            printf("%s (character literal)\n", token);
        }
        else if(isalpha(line[i]))
        {
            start = i;
            i++;
            while (isalpha(line[i])){
                i++;
            }
            end = i;
            strncpy(token, line+start, end-start);
            int j = end-start;
            token[j] = NULL;
            if(isKeyword(token) == true){
                printf("%s (keyword)\n", token);
            }          
            else{
                printf("%s (identifier)\n", token);
            }
        }*/
        else if(isspace(line[i])){
            if(i>=size){
                return;
            }
            fprintf(outfile, "UNK\n");
            // fflush(outfile);
            while(isspace(line[i])){
                i++;
            }          
        }
        else{
            if(i>=size){
                return;
            }
            fprintf(outfile, "UNK1\n");
            // fflush(outfile);
        }
    }
}

void readFile(char* file)
{
    // FILE *fptr;
    int fvar;
    FILE *outfile;
    outfile = fopen("output.txt", "w");
    char buffer[1000];

    fvar = open(file, O_RDONLY);
    // fptr = open(file, 'r');

    /* This was a while loop previously and it was throwing an infinity loop. Eventually I figured out that I can 
     fix this by changing the while to an if.*/
    if(read(fvar,buffer, 1000) != EOF)
    {   
        printf("Call parseLine\n"); 
        // fflush(stdout);   
        parseLine(buffer, outfile);       
    }
    // fclose(fvar);
}

/* More about the difference between read() and fgets():
https://stackoverflow.com/questions/6220093/difference-between-read-and-fgets-in-c
https://stackoverflow.com/questions/5436193/read-up-to-a-null-terminator-using-read
*/
