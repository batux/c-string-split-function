#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split2(const char *str, const char *delim);

int main()
{
    char names[] = "ali,veli,selami,mustafa,batuhan,sevil";
    int i;
    char **ppstr;

    puts(names);

    if ((ppstr = split2(names, ",")) == NULL) 
    {
        fprintf(stderr, "cannot split!..\n");
        exit(EXIT_FAILURE);
    }

    puts(names);

    for (i = 0; ppstr[i] != NULL; ++i)
    {   
        puts(ppstr[i]);
    }

    for (i = 0; ppstr[i] != NULL; ++i)
    {
        free(ppstr[i]);
    }

    free(ppstr);

    return 0;
}

char **split2(const char *names, const char *delim)
{
    char *tmpVal;
    if( (tmpVal = (char *)malloc(strlen(names) + 1)) == NULL )
    {
        return NULL;
    }
    strcpy(tmpVal, names);

    char *str;
    str = strtok(tmpVal, delim);
    if(str == NULL)
    {
        return NULL;
    }

    int wordCount = 1;
    char **words;
    char **temp;
    
    if( (words = (char**) malloc((wordCount + 1) * sizeof(char*))) == NULL )
    {
        free(tmpVal);
        return NULL;
    }

    char *word;
    if( (word = (char*) malloc((strlen(str) + 1) * sizeof(char))) == NULL )
    {
        free(tmpVal);
        return NULL;
    }
    strcpy(word, str);
    words[0] = word;
    
    while( str != NULL )
    {
        str = strtok(NULL, delim);

        word = NULL;
        if(str != NULL)
        {
            if( (word = (char*) malloc((strlen(str) + 1) * sizeof(char))) == NULL )
            {
                free(tmpVal);
                free(words);
                return NULL;
            }
            strcpy(word, str);
            words[wordCount] = word;
        }
        words[wordCount] = word;

        wordCount++;
        if( (temp = (char**) realloc(words, (wordCount + 1) * sizeof(char*))) == NULL )
        {
            free(tmpVal);
            free(words);
            return NULL;
        }
        words = temp;
    }

    return words;
}