#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 16

int rand_search(int array[],int size,int x);
int rand_search_sqrtn(int array[],int size,int x);

int main()
{
	int i;
	int flag=-1;
	int sample_space[SIZE];
	srand(time(NULL));

	//create sample space
	for(i=0;i<SIZE;i++)
		sample_space[i]=rand()%10;

	//print sample space
	for(i=0;i<SIZE;i++)
		cout<<i<<": "<<sample_space[i]<<endl;

	int element_to_search=sample_space[rand()%SIZE];
	cout<<"element_to_search: "<<element_to_search<<endl;

	flag=rand_search_sqrtn(sample_space,SIZE,element_to_search);

	if(flag)
		cout<<"Found"<<endl;
	else
		cout<<"Not found"<<endl;


}

int rand_search_logn(int array[],int size,int x)
{
	int i;
	int index;
	int temp;
	int original_size=size;
	cout<<"Location and value:"<<endl;
	for(i=1;i<=log2(original_size);i++)
	{
		index=rand()%size;
		cout<<i<<"\t"<<index<<"\t"<<array[index]<<endl;
		if(array[index]==x)
			return 1;
		else
		{
			//swap current element with last element in the array
			temp=array[index];
			array[index]=array[size];
			array[size]=temp;
			size--;
		}
	}

	return 0;
}

int rand_search_sqrtn(int array[],int size,int x)
{
	int i;
	int index;
	int temp;
	int original_size=size;
	cout<<"Locations and value:"<<endl;
	for(i=1;i<=sqrt(original_size);i++)
	{
		index=rand()%size;
		cout<<i<<"\t"<<index<<"\t"<<array[index]<<endl;
		if(array[index]==x)
			return 1;
		else
		{
			//swap current element with last element in the array
			temp=array[index];
			array[index]=array[size];
			array[size]=temp;
			size--;
		}
	}

	return 0;
}