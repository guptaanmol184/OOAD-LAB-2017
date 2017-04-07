#include <iostream>
using namespace std;

#include <cmath>

/*
Note: Works only for upto n=29
Causes OVERFLOW ERRORS THEREON 
*/

int mergeBestComp(int n);
int mergeWorstComp(int n);
double mergeAvgComp(int n);

long int nCr(int n,int r);

main()
{
	int n;
	cout<<"Enter size of ARRAY"<<endl;
	cin>>n;

	cout<<"MERGE SORT BEST CASE  = "<<mergeBestComp(n)<<endl;
	cout<<"MERGE SORT WORST CASE = "<<mergeWorstComp(n)<<endl;
	cout<<"MERGE SORT AVG CASE   = "<<mergeAvgComp(n)<<endl;
}

/*No. of comparisons by merge in MERGE SORT*/

//BEST CASE
int mergeBestComp(int n)
{
	if(n==1)
		return 0;

	else if(n==2)
		return 1;

	else
		return floor(n/2.00)+mergeBestComp(floor(n/2.00))+mergeBestComp(ceil(n/2.00));
}

int mergeWorstComp(int n)
{
	if(n==1)
		return 0;

	else if(n==2)
		return 1;

	else
		return n-1+mergeWorstComp(floor(n/2.00))+mergeWorstComp(ceil(n/2.00));
}

//Expectations of the number of comparisons
double mergeAvgComp(int n)
{

	if(n==1)
		return 0.00;

	else if(n==2)
		return 1.00;

	else
	{
		int i;

		int list1_size=floor(n/2.00);
		int list2_size=ceil(n/2.00);

		double base_comp=list1_size*1;

		double avg_comp=base_comp;

		//when array 
		for(i=1;i<list2_size;++i)
		{
			base_comp=base_comp*(list1_size+i)*1.00/i;
			avg_comp+=base_comp;
		}

		if(list1_size==list2_size)
			avg_comp=avg_comp*2;

		else
		{
			base_comp=list2_size*1;
			for(i=1;i<list1_size;++i)
			{
				base_comp=base_comp*(list2_size+i)*1.00/i;
				avg_comp+=base_comp;
			}
		}

		//cost for merging
		avg_comp=avg_comp/nCr(n,floor(n/2.00));

		return avg_comp+mergeAvgComp(floor(n/2.00))+mergeAvgComp(ceil(n/2.00));
	}
	


}

long int nCr(int n,int r)
{
	int i;

	long int numerator=1,denominator=1;
	for(i=0;i<r;++i)
	{
		numerator*=(n-i);
		denominator*=(i+1);
	}

	return numerator/denominator;
}
