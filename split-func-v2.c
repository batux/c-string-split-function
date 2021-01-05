#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split2(const char *str, const char *delim);

int main()
{
    char names[] = "ali,veli,selami,mustafa,batuhan,sevil";
    int i;
    char **ppstr;

    if ((ppstr = split2(names, ",")) == NULL) 
    {
        fprintf(stderr, "cannot split!..\n");
        exit(EXIT_FAILURE);
    }

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
    char *tmpVal = (char *)malloc(strlen(names) + 1);
    strcpy(tmpVal, names);

    char *str;
    str = strtok(tmpVal, delim);

    int wordCount = 1;
    char **words;
    words = (char**) malloc((wordCount + 1) * sizeof(char*));

    int strSize = strlen(str);  
    char *word = (char*) malloc((strSize + 1) * sizeof(char));
    strcpy(word, str);
    words[0] = word;
    
    while( str != NULL )
    {
        str = strtok(NULL, ",");

        word = NULL;
        if(str != NULL)
        {
            int strSize = strlen(str);         
            word = (char*) malloc((strSize + 1) * sizeof(char));
            strcpy(word, str);
            words[wordCount] = word;
        }
        words[wordCount] = word;

        wordCount++;
        words = (char**) realloc(words, (wordCount + 1) * sizeof(char*));
    }

    return words;
}