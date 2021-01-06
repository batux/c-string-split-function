/*
    Batuhan Düzgün - 03.01.2021
    Question-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *str, const char *delim);

int main(void)
{
    char names[] = "ali,veli,selami,batuhan,sevil";
    
    //For empty string test!
    //char names[] = "";

    //For invalid delimeter test!
    //char names[] = "ali-veli-selami-batuhan-sevil";

    char **ppstr;
    int i;

    /*
    //For NULL check test!
    if ((ppstr = split(NULL, ", ")) == NULL) 
    {
        fprintf(stderr, "cannot split!..\n");
        exit(EXIT_FAILURE);
    }
    */

    puts(names);

    if ((ppstr = split(names, ",")) == NULL) 
    {
        fprintf(stderr, "cannot split!..\n");
        exit(EXIT_FAILURE);
    }

    puts(names);
    
    for (i = 0; ppstr[i] != NULL; ++i)
    {
        puts(ppstr[i]);
    }

    free(ppstr);
    return 0;
}

char **split(char *str, const char *delim)
{
    char *tmpStr;
    tmpStr = strtok(str, delim);

    if(tmpStr == NULL)
    {
        return NULL;
    }

    int wordCount = 0;
    char **words;
    char **temp;
    
    if( (words = (char**) malloc((wordCount + 1) * sizeof(char*))) == NULL )
    {
        return NULL;
    }

    words[wordCount] = tmpStr;

    while( tmpStr != NULL )
    {
        tmpStr = strtok(NULL, delim);

        wordCount++;
        
        if( (temp = (char**) realloc(words, (wordCount + 1) * sizeof(char*))) == NULL )
        {
            free(words);
            return NULL;
        }
        
        words = temp;
        words[wordCount] = tmpStr;
    }

    return words;
}