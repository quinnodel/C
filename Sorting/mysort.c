/* -----------------------
Author - Quinn Hiaasen
Date Created - 11/19/2023
-------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int *mySort(int *rand_arr) {
    // Sorting logic here
}

void printIntArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

int *createRandArray(int size) {
    srand(time(NULL)); // sets the random seed
    int *rand_array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        rand_array[i] = rand();
    }
    return rand_array;
}

/*
--- NOTES ---
- Implement error handing for arguments.
- implement sorting algorithm
*/

int main(int argc, char *argv[]) {
    int size = atoi(argv[1]);
    int *rand_array = createRandArray(size);
    printIntArray(rand_array, size);
    free(rand_array);

    return 0;
}
