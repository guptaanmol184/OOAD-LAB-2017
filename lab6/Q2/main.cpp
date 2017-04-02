#include <iostream>
using namespace std;

#include "./combined_knapsack.h"

int main()
{	
	char choice;

	cout<<"Enter your choice"<<endl;
	cout<<"1. INT I/O knapsack"<<endl;
	cout<<"2. FLOAT I/O knapsack"<<endl;
	cout<<"3. container loading"<<endl;
	cout<<"4. fractional knapsack"<<endl;

	cout<<endl<<"Your choice: ";
	cin>>choice;
	cout<<endl;
	
	switch( choice )
	{
		case '1':
		{
			cout<<"Your choice is INT I/O knap!"<<endl;

			int no_weights,i;

			cout<<"enter no_weights: ";
			cin>>no_weights;

			int weight[no_weights+1];
			cout<<"enter weight:  ";
			weight[0]=0;
			for(i=1;i<=no_weights;i++)
				cin>>weight[i];

			cout<<"enter profit:  ";
			int profit[no_weights+1];
			profit[0]=0;
			for(int i=1;i<=no_weights;i++)
				cin>>profit[i];

			int W;
			cout<<"enter max weight for the knapsack: ";
			cin>>W;

			knapsack(W,weight,profit,no_weights);
			break;
		}
		case '2':
		{
			cout<<"Your choice is FLOAT I/O knap!"<<endl;

			int no_weights,i;

			cout<<"enter no_weights: ";
			cin>>no_weights;

			float weight[no_weights+1];
			cout<<"enter weight:  ";
			weight[0]=0;
			for(i=1;i<=no_weights;i++)
				cin>>weight[i];

			cout<<"enter profit:  ";
			float profit[no_weights+1];
			profit[0]=0;
			for(int i=1;i<=no_weights;i++)
				cin>>profit[i];

			float W;
			cout<<"enter max weight for the knapsack: ";
			cin>>W;

			knapsack(W,weight,profit,no_weights);
			break;
		}
		case '3':
		{
			cout<<"Your choice is container loading!"<<endl;

			int no_weights,i;

			cout<<"enter no_weights: ";
			cin>>no_weights;

			int weight[no_weights];
			cout<<"enter weight:  ";
			for(i=0;i<no_weights;i++)
				cin>>weight[i];

			int W;
			cout<<"enter max weight for the knapsack: ";
			cin>>W;

			knapsack(W,weight,no_weights);
			break;
		}
			
		case '4':
		{
			cout<<"Your choice is fractional knapsack!"<<endl;
			int no_weights;
			cout<<"enter the number of weights: ";
			cin>>no_weights;

			cout<<"enter weights: ";
			int weight[no_weights];
			for(int i=0;i<no_weights;i++)
				cin>>weight[i];

			cout<<"enter profit:  ";
			int profit[no_weights];
			for(int i=0;i<no_weights;i++)
				cin>>profit[i];
			
			int w;
			cout<<"enter knapsack limit: ";
			cin>>w;

			knapsack(w,weight,profit,no_weights,true);
			break;
		}
		default:
			cout<<"select a proper choice."<<endl;
	}

	return 0;
}