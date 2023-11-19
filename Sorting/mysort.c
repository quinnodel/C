/* -----------------------
Author - Quinn Hiaasen
Date Created - 11/19/2023
-------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printIntArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int* createRandArray(int size)
{
    srand(time(NULL));
    int* rand_array = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
       rand_array[i] = rand(); 
    }
    return rand_array;
}

int main (int argc, char* argv[])
{
    int size = atoi(argv[1]);
    int* rand_array = createRandArray(size);
    printIntArray(rand_array,size);
    free(rand_array);

    return 0;
}