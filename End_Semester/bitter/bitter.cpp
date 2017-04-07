#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int insertion(int *array,int p,int r);

int main(void)
{
	srand(time(NULL));
	int size=30;
	int random_variable[10]={0};
	int arr[30];
	int key,i,k;
	int comp=0,comp2=0;
	//int insertion(int *array,int p,int r);

	for ( i = 0; i < 10; ++i)
	{	
		
		comp=0;
		for (k = 1; k < size; ++k)			//random variable 
		{
			comp=comp+rand()%(k)+1;
		}
		//cout<<"hello";
		random_variable[i]=comp;		
	}
/*	for ( i = 0; i < 10; ++i)
	{
		cout<<" "<<random_variable[i]<<"\n";
	}*/

	cout<<"gRV"<<" "<<"RV"<<"\n";
	for (i = 0; i < 10; ++i)
	{
		for ( k = 0; k < size; ++k)		//initalize the array with random values
		{
			arr[k]=rand()%100;
		}
/*		for (int i = 0; i < size; ++i)
		{
			cout<<" "<<arr[i];
		}
		cout<<"\n";*/		
		comp2=insertion(arr,0,size-1);
/*		for (int i = 0; i < size; ++i)
		{
			cout<<" "<<arr[i];
		}
		cout<<"\n";*/
		cout<<" "<<random_variable[i]<<"   "<<comp2<<"\n";
	}

}


int insertion(int *array,int p,int r) 			//this returns the no of swaps for sorting 
{     
	int i,j,temp,comp=0;
	for(i=p+1;i<=r;++i)
	{
		temp=array[i];
		for(j=i-1;j>=p;--j)
		{
			++comp;

			if(array[j]>temp)
			{
					array[j+1]=array[j];
					
			}	
			else
				break;
		}

		array[j+1]=temp;
	}
	//cout<<comp<<"\n";
	return(comp);
}    