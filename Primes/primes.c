/** -------------------------------
 * Author: Quinn Hiaasen
 * Date Created: Nov 17 2023
-----------------------------------*/


/**
 * --  NOTES --
 * to compile with GCC
 * gcc -o executable_name sourcefile.c
 * -Wall for ALL warnings and errors
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printIntArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
}

int* listprimes(int n)
{
    int* primelist = (int *)malloc(n * sizeof(int));              // cast type, n integers times the number 
    int totalprimes = 0;                                          // of bytes needed per integer
    bool primesFound = false;
    
    int i = 2;
    while(primesFound == false)
    {
        bool isPrime = true;
        
        for (int j = i-1; j>1;j--)                                // exclude edge cases for now
        {
            if (i%j ==0)                                          // if the original mod the new is 0
            {                                                     // then even division took place, and
                isPrime = false;                                  // the number is not prime
            }
        }
        
        if(isPrime)                                               // if the whole loop has finished without
        {                                                         // affecting the bool, its a prime
            primelist[totalprimes] = i;
            totalprimes++;
        }

        
        if(totalprimes == n)
        {
            primesFound = true;
        }

        i++;                                                      // we must increment I like a for-loop
    }
    
    return primelist;
}


int main(int argc, char* argv[])                                  // argc = number of arguments entered
{                                                                 // argv[] = index into each argument of string
    printf(" -- PRIME NUMBER FINDER -- \n");
    printf("How many primes to find? //: ");
    int n;
    scanf("%d",&n);
    int* primes = listprimes(n);
    printIntArray(primes,n);
    free(primes); 
    return 0;
}