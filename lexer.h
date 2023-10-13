#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>
     #include <fcntl.h>

void readFile(char* file);
// bool startOfComment(char* s);
// bool midComment(char* s);
// bool endOfComment(char* s);
// bool isString(char* s);
// bool isCharacter(char s);
// bool isKeyword(char* s);
// bool isOperator(char ch);

void parseLine(char* line, FILE * outfile);
void parseString(char* s, FILE * outfile);

