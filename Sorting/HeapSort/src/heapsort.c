/*--------------------------
Author : Quinn Hiaasen
--------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
Struct : Heap
- size and capacity must be store seperately
- to enable checks and not overwriting data
*/

struct Heap
{
    int *arr;
    int size;
    int capacity;
};
typedef struct Heap heap;

/*
Function : extractMin()
- returns and removes the minimum
*/

int extractMin(int size, heap *h)
{
    int min = h->arr[0];
    h->arr[0] = h->arr[size - 1];
    h->size--;

    // heapifyDown()

    return min;
}

/*
Function : heapifyDown()
*/

void heapifyDown(int index, heap *h)
{
    int left_child_index = 2 * index + 1;
    int right_child_index  = 2 * index + 2;
    
    if (h -> arr[index] < h -> arr[left_child_index])
    {
        int temp = h -> arr[index];
        h -> arr[index] = h -> arr[left_child_index];
        h -> arr[left_child_index] = temp; // LEFT OFF HERE
        // need to handle incrementing index

    }
}

/*
Function : heapifyUp()
- maintains the vertical structure of the min heap
- does not maintain child node structure!
*/

void heapifyUp(int index, heap *h)
{
    int parent_index = (index - 1) / 2;

    if (index > 0 && h->arr[index] < h->arr[parent_index])
    {
        int temp = h->arr[index]; // store the previous value

        h->arr[index] = h->arr[parent_index]; // replace the current with the parent
        h->arr[parent_index] = temp;          // replace the parent with the newer, lower value

        heapifyUp(parent_index, h);
    }
}

/*
Function : insert()
- this function ONLY inserts the element at the end of the array
- and does NOT maintain the min heap structure
*/

void insert(int num, heap *h)
{
    if (h->size < h->capacity)
    {
        h->arr[h->size] = num; // the size should be the correct insert index
        h->size++;             // so we have to increment it
    }
    else
    {
        printf("Heap is Full! Cannot insert.");
    }
}

/*
Function : createHeap()
- returns a pointer to a heap struct
- creates an empty heap, does not pre-populate
*/

heap *createHeap(int capacity, int *nums)
{
    heap *minheap = (heap *)malloc(sizeof(heap)); // allocate the memory for the heap
    if (minheap == NULL)
    {
        printf("Error: Heap Memory Allocation Failed");
    }
    minheap->size = 0; // no elements in heap yet, so size is 0
    minheap->capacity = capacity;
    minheap->arr = (int *)malloc(capacity * sizeof(int)); // allocating memory for heap elements
    if (minheap->arr == NULL)
    {
        printf("Error: Internal Array Allocation Failed");
    }

    return minheap;
}

/*
ENTRY POINT
*/

int main(int argc, char *argv[])
{

    return 0;
}
