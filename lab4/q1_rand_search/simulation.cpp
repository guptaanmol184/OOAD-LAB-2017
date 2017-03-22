/*
 By running the simulation of random search vs linear search
 We can see that the randomised algorithms employed correct
 output in only about 50% of the cases.
 */

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define SIZE 4
#define TRIALS 100

// function prototype
int linearSrch(int *array,int n,int srchElement);
int rand_search_logn(int array[],int size,int x);
int rand_search_sqrtn(int array[],int size,int x);

int main()
{

	int i,j;
	int seed;
	int search_element;
	int ls_found,lgn_found,sqrtn_found;
	int crt_ls=0,ctr_lgn=0,ctr_sqrtn=0;
	int search_array[SIZE];

	cout<<"seed:";
	cin>>seed;

	for(i=0;i<TRIALS;i++)
	{
		srand(seed+i*i+time(NULL));

		for(j=0;j<SIZE;j++)
			search_array[j]=rand()%1000;

		search_element=search_array[rand()%SIZE];

		//perform lserach
		ls_found=linearSrch(search_array,SIZE,search_element);
		if(ls_found)
			crt_ls++;

		//perform log_search
		lgn_found=rand_search_logn(search_array,SIZE,search_element);
		if(lgn_found)
			ctr_lgn++;

		//perform sqrtn_search
		sqrtn_found=rand_search_sqrtn(search_array,SIZE,search_element);
		if(sqrtn_found)
			ctr_sqrtn++;
	}

	cout<<"STATS:\n";
	cout<<"lsearch: \n\t"<<crt_ls<<"/"<<TRIALS;
	cout<<"\t"<<"prob:"<<((float)crt_ls/(float)TRIALS)*100<<"%";
	cout<<"\nlogn rand search: \n\t"<<ctr_lgn<<"/"<<TRIALS;
	cout<<"\t"<<"prob:"<<((float)ctr_lgn/(float)TRIALS)*100<<"%";
	cout<<"\nsqrt rand search: \n\t"<<ctr_sqrtn<<"/"<<TRIALS;
	cout<<"\t"<<"prob:"<<((float)ctr_sqrtn/(float)TRIALS)*100<<"%";

	cout<<endl;
}

//implementation
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

int rand_search_logn(int array[],int size,int x)
{
	int i;
	int index;
	int temp;
	int original_size=size;
	//cout<<"Location and value:"<<endl;
	for(i=1;i<=log2(original_size);i++)
	{
		index=rand()%size;
		//cout<<i<<"\t"<<index<<"\t"<<array[index]<<endl;
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
	//cout<<"Locations and value:"<<endl;
	for(i=1;i<=sqrt(original_size);i++)
	{
		index=rand()%size;
		//cout<<i<<"\t"<<index<<"\t"<<array[index]<<endl;
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