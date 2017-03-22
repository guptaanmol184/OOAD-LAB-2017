#include <iostream>
using namespace std;

#include "../INCLUDE/swap.h"
#include "../INCLUDE/sort.h"
#include "../INCLUDE/arrayOpns.h"

#define ARRAY_SIZE 100
#define PIVOT_SIZE 5

int manyPIVOTpartition(int *array,int array_size,int pivot_length);
void multiPIVOTsort(int *array,int array_size,int pivot_length);
main()
{
	int array[ARRAY_SIZE];

	int seed;
	cout<<"Enter seed to generate random array"<<endl;
	cin>>seed;

	//reading array inputs
	genRANDArray(array,ARRAY_SIZE,seed);

	/*for(i=0;i<ARRAY_SIZE;++i)
		cin>>array[i];*/
	
	int j;
	
	multiPIVOTsort(array,ARRAY_SIZE,PIVOT_SIZE);

	/*
	for(j=0;j<ARRAY_SIZE;++j)
		cout<<array[j]<<" ";

	cout<<endl;
	*/

	int isSorted=checkSorted(array,ARRAY_SIZE);

	if(isSorted==1)
		cout<<"The ARRAY is SORTED"<<endl;

	else
		cout<<"The ARRAY is NOT SORTED!!!"<<endl;
}

int manyPIVOTpartition(int *array,int array_size,int pivot_length)
{
	/*Last pivot_length elements are choosen as pivot*/
	int pivot_start=array_size - pivot_length;
	int pivot_end=pivot_start + pivot_length -1;

	//cout<<"PS = "<<pivot_start<<" PE="<<pivot_end<<endl;

	IndexInsSort(array,pivot_start,pivot_end);

	int i,j,k;

	for(i=-1,j=0;j<pivot_start;++j)
	{
		//element less than minimum pivot
		if(array[j]<array[pivot_start])
		{
			//cout<<array[j]<<"< PS "<<array[pivot_start]<<endl;
			swap_XOR(&array[j],&array[++i]);
		}

		//element between pivots
		else if((array[j]>array[pivot_start])&&(array[j]<array[pivot_end]))
		{
			swap_TEMP(&array[j],&array[pivot_start]);
			swap_TEMP(&array[j],&array[++i]);
			IndexInsSort(array,pivot_start,pivot_end);

		}	
	}

	//put pivot into right positions
	for(j=0;j<pivot_length;++j)
	{
		swap_TEMP(&array[i+1+j],&array[pivot_start+j]);
	}

	return i;
}

void multiPIVOTsort(int *array,int array_size,int pivot_length)
{
	if(array_size<=pivot_length)
		IndexInsSort(array,0,array_size-1);

	else
	{
		int partition_index;
		partition_index=manyPIVOTpartition(array,array_size,pivot_length);

		multiPIVOTsort(array,partition_index+1,pivot_length);
		multiPIVOTsort(array+partition_index+pivot_length+1,array_size-(partition_index+1)-pivot_length,pivot_length);
	}
}

