#include <stdlib.h>

#include "../arrayOpns.h"
/*Forms a set out of a given array of size 'n'
i.e., removes DUPLICATES and sorts the elements
INPUT  : A pointer to the array pointer and size of array 'n'
OUTPUT : Size of array after formSET

Note: Please declare array using malloc in MAIN, not array[n]*/
int formSET(int **arrayPtr,int n)
{
	int set_SIZE=1;

	int i,temp,j,k;
	for(i=1;i<n;++i)
	{
		if(binarySearch(*arrayPtr,set_SIZE,*(*arrayPtr+i))==-1)
		{
			temp=*(*arrayPtr+i);

			for(j=set_SIZE-1;(j>=0)&&(*(*arrayPtr+j)>temp);--j)
			{
				*(*arrayPtr+j+1)=*(*arrayPtr+j);
			}

			*(*arrayPtr+j+1)=temp;

			set_SIZE++;
		}
	}

	int *new_set=(int *)malloc(sizeof(int)*set_SIZE);

	for(i=0;i<set_SIZE;++i)
		new_set[i]=(*arrayPtr)[i];

	free(*arrayPtr);
	*arrayPtr=new_set;	

	return set_SIZE;
}

#include <iostream>
using namespace std;
#include "../combinatorics.h"

/*Prints all 'subsetSIZE' sized subsets of set
INPUT  : An set of size 'set_SIZE'
OUTPUT : Returns number of subsets printed
		 Returns '0' if subsetSIZE > set_SIZE */
int printNsizeSUBSETS(int *set,int set_SIZE,int subsetSIZE)
{
	int subset_count=0;

	if(subsetSIZE<=set_SIZE)
	{
		int element_include[set_SIZE]={0};

		int i;
		for(i=0;i<subsetSIZE;++i)
			element_include[i]=1;
		
		do
		{
			cout<<"{ ";
			for(i=0;i<set_SIZE;++i)
				if(element_include[i]==1)
					cout<<set[i]<<" ";

			cout<<"}"<<endl;

			subset_count++;

		}while(nxtPermutation(element_include,element_include+set_SIZE-1));
	}
	
	return subset_count;
}