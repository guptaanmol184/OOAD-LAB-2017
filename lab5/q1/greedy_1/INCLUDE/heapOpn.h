#ifndef heapOpn_H
#define heapOpn_H

#include "./Implementation/heapOpn.cpp"

/*Heap operation FIND PARENT INDEX for array[0 ... n-1]
DS: HEAP (Complete Tree) using array*/
int parent(int elementIndex);

/*Heap operation HEAPIFY for a particular element in array[0 ... n-1]
DS: HEAP (Complete Tree) using array*/
void heapify(int *array,int elementIndex);

#endif