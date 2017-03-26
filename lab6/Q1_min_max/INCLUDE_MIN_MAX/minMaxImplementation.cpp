#include <stdlib.h>
#include <cmath>

template <typename C>
C linMinFind(C *array,int size)
{
	C min=array[0];
	for(int i=1;i<size;++i)
		if(array[i]<min)
			min=array[i];

	return min;
}

template <typename C>
C linMaxFind(C *array,int size)
{
	C max=array[0];
	for(int i=1;i<size;++i)
		if(array[i]>max)
			max=array[i];

	return max;
}


template <typename C>
C *minMax(C *array,int size)
{
	C *maxCandidates,*minCandidates;

	maxCandidates=(C *)malloc(sizeof(C)*ceil(size/2.00));
	minCandidates=(C *)malloc(sizeof(C)*ceil(size/2.00));

	int i;
	for(i=0;i<(size-1);i+=2)
	{
		if(array[i]>=array[i+1])
		{
			maxCandidates[i/2]=array[i];
			minCandidates[i/2]=array[i+1];
		}

		else
		{
			maxCandidates[i/2]=array[i+1];
			minCandidates[i/2]=array[i];
		}
	}

	if(size%2==1)
	{
		maxCandidates[size/2]=array[size-1];
		minCandidates[size/2]=array[size-1];
	}

	/*
	minAndMax[0] contains Min and minAndMax[1] contains Max
	pointer to minAndMax returned by Function
	*/
	C *minAndMax=(C *)malloc(sizeof(C)*2);

	minAndMax[0]=linMinFind(minCandidates,ceil(size/2.00));
	minAndMax[1]=linMaxFind(maxCandidates,ceil(size/2.00));

	return minAndMax;
}
