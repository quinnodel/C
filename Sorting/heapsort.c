#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
TODO

- implement insert() , insertHeper()
- implement minHeapify()


*/

struct Heap{
    int* arr;
    int size;
    int capacity;
};
typedef struct Heap heap;

void printHeap(heap* h){
 
    
}

heap* createHeap(int capacity, int* nums){
    heap* minheap = (heap*)malloc(sizeof(heap));
    if(minheap==NULL){printf("Error: Heap Memory Allocation Failed");}
    minheap -> size = 0;
    minheap -> capacity = capacity;
    minheap -> arr = (int*)malloc(capacity * sizeof(int));
    if(minheap -> arr == NULL){printf("Error: Internal Array Allocation Failed");}

    for (int i = 0; i < capacity; i++){
        minheap -> arr[i] = nums[i]; // populate the internal array of numbers
    }


    
}



int main(int argc, char* argv[]){


    return 0;
}