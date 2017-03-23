/*Heap operation FIND PARENT INDEX for array[0 ... n-1]
DS: HEAP (Complete Tree) using array*/
#include <math.h>
int parent(int elementIndex)
{
	return floor((elementIndex-1.00)/2);
}

/*Heap operation HEAPIFY for a particular element in array[0 ... n-1]
DS: HEAP (Complete Tree) using array*/
void heapify(int *array,int elementIndex)
{
	int temp;

	int alpha=elementIndex;
	int p=parent(elementIndex);

	while(p>=0)
	{
		if(array[alpha]>array[p])
		{
			//swap array[alpha] and array[parent]
			temp=array[p];
			array[p]=array[alpha];
			array[alpha]=temp;
		}

		alpha=p;
		p=parent(p);
	}
}