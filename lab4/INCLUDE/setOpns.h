#ifndef setOpns_H
#define setOpns_H

#include "./Implementation/setOpns.cpp"
/*Forms a set out of a given array of size 'n'
i.e., removes DUPLICATES and sorts the elements
INPUT  : A pointer to the array pointer and size of array 'n'
OUTPUT : Size of array after formSET*/
int formSET(int **arrayPtr,int n);

/*Prints all 'subsetSIZE' sized subsets of set
INPUT  : An set of size 'set_SIZE'
OUTPUT : Returns number of subsets printed*/
int printNsizeSUBSETS(int *set,int set_SIZE,int subsetSIZE);

#endif