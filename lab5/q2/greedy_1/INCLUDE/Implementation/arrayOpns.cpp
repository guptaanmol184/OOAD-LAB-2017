#include <stdlib.h>

/*
Clone or make copy of an array
Input: array to clone of size 'n'
Returns: pointer to cloned array of type FLOAT
*/
float *array_clone(int *array,int n)
{
	int i=0;
	float *clone=(float *)malloc(sizeof(float)*n);
	for(i=0;i<n;++i)
		clone[i]=array[i];

	return clone;
}

/*
Clone or make copy of an array
Input: array to clone of size 'n'
Returns: pointer to cloned array of type FLOAT
*/
float *array_clone(float *array,int n)
{
	int i=0;
	float *clone=(float *)malloc(sizeof(float)*n);
	for(i=0;i<n;++i)
		clone[i]=array[i];

	return clone;
}

/*Counts number of elements strictly above threshold in array
Input: An array of size 'n'*/
int count_threshold_exclusive(float *array,int n,float threshold)
{
	int i,cnt_above_thres=0;
	for(i=0;i<n;++i)
		if(array[i]>threshold)
			cnt_above_thres++;

	return  cnt_above_thres;
}

/*Preprocess input to extend MAXNET network for
CASE: All '-ve NUMBERS or ZERO'
Input: A array of FLOATS of size 'n'*/

#include <cfloat>
float *preprocess_ALLNEG(float *net_input,int n)
{
	int i;
	for(i=0;i<n;++i)
		net_input[i]=-1*net_input[i];

	for(i=0;i<n;++i)
	{
		if(net_input[i]==0)
			net_input[i]=FLT_MAX;
		else
			net_input[i]=1.00/net_input[i];
	}
	return net_input;

}

/*Count number of occurence of an 'element' in array
INPUT: An array of size 'n' and element to count*/
int count_occurence(int *array,int n,int element)
{
	int i,cnt_occur_elt=0;
	for(i=0;i<n;++i)
		if(array[i]==element)
			cnt_occur_elt++;

	return cnt_occur_elt;
}

/*Counts number of elements equal to or above threshold in array
Input: An array of size 'n'*/
int count_threshold_inclusive(float *array,int n,float threshold)
{
	int i,cnt_above_thres=0;
	for(i=0;i<n;++i)
		if(array[i]>=threshold)
			cnt_above_thres++;

	return  cnt_above_thres;
}

#include "../swap.h"
/*Inplace REVERSAL the order of elements of the array
Input  : Pointers to starting and ending array indices
Output : Reversed array*/
void arrayReverse(int *arrayStart,int *arrayEnd)
{
	while(arrayStart<=arrayEnd)
	{
		swap_TEMP(arrayStart,arrayEnd);
		arrayStart++;
		arrayEnd--;
	}
}

/*Merges two sorted subarrays array[p ... q] and array[q+1 ... r]
to form a sorted array[p ... q]*/
void merge(int *a,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;

	int *left=(int *)malloc(sizeof(int)*n1);
	int *right=(int *)malloc(sizeof(int)*n2);

	for(int i=0;i<n1;++i)
		*(left+i)=*(a+p+i);


	for(int i=0;i<n2;++i)
		*(right+i)=*(a+q+1+i);

	int i=0;
	int j=0;

	int k;
	for(k=0;(k<(n1+n2-1)&&(i<n1)&&(j<n2));++k)
	{
		if(*(left+i)<=*(right+j))
		{
			*(a+p+k)=*(left+i);
			i++;
		}

		else
		{
			*(a+p+k)=*(right+j);
			j++;
		}

	}

	
	while(i<n1)
	{
		*(a+p+k)=*(left+i);
		++i;
		k++;
	}

	while(j<n2)
	{
		*(a+p+k)=*(right+j);
		++j;
		k++;
	}


		
}

/*Performs binary search for 'srchElement' on array of size 'n'
Output : If element in ARRAY     : Returns index of element in array
		 If element not in ARRAY : Returns -1*/
#include <math.h>
int binarySearch(int *array,int n,int srchElement)
{
	int elementIndex=-1;

	int leftIndex=0,rightIndex=n-1;
	int middleIndex;

	while((leftIndex<=rightIndex)&&(elementIndex==-1))
	{
		middleIndex=(leftIndex+rightIndex)/2;

		if(*(array+middleIndex)==srchElement)
			elementIndex=middleIndex;

		else if(*(array+middleIndex)>srchElement)
			rightIndex=middleIndex-1;
		
		else if(*(array+middleIndex)<srchElement)
			leftIndex=middleIndex+1;
	}

	return elementIndex;	
}

/*Partitions an array
- (elements<a[r]) to left of a[r] (unsorted); and
- element a[r] between the two, i.e., 
(The place element a[r] would take if array was sorted)

- (elements>a[r]) to right of a[r] (unsorted)

INPUT: An sub-array from index p to r */
#include "../swap.h"

//quick sort partition function
int partition(int *array,int p,int r)
{
	int i=p-1;
	int x=array[r];

	for(int j=p;j<r;++j)
		if(array[j]<=x)
			swap_TEMP(&array[++i],&array[j]);

	swap_TEMP(&array[i+1],&array[r]);

	return i+1;
}

/*Print contents of an array
INPUT: An pointer to array of size 'n'*/
#include <iostream>
using namespace std;

void displayArray(int *array,int n)
{
	for(int i=0;i<n;++i)
		cout<<array[i]<<" ";
	cout<<endl;
}

/*Generate a random number array of size 'n'
INPUT : An array pointer and size of array 'n'
		Seed for RANDOM NUMBER GENERATION
*/
#include <stdlib.h>

void genRANDArray(int *array,int n,int seed)
{
	srand(seed);

	for(int i=0;i<n;++i)
		array[i]=rand();
}


/*
Randomly search log2(n) indices in the array for SrchElement
INPUT : An array of size 'n' and element to Search (SrchElement)

Note: n is a radix two number,i.e., n = 2^x; for some number x
	  The randomly choosen indices do not repeat
*/
int randomLOGSrch(int *array,int n,int srchElement)
{
	//index increment steps
	int indexIncRange=log2(n);

	int currentIndex=0;
	int flagFound=0;

	for(int i=0;(i<indexIncRange-1)&&(flagFound==0);++i)
	{
		currentIndex+=rand()%indexIncRange;
		if(array[currentIndex]==srchElement)
			flagFound=1;

		currentIndex++;
	}

	if(flagFound==0)
	{
		currentIndex+=rand()%(n-currentIndex);
		if(array[currentIndex]==srchElement)
			flagFound=1;
	}
	return flagFound;
	
}

/*
Linear Search an 'srchElement' in array of size 'n'
INPUT: An array of size 'n' and element to search (srchElement)
*/
int linearSrch(int *array,int n,int srchElement)
{
	int elementFound=0;
	for(int i=0;i<n;++i)
		if(array[i]==srchElement)
		{
			elementFound=1;
			break;
		}

	return elementFound;

}
