#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMultiple(int multiple, int factor)
{
    bool isMultiple = false;
    if (multiple % factor == 0)
    {
        isMultiple = true;
    }
    return isMultiple;
}

int main(int argc, char *argv[])
{
    // every multiple of 3 is a fizz
    // every multiple of 5 is a buzz

    // when muplitple of 5 and 3 is fizzbuzz

    for (int i = 1; i <= 100; i++)
    {
        if (isMultiple(i, 3) && isMultiple(i, 5))
        {
            printf("FizzBuzz!\n");
        }
        else if (isMultiple(i, 3))
        {
            printf("Fizz\n");
        }
        else if (isMultiple(i, 5))
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }

    return 0;
}