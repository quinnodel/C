/** -------------------------------
 * Author: Quinn Hiaasen
 * Date Created: Nov 17 2023
-----------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void listPrimes(int n)
{
    int totalprimes = 0;                                                // of bytes needed per integer
    bool primesFound = false;

    int i = 2;
    while (primesFound == false)
    {
        clock_t start, end;
        double time_elapsed;

        start = clock();

        bool isPrime = true;
        for (int j = i - 1; j > 1; j--)                                 // exclude edge cases for now
        {
            if (i % j == 0)                                             // if the original mod the new is 0
            {                                                           // then even division took place, and
                isPrime = false;                                        // the number is not prime
            }
        }

        end = clock();

        time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

        if (isPrime)                                                    // if the whole loop has finished without
        {                                                               // affecting the bool, its a prime
            totalprimes++;
            printf("Prime: %d // Time: %f sec // Progress: %d/%d found\n", i, time_elapsed,totalprimes,n);
        }

        if (totalprimes == n)
        {
            primesFound = true;
        }

        i++;                                                            // we must increment I like a for-loop
    }
}

int main(int argc, char *argv[])                                        // argc = number of arguments entered
{                                                                       // argv[] = index into each argument of string
    if (argc == 2)
    {
        if(atoi(argv[1])!=0)
        {
            int n = atoi(argv[1]);
            listPrimes(n);
        }
        else
        {
            printf("Please enter an integer as argument.\n");
            printf("Syntax: ./primes <numberofprimes>\n");
        }
    }
    else
    {
        printf("Incorrect number of arguments.\n");
        printf("Syntax: ./primes <numberofprimes>\n");
    }
    return 0;
}
