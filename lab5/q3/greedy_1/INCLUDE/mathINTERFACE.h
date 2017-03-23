#ifndef mathINTERFACE_H
#define mathINTERFACE_H

#include "./Implementation/gcd.cpp"
/*calculates GCD using Euclidean ALGORITHM
Input: 2 integers*/
int gcd(int a,int b);

/*calculates GCD using Euclidean ALGORITHM
Input: An array of size 'n', n>=2*/
int gcd(int *array,int n);

#include "./Implementation/signum.cpp"
/*Calculate signum or sign of an number
INTPUT: An INTEGER
RETURN: num > 0 : 1
		num = 0 : 0
		num < 0 : -1*/
int signum(int a);

/*Calculate signum or sign of an FLOATING number
INTPUT: An INTEGER
RETURN: num > 0 : 1
		num = 0 : 0
		num < 0 : -1*/
int signum(float a);

#include "./Implementation/average.cpp"
/*find the AVERAGE of an array[0 ... n-1]
OPTIMISED TO WORK FOR LARGE NUMBERS
D.S. An array of size 'n'*/
double average(int *array,int n,int threshold);

#include "./Implementation/max.cpp"
/*find max of an array using one pass of BUBBLE SORT
Input: An array of size 'n'*/
int max_bubble(int *array,int n);

/*find max of an array by forming MAXHEAP
Input: An array of size 'n'*/
int max_heap(int *array,int n);

/*find max of an array using DIVIDE AND CONQUER
Similar to MERGE SORT
Input: An array of size 'n'*/
int max_div_conq(int *array,int initialIndex,int endIndex);

/*find max of an array using 'MAX>=AVERAGE' property
Input  : An array of size 'n'
Output : MAX element of the array*/
int max_average(int *array,int n);

/*find max of an array using 'MAX>=AVERAGE' property
Input  : An array of size 'n'
Output : Index of the MAX element of the array*/
int max_average_index(int *array,int n);

/*finding max of an array using MAXNET neural network
Input: An array of size 'n'
Note:	- Works only when MAX is unique
		- Works only for all +ve numbers or mix of +ve and -ve (Corrected to work for -ve NUMBERS)
*/
int max_MAXNET(int *array,int n);

/*Find maximum an an array of size 'n' by RECURSIVE SUBTRACTION
The maximum survives the longest*/
int max_recDIFF(int *array,int n);

/*Find maximum of an array of size 'n' by
INSERTION IN BINARY SEARCH TREE
INPUT: An array of size 'n' (Duplicates allowed)*/
int max_BST(int *array,int n);

/*Finds the index of the maximum of an array of size 'n'
by LINEARLY SCANNING THE ARRAY
INPUT: An array of size 'n'*/
int maxLinearSRCH_index(int *array,int n);

#endif