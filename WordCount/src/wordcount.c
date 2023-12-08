/* --------------------------
 * Author : Quinn Hiaasen
 --------------------------*/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

typedef struct
{
    int capacity;
    int size;
    char **words; // pointer to a pointer of chars, or string array
    int *frequency;
}Dict;

/*
 *
 */

void destroyDict(Dict *dict)
{
    for(int i = 0; i < dict->capacity; i++)
    {
        free(dict->words[i]);
    }
    free(dict->words);
    printf("Dict String Array Freed!\n");
    free(dict->frequency);
    printf("Dict Frequency Array Freed!\n");
    free(dict);
    printf("All Dict Memory Freed!\n");
    
}

/*
 *
 */

bool isInDict(Dict *dict, char *word)
{
    bool found = false;
    int i = 0; 
    for(int i = 0; i < dict->size; i++) 
    {
       if(strcmp(word,dict->words[i]) == 0)
       {
            found = true;
       }
       i++;
    }
    return found;
}

/*
 *
 */

int getIndex(Dict *dict, char *word)
{
    if(word != NULL)
    {
        for(int i = 0; i < dict->size; i++)
        {
            if(strcmp(word, dict->words[i]) == 0)
            {
                return i;   
            }
        }
    }
    else if (word == NULL)
    {
        printf("Cannot check a NULL word index!\n");
    }
    return -1;
}

Dict *resizeDict(Dict *dict)
{
    char **tempStringArr = realloc(dict->words, dict->capacity*2 * sizeof(char));
    if(tempStringArr == NULL)
    {
        printf("Resizing String Array Failed.\n");
        return NULL;
    }
    dict->words = tempStringArr;
    int *tempFreq = realloc(dict->frequency, dict->capacity*2 * sizeof(int));
    if(tempFreq == NULL)
    {
        printf("Resizing Frequency Array Failed.\n");
        return NULL;
    }
    dict->frequency = tempFreq;
    dict->capacity = dict->capacity*2;
    return dict;
}

/*
 *
 */

void addWord(Dict *dict, char *word)
{
    bool isIn = isInDict(dict,word);
    if(!isIn && dict->size <= dict->capacity)
    {
       dict->words[dict->size] = word;
       dict->frequency[dict->size]++;
       printf("%s added as new word.\n", word);
       dict->size++;
    }
    else if (isIn)
    {
        int index = getIndex(dict, word);
        dict->frequency[index]++;
        printf("%s incremented to %d.\n", word, dict->frequency[index]);
    }

}

void parseAndAdd(FILE *filePtr, Dict *dict)
{
   // do each word of a file at a time
   // split at whitespace 
    char buffer[1024];
    char *word;
    const char *delimiters = ",.;:\n\t ";

    while(fgets(buffer, sizeof(buffer), filePtr))
    {
        word = strtok(buffer, delimiters);
        while(word != NULL)
        {
            for(int i = 0; word[i] != '\0'; i++)
            {
                word[i] = tolower(word[i]);
            }
            
            // the way I did it before resulted in 

            char *newWord = malloc(strlen(word)+1);
            
            strcpy(newWord, word);

            addWord(dict,newWord);

            word = strtok(NULL,delimiters);
        }
    }
}

/*
 *
 */

void printDict(Dict *dict)
{
    for (int i = 0; i < dict->size; i++)
    {
        printf("Word: %s --- Frequency: %d\n", dict->words[i], dict->frequency[i]);
    }
}

/* 
 * Function - createEmptyDict()
 * returns a pointer to a Dict struct
 */

Dict *createEmptyDict(int capacity)
{
    Dict *dict = (Dict *)malloc(sizeof(Dict));
    char **stringArr = (char **)malloc(capacity * sizeof(char *));
    int *frequency  = (int *)malloc(capacity * sizeof(int));
    
    // check memory allocation
    if (stringArr == NULL)
    {
        free(stringArr);
        printf("String Array Failed to Allocate!\n");
        return NULL;
    }
    if (frequency == NULL)
    {
        free(frequency);
        printf("Frequency Array Failed to Allocate!\n");
        return NULL;
    }
    // full with default values 
    for (int i = 0; i < capacity ;i++)
    {
        stringArr[i] = (char*)malloc(sizeof(char));
        frequency[i] = 0;
        if(stringArr[i] == NULL)
        {
            free(stringArr[i]);
            printf("Failed to Allocate *Chars to Array");
            return NULL;
        }
    }
    
    dict->words = stringArr;
    dict->frequency = frequency;
    dict->size = 0;
    dict->capacity = capacity;
    return dict;
}    


int main(int argc, char *argv[])
{
    
    Dict *dict = createEmptyDict(100);
    FILE *fileptr = fopen(argv[1], "r");
    parseAndAdd(fileptr, dict);
    printDict(dict);
    destroyDict(dict);

    return 0;

}
