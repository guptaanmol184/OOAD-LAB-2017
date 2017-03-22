#include <iostream>
#include <stdlib.h>

using namespace std;

#define SIZE 16

int linearSrch(int *array,int n,int srchElement);

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

	flag=linearSrch(sample_space,SIZE,element_to_search);

	if(flag)
		cout<<"Found"<<endl;
	else
		cout<<"Not found"<<endl;

}

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