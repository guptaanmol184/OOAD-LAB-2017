#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

//#define SIZE 16
//#define TRIALS 100

int rand_search(int array[],int size,int x);

int main()
{
	int SIZE=4;
	int seed;
	cout<<"enter seed: ";
	cin>>seed;
	for(SIZE;SIZE<=65536;SIZE*=2)
	{
		cout<<"\nArray size: "<<SIZE<<endl;
		int ctr=0;
		int TRIALS=10;
		cout<<"\tTRAILS "<<" SUCCESS "<<" PROBABILITY "<<endl;
		for(TRIALS;TRIALS<=10000;TRIALS*=10)
		{
			for(int k=0;k<TRIALS;k++)
			{
				int i;
				int flag=-1;
				int sample_space[SIZE];
				//srand(time(NULL));

				srand(seed+k*k);

				//create sample space
				for(i=0;i<SIZE;i++)
					sample_space[i]=rand();

				//print sample space
				/*for(i=0;i<SIZE;i++)
					cout<<i<<": "<<sample_space[i]<<endl;*/
				srand(seed+TRIALS-k);
				int element_to_search=sample_space[rand()%SIZE];
				//cout<<"element_to_search: "<<element_to_search<<endl;

				flag=rand_search(sample_space,SIZE,element_to_search);

				if(flag)
					ctr++;
			}

			cout<<"\t"<<setw(5)<<TRIALS<<"  ";
			cout<<setw(4)<<ctr<<"  ";
			cout<<fixed<<setw(15)<<setprecision(10);
			cout<<(float)ctr/(float)TRIALS<<endl;
		}
	}
}

int rand_search(int array[],int size,int x)
{
	int i;
	int index;
	int temp;
	int original_size=size;
	//cout<<"Searching locations"<<endl;
	for(i=1;i<=log2(original_size);i++)
	{
		srand(i);
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