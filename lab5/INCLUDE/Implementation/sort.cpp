#include "../combinatorics.h"
/*Sorts an array by listing all permutations and finding the sorted permutation
Input  : An array of size 'n'
Output : A sorted array*/
void sortPermute(int *array,int n)
{
	while(nxtPermutation(array,array+n-1))
		continue;
}

/*Sorts an array by finding MAX and swapping with LAST element,
reducing array size by 1 and repeating
INPUT : An array of size 'n'*/
#include "../mathINTERFACE.h"
void sortAverage(int *array,int n)
{	
	int maxIndex,i;
	for(i=n;i>1;--i)
	{
		maxIndex=max_average_index(array,i);
		swap_XOR(&array[maxIndex],&array[i-1]);
	}
}

#include "../arrayOpns.h"
/*Sorts an sub-array from index p to index r using DIVIDE AND CONQUER TECHNIQUE
INPUT: An pointer to array 'a'
	   Starting index p and ending index r of the SUBARRAY to be sorted

	   Time COMPLEXITY  : Independent of input properties
	   Space COMPLEXITY : theta(n)
*/
void mergesort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

#include <stdlib.h>
/*Generates a new sorted array of size 'n'
INPUT  : An array of size 'n'
OUTPUT : A NEW sorted array of size 'n'
Note: Original array remains untampered

NOTE : Optimised version of ADJACENCY MATRIX METHOD (Saravana Balaji)*/
int *countSORT(int *array,int n)
{
	int count[n]={0};
	
	int i,j;
	for(i=0;i<n-1;++i)
		for(j=i+1;j<n;++j)
		{
			if(array[i]>array[j])
				count[i]++;
			else
				count[j]++;
		}

	int *array_sorted=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;++i)
	{
		array_sorted[count[i]]=array[i];
	}
		
	return array_sorted;
}

/*Sorts an array by finding MAX and swapping with LAST element,
reducing array size by 1 and repeating
INPUT : An array of size 'n'*/
#include "../mathINTERFACE.h"
void selectionSort(int *array,int n)
{	
	int maxIndex,i;
	for(i=n;i>1;--i)
	{
		maxIndex=maxLinearSRCH_index(array,i);
		swap_XOR(&array[maxIndex],&array[i-1]);
	}
}

/*QUICK sorts the array pointed to by 'array' from index p to r
by repeatedly partioning array into elements (<a[r]), a[r], (>a[r])

INPUT : An array
		Starting and ending INDEX of sub-array to sort
*/
void quickSort(int *array,int p,int r)
{
	if(p<r)
	{
		int q=partition(array,p,r);
		quickSort(array,p,q-1);
		quickSort(array,q+1,r);
	}
	
}

#include <stdlib.h>
#include <math.h>

/*
sorts an ARRAY by randomly choosing n pairs of indices i,j (s.t. i<j); and
if a[i]>a[j]: swap a[i] and a[j]

INPUT : An array of size 'arraySize'
		An seed to randomly choose pairs to indices

NOTE : Success rate -> 0 for inputs large than size 8 
*/
void randomSort(int *array,int arraySize,int seed)
{
	int i;
	srand(seed);

	int index1,index2;
	for(i=0;i<arraySize;++i)
	{	
		do
		{	
			index1=rand()%arraySize;
			index2=rand()%arraySize;
		}while(index1==index2);

		if(index1>index2)
			swap_TEMP(&index1,&index2);

		//cout<<index1<<" "<<index2<<endl;

		if(array[index1]>array[index2])
		{
			//displayArray(array,arraySize);
			//cout<<index1<<" "<<index2<<"swapped"<<endl;
			swap_TEMP(&array[index1],&array[index2]);
			//displayArray(array,arraySize);
			//cout<<endl;

		}
	}
}


/*
Checks if an array is sorted in ASCENDING order
INPUT  : An array of size 'arraySize'
RETURN : 1; if sorted
		 0; if unsorted
*/
int checkSorted(int *array,int arraySize)
{
	int isSorted=1;

	for(int i=0;i<arraySize-1;++i)
		if(array[i]>array[i+1])
		{
			isSorted=0;
			break;
		}

	return isSorted;

}

/*
sorts an sub-array ARRAY[ p ... r ] using INSERTION SORT algorithm

INPUT : An array
		Starting and ending INDEX of sub-array to sort
*/
void IndexInsSort(int *array,int p,int r)
{
	int i,j,temp;
	for(i=p+1;i<=r;++i)
	{
		temp=array[i];
		for(j=i-1;j>=p;--j)
		{
			if(array[j]>temp)
				array[j+1]=array[j];

			else
				break;
		}

		array[j+1]=temp;
	}
}

/*Sorts an array using HYBIRD of Insertion and Quick Sort

Sorts the array using "Quick Sort and Partition" for sub-arrays of size > threshold_ins
Uses insertion sort if sub-probkem size <= threshold_ins

INPUT : An array
		Starting and ending INDEX of sub-array to sort
		Threshold size of sub-array to use INSERTION SORT
*/
void modifiedQSort(int *array,int p,int r,int threshold_ins)
{
	if(p<r)
	{
		int array_size=r-p+1;
		if(array_size<=threshold_ins)
		{
			IndexInsSort(array,p,r);
		}

		else
		{
			int q=partition(array,p,r);
			modifiedQSort(array,p,q-1,threshold_ins);
			modifiedQSort(array,q+1,r,threshold_ins);
		}
		
	}
	
}