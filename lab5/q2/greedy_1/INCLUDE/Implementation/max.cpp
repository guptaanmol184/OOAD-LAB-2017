/*find max of an array using one pass of BUBBLE SORT
Input: An array of size 'n'*/
int max_bubble(int *array,int n)
{
	int i,temp;
	for(i=0;i<n-1;++i)
	{
		if(array[i]>array[i+1])
		{
			//swap array[i],array[i+1]
			temp=array[i+1];
			array[i+1]=array[i];
			array[i]=temp;
		}
	}

	return array[n-1];
}

#include "../heapOpn.h"
/*find max of an array by forming MAXHEAP
Input: An array of size 'n'*/
int max_heap(int *array,int n)
{
	int i=0;
	for(i=n-1;i>0;--i)
		heapify(array,i);

	return array[0];
}

/*find max of an array using DIVIDE AND CONQUER
Similar to MERGE SORT
Input: An array of size 'n'*/
int max_div_conq(int *array,int initialIndex,int endIndex)
{
	//Conquering the sub-problems
	if(initialIndex==endIndex)
		return array[initialIndex];

	else if(initialIndex+1==endIndex)
		return array[initialIndex]>=array[endIndex]?array[initialIndex]:array[endIndex];

	//Dividing and combining steps
	else
	{
		int max1=max_div_conq(array,initialIndex,(initialIndex+endIndex)/2);
		int max2=max_div_conq(array,(initialIndex+endIndex)/2+1,endIndex);
		return max1>=max2?max1:max2;
	}
}

#include "../mathINTERFACE.h"
#include <limits.h>
#include <math.h>
/*find max of an array using 'MAX>=AVERAGE' property
Input  : An array of size 'n'
Output : MAX element of the array*/
int max_average(int *array,int n)
{
	int i,flag=1;
	//creating and initialising an array to flag potential maximums
	char isPotentialMax[n];
	for(i=0;i<n;++i)
		isPotentialMax[i]=1;

	int avg=ceil(average(array,n,INT_MIN));
	//shrinking search space to find max
	while(flag!=0)
	{	
		flag=0;
		for(i=0;i<n;++i)
			if((array[i]<avg)&&(isPotentialMax[i]==1))
			{
				isPotentialMax[i]=0;
				flag=1;
			}
		avg=ceil(average(array,n,avg));
	}

	for(i=0;i<n;++i)
		if(isPotentialMax[i]==1)
			break;

	return array[i];
}

/*find max of an array using 'MAX>=AVERAGE' property
Input  : An array of size 'n'
Output : Index of the MAX element of the array*/
int max_average_index(int *array,int n)
{
	int i,flag=1;
	//creating and initialising an array to flag potential maximums
	char isPotentialMax[n];
	for(i=0;i<n;++i)
		isPotentialMax[i]=1;

	int avg=ceil(average(array,n,INT_MIN));
	//shrinking search space to find max
	while(flag!=0)
	{	
		flag=0;
		for(i=0;i<n;++i)
			if((array[i]<avg)&&(isPotentialMax[i]==1))
			{
				isPotentialMax[i]=0;
				flag=1;
			}
		avg=ceil(average(array,n,avg));
	}

	for(i=0;i<n;++i)
		if(isPotentialMax[i]==1)
			break;

	return i;
}

/*finding max of an array using MAXNET neural network
Input: An array of size 'n'
Note:	- Works only when MAX is unique
		- Works only for all +ve numbers or mix of +ve and -ve (Corrected to work for -ve NUMBERS)
*/
#include "../arrayOpns.h"
int max_MAXNET(int *array,int n)
{
	float *net_input=array_clone(array,n);

	int i,j;
	
	//inter-network weight Epsilon - made large
	//float epsilon=1/(pow(2,n));
	float epsilon=0.1;

	if(n>2)
		epsilon=1.00/pow(2,n);

	if(count_threshold_exclusive(net_input,n,0)==0)
	{
		net_input=preprocess_ALLNEG(net_input,n);
	}

	float *net_output=array_clone(net_input,n);

	while(count_threshold_exclusive(net_input,n,0)>1)
	{

		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
			{
				if(i!=j)
					net_output[i]-=epsilon*net_input[j];
			}
				

		for(i=0;i<n;++i)
			if(net_output[i]<0)
				net_output[i]=0;	

		free(net_input);
		net_input=array_clone(net_output,n);
	}

	for(i=0;i<n;++i)
		if(net_output[i]>0)
			break;

		
	return array[i];	

}

/*Find maximum an an array of size 'n' by RECURSIVE SUBTRACTION
The maximum survives the longest*/
int max_recDIFF(int *array,int n)
{
	int i,j;
	float arr_reducer;
	float *arr=array_clone(array,n);

	//if all are negative do preprocessing before operating on it
	if(count_threshold_inclusive(arr,n,0)==0)
		arr=preprocess_ALLNEG(arr,n);

	for(i=0;(i<n)&&(count_threshold_exclusive(arr,n,0)>0);++i)
	{
		arr_reducer=arr[i];
		if(arr_reducer<=0)
			continue;
		
		for(j=0;j<n;++j)
			arr[j]-=arr_reducer;
	}

	for(i=0;i<n;++i)
		if(arr[i]==0)
			break;

	return array[i];
}


/*Find maximum of an array of size 'n' by
INSERTION IN BINARY SEARCH TREE
INPUT: An array of size 'n' (Duplicates allowed)*/
#include "../tree.h"

int max_BST(int *array,int n)
{
	int i;

	binarySearchTree BST;

	for(i=0;i<n;++i)
		BST.insert(array[i]);

	return BST.maximum();
}

/*Finds the index of the maximum of an array of size 'n'
by LINEARLY SCANNING THE ARRAY
INPUT: An array of size 'n'*/
int maxLinearSRCH_index(int *array,int n)
{
	int maxIndex=0;

	int i;
	for(i=1;i<n;++i)
		if(array[i]>array[maxIndex])
			maxIndex=i;

	return maxIndex;
}