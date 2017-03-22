#ifndef arrayOpns_H
#define arrayOpns_H

/*
Clone or make copy of an array
Input: array to clone of size 'n'
Returns: pointer to cloned array of type FLOAT
*/
float *array_clone(int *array,int n);

/*
Clone or make copy of an array
Input: array to clone of size 'n'
Returns: pointer to cloned array of type FLOAT
*/
float *array_clone(float *array,int n);

/*Counts number of elements strictly above threshold in array
Input: An array of size 'n'*/
int count_threshold_exclusive(float *array,int n,float threshold);

/*Preprocess input to extend MAXNET network for
CASE: All '-ve NUMBERS or ZERO'
Input: A array of FLOATS of size 'n'*/

float *preprocess_ALLNEG(float *net_input,int n);

/*Count number of occurence of an 'element' in array
INPUT: An array of size 'n' and element to count*/
int count_occurence(int *array,int n,int element);

/*Counts number of elements equal to or above threshold in array
Input: An array of size 'n'*/
int count_threshold_inclusive(float *array,int n,float threshold);


/*Inplace REVERSAL the order of elements of the array
Input  : Pointers to starting and ending array indices
Output : Reversed array*/
void arrayReverse(int *arrayStart,int *arrayEnd);

/*Merges two sorted subarrays array[p ... q] and array[q+1 ... r]
to form a sorted array[p ... q]*/
void merge(int *a,int p,int q,int r);

/*Performs binary search for 'srchElement' on array of size 'n'
Output : If element in ARRAY     : Returns index of element in array
		 If element not in ARRAY : Returns -1*/

int binarySearch(int *array,int n,int srchElement);

/*Partitions an array
- (elements<a[r]) to left of a[r] (unsorted); and
- element a[r] between the two, i.e., 
(The place element a[r] would take if array was sorted)

- (elements>a[r]) to right of a[r] (unsorted)

INPUT: An sub-array from index p to r */

//quick sort partition function
int partition(int *array,int p,int r);

/*Print contents of an array
INPUT: An pointer to array of size 'n'*/

void displayArray(int *array,int n);

/*Generate a random number array of size 'n'
INPUT : An array pointer and size of array 'n'
		Seed for RANDOM NUMBER GENERATION
*/

void genRANDArray(int *array,int n,int seed);

/*
Randomly search log2(n) indices in the array for SrchElement
INPUT : An array of size 'n' and element to Search (SrchElement)

Note: n is a radix two number,i.e., n = 2^x; for some number x
	  The randomly choosen indices do not repeat
*/
int randomLOGSrch(int *array,int n,int srchElement);

/*Linear Search an 'srchElement' in array of size 'n'
INPUT: An array of size 'n' and element to search (srchElement)*/

int linearSrch(int *array,int n,int srchElement);


#include "./Implementation/arrayOpns.cpp"

#endif