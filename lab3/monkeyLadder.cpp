#include <iostream>
#include <algorithm>
using namespace std;

#include "../INCLUDE/combinatorics.h"
#include "../INCLUDE/arrayOpns.h"
void print_route(int *permute_route,int no_steps);

main()
{
	int no_steps;
	cout<<"Enter number of STEPS"<<endl;
	cin>>no_steps;

	//creates an array of size = # steps and initialise all to 1
	int permute_route[no_steps];
	fill_n(permute_route,no_steps,1);

	int no_permute,total_routes=0;
	for(no_permute=0;no_permute<(no_steps/2)+1;++no_permute)
	{
		do
		{
			print_route(permute_route,no_steps-no_permute);
			total_routes++;
		}while(nxtPermutation(permute_route,permute_route+no_steps-no_permute-1));

		arrayReverse(permute_route,permute_route+no_steps-no_permute-1);
		permute_route[no_permute]=2;
	}


	cout<<"Total number of possible routes = "<<total_routes<<endl;

}

void print_route(int *permute_route,int no_steps)
{
	int cntr;
	for(cntr=0;cntr<no_steps;++cntr)
		cout<<permute_route[cntr]<<" ";
	cout<<endl;
}