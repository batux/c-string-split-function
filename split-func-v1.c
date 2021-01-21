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
    char *tmp_str;
    tmp_str = strtok(str, delim);

    if(tmp_str == NULL)
    {
        return NULL;
    }

    int word_count = 0;
    char **words;
    char **temp;
    
    if( (words = (char**) malloc((word_count + 1) * sizeof(char*))) == NULL )
    {
        return NULL;
    }

    words[word_count] = tmp_str;

    while( tmp_str != NULL )
    {
        tmp_str = strtok(NULL, delim);

        word_count++;
        
        if( (temp = (char**) realloc(words, (word_count + 1) * sizeof(char*))) == NULL )
        {
            free(words);
            return NULL;
        }
        
        words = temp;
        words[word_count] = tmp_str;
    }

    return words;
}