#include <iostream>
using namespace std;

#include <math.h>

//number of samples
#define NO_SAMPLES 1000000
//size of array
#define ARRAY_SIZE int(pow(2,3))

#include <stdlib.h>
#include <time.h>

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

void swap_TEMP(int *a,int *b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

void displayArray(int *array,int n)
{
	for(int i=0;i<n;++i)
		cout<<array[i]<<" ";
	cout<<endl;
}

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



void genRANDArray(int *array,int n,int seed)
{
	srand(seed);

	for(int i=0;i<n;++i)
		array[i]=rand();
}

main()
{
	int *array=(int *)malloc(sizeof(int)*ARRAY_SIZE);

	int sample_cntr;
	
	time_t seed=31*time(NULL);
	cout<<"SEED: "<<seed<<endl;
	srand(seed);
	int count_success=0;

	cout<<"ARRAY SIZE: "<<ARRAY_SIZE<<endl;
	cout<<"NO OF SAMPLES: "<<NO_SAMPLES<<endl;

	for(sample_cntr=0;sample_cntr<NO_SAMPLES;++sample_cntr)
	{
		genRANDArray(array,ARRAY_SIZE,rand()+sample_cntr);

		//cout<<"BEFORE SORT"<<endl;

		randomSort(array,ARRAY_SIZE,rand()+sample_cntr);

		//cout<<"AFTER SORT"<<endl;
		//displayArray(array,ARRAY_SIZE);
		if(checkSorted(array,ARRAY_SIZE))
		{
			count_success+=1;
			//displayArray(array,ARRAY_SIZE);	
			
		}
	}

	cout<<"NO OF SUCCESSFUL SORTS: "<<count_success<<endl;
	cout<<"PROBABILITY: "<<((float)count_success/(float)NO_SAMPLES)*100<<"%"<<endl;
}