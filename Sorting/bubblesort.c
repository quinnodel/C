/* -----------------------
Author - Quinn Hiaasen
Date Created - 11/19/2023
-------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isSorted(int *arr, int size){
    bool sorted = true;
    for (int i = 1; i < size; i++){
        if (arr[i] < arr[i - 1]){
            sorted = false;}
    }

    return sorted;
}

int *bubbleSort(int *rand_arr, int size){
    printf("--- Beginning bubbleSort() ----\n");
    
    int *sorted = rand_arr;
    int swapnumber = 0;
    int passnumber = 0;
    while(isSorted(sorted,size)==0){
        passnumber++;
        for (int i = 0; i < size; i++){
            int curr = sorted[i];
            int next = sorted[i+1];
            if (next < curr){
                swapnumber++;
                printf("--- Mismatch Found! Performing Swap (%d) on Pass (%d) ---\n",swapnumber,passnumber);
                sorted[i] = next;
                sorted[i+1] = curr;
            }
        }
    }
    printf("--- MySort() Has Finished! ---\n");
    printf("--- Summary: %d operations in %d passes. ---\n", swapnumber,passnumber);
    return sorted;
}

void printIntArray(int *arr, int size){
    for (int i = 0; i < size; i++){
        printf("--- Index: %d --- Value: %d ---\n", i, arr[i]);
    }
}

int *createRandArray(int size){
    srand(time(NULL)); // sets the random seed
    int *rand_array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        rand_array[i] = rand();
    }
    return rand_array;
}

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);
    int *rand_array = createRandArray(size);
    clock_t start, end;

    printf("--- Array of %d Random Integers. ---\n",size);
    printIntArray(rand_array, size);
    printf("--- Array Sorted: %d ---\n", isSorted(rand_array,size));

    start = clock();
    int* sorted_arr = bubbleSort(rand_array,size);
    end = clock();
    double time_elapsed = ((double)(end-start)) / CLOCKS_PER_SEC;

    printf("--- New Array Sorted: %d ---\n", isSorted(sorted_arr,size));
    printf("--- Sorted Successfully in %f seconds. ---\n", time_elapsed);


    free(rand_array);

    return 0;
}
