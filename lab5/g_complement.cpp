#include <iostream>
using namespace std;

void graph_complement(int a[], int size);

int main()
{
	int a[5]={1,0,1,1,0};
	int i;
	graph_complement(a,5);

	for(i=0;i<5;i++)
		cout<<a[i]<<" ";
}

void graph_complement(int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==0)
			a[i]=1;
		else
			a[i]=0;		
	}
}