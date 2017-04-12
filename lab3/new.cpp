#include <iostream>
#include <math.h>
using namespace std;

void prime(int n);

int main(void)
{
	int number;
	cin>>number;
	prime(number);
	cout<<"\n";	

	return 0;
}

void prime(int n)
{
	int i,j,prime,ctr=0;
	for(i=2;i<n;i++)
	{
		prime=1;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
				prime=0;
		}

		if(prime==1)
		{
			ctr++;
			cout<<i<<endl;
		}
	}

	cout<<"count:"<<ctr;
}