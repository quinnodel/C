/**
 * ------------------------------------------------
 * Author: Quinn Hiaasen
 * Date Created: Nov 17, 2023
 * ------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


bool isPrimeBF(int n) {
    bool isPrime = true;
    for (int j = n - 1; j > 1; j--) {
        if (n % j == 0) {
            isPrime = false;
        }
    }
    return isPrime;
}

void printNPrimes(int number) {
    int total_primes_found = 0;
    bool quota_met = false;
    int i = 2;

    while (!quota_met) {
        clock_t start, end;
        double time_elapsed;

        start = clock();
        bool is_prime = isPrimeBF(i);
        end = clock();

        time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

        if (is_prime) {
            total_primes_found++;
            printf("Prime: %d --- Time: %f sec --- Progress: %d/%d found\n", i, time_elapsed, total_primes_found, number);
        }

        if (total_primes_found == number) {
            quota_met = true;
        }

        i++;
    }
}

int main(int argc, char *argv[]) {
    if (atoi(argv[1]) != 0) {
        clock_t start, end;
        double total_time;
        int n = atoi(argv[1]);

        start = clock();
        printNPrimes(n);
        end = clock();

        total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("--- %d primes found in %f seconds. ---\n", n, total_time);
    } else {
        printf("Please enter an integer as argument.\n");
        printf("Syntax: ./primes <numberofprimes>\n");
    }

    return 0;
}
