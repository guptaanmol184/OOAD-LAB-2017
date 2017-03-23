#ifndef SORT_H
#define SORT_H

#include "./Implementation/sort.cpp"

void sortPermute(int *array,int n);

/*Sorts an array by finding MAX and swapping with LAST element,
reducing array size by 1 and repeating
INPUT : An array of size 'n'*/
void sortAverage(int *array,int n);

/*Sorts the array pointed by 'a' from index p to index r*/
void mergesort(int *a,int p,int r);

/*Generates a new sorted array of size 'n'
INPUT  : An array of size 'n'
OUTPUT : A new sorted array of size 'n'
Note: Original array remains untampered*/
int *countSORT(int *array,int n);

/*Sorts an array by finding MAX and swapping with LAST element,
reducing array size by 1 and repeating
INPUT : An array of size 'n'*/
void selectionSort(int *array,int n);

/*QUICK sorts the array pointed to by 'array' from index p to r
by repeatedly partioning array into elements (<a[r]), a[r], (>a[r])

INPUT : An array
		Starting and ending INDEX of sub-array to sort
*/
void quickSort(int *array,int p,int r);

/*
sorts an ARRAY by randomly choosing n pairs of indices i,j (s.t. i<j); and
if a[i]>a[j]: swap a[i] and a[j]

INPUT : An array of size 'arraySize'
		An seed to randomly choose pairs to indices

NOTE : Success rate -> 0 for inputs large than size 8 
*/
void randomSort(int *array,int arraySize,int seed);

/*
Checks if an array is sorted in ASCENDING order
INPUT  : An array of size 'arraySize'
RETURN : 1; if sorted
		 0; if unsorted
*/
int checkSorted(int *array,int arraySize);

/*
sorts an sub-array ARRAY[ p ... r ] using INSERTION SORT algorithm

INPUT : An array
		Starting and ending INDEX of sub-array to sort
*/
void IndexInsSort(int *array,int p,int r);


/*Sorts an array using HYBIRD of Insertion and Quick Sort

Sorts the array using "Quick Sort and Partition" for sub-arrays of size > threshold_ins
Uses insertion sort if sub-probkem size <= threshold_ins

INPUT : An array
		Starting and ending INDEX of sub-array to sort
		Threshold size of sub-array to use INSERTION SORT
*/
void modifiedQSort(int *array,int p,int r,int threshold_ins);

#endif

