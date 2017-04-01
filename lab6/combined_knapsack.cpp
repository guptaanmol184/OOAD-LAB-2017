#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 1 & 2
int max(int a,int b);
float max(float a,float b);
void knapsack(int W,int *weight,int *profit,int n);
void knapsack(float W,float *weight,float *profit,int n);

// 3
void knapsack(int W, int weight[], int no_weights);

// 4
void knapsack(int w, int weight[], int profit[], int no_weights, bool flag);
int max_index(float a[], int start, int end);
template <typename T> void print_array(T a[],int size);
template <typename T> void swap(T arr[], int index1, int index2);

int main(int argc, char const *argv[])
{
	char choice=argv[1][0];
	
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

// 1 & 2
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}


float max(float a,float b)
{
	if(a>b)
		return a;
	else
		return b;
}

// 1
void knapsack(int W,int *weight,int *profit,int n)
{
	int M[n+1][W+1];
	int i,w;
	int p;
	int profit_array[n+1];

		for (int j = 0; j <= W; ++j)
		{
			M[0][j]=0;
		}
	

	for(i=1;i<=n;++i)
	for (int w = 0; w <= W; ++w)
	{
		if(w < weight[i])
			M[i][w]=M[i-1][w];

		else
			M[i][w] = max(M[i-1][w],profit[i]+M[i-1][w-weight[i]]);
	}

	w=W;
	for (int i = n; i >= 1; --i)
	{
		if (M[i][w]==M[i-1][w])
			profit_array[i]=0;
		else
		{
			profit_array[i]=1;
			w=w-weight[i];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout<<" "<<profit_array[i];
	}
	cout<<endl;
}

// 2
void knapsack(float W,float *weight,float *profit,int n)
{
	int We=W*100;
	int wt[n+1];

	for (int i = 1; i <= n; ++i)
	{
		wt[i]=weight[i]*100;
	}

	float M[n+1][We+1];
	int p,i,w;
	int profit_array[n+1];

		for (int j = 0; j <= W; ++j)
		{
			M[0][j]=0;
		}
	

	for(i=1;i<=n;++i)
	for (int w = 0; w <= We; ++w)
	{
		if(w < wt[i])
			M[i][w]=M[i-1][w];

		else
			M[i][w] = max(M[i-1][w],profit[i]+M[i-1][w-wt[i]]);
	}

	w=We;
	for (int i = n; i >= 1; --i)
	{
		if (M[i][w]==M[i-1][w])
			profit_array[i]=0;
		else
		{
			profit_array[i]=1;
			w=w-wt[i];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout<<" "<<profit_array[i];
	}
	cout<<endl;
}
// 3 start
void knapsack(int W, int weight[], int no_weights)
{
	int size=no_weights;
	int ctr=0;

	sort(weight,weight+size);

	/*	
	for( int i=0; i<size; i++)
		cout<<weight[i]<<" ";
	*/

	int weight_sum=weight[0];

	
	cout<<"weights included: ";
	/*weight_sum=weight[0];
	*/
	int i=0;
	while(weight_sum<=W)
	{
		cout<<weight[i]<<" ";
		i++;
		ctr++;
		weight_sum+=weight[i];	
	}

	cout<<endl<<"Total number of weights inclucded: "<<ctr<<endl;
}
// 3 end

// 4 start
void knapsack(int w, int weight[], int profit[], int no_weights, bool flag)
{
	int temp;
	int size=no_weights;
	float p_w[size];

	for(int i=0;i<size;i++)
		p_w[i]=(float)profit[i]/(float)weight[i];

	cout<<"w  :";
	print_array(weight,size);
	cout<<"p  :";
	print_array(profit,size);
	cout<<"p_w:";
	print_array(p_w,size);

	//sort
	int k=0;
	for(int i=size-1;i>=0;i--)
	{
		int index=max_index(p_w,0,i);

		//swap for p_w
		swap(weight,k,index);
		//swap for profit
		swap(profit,k,index);
		//swap for weight
		swap(p_w,k,index);

		cout<<"w  :";
		print_array(weight,size);
		cout<<"p  :";
		print_array(profit,size);
		cout<<"p_w:";
		print_array(p_w,size);

	}

	int weight_sum=weight[0];

	
	cout<<"weights included: ";
	/*weight_sum=weight[0];
	*/
	int i=0,ctr=0;
	float total_profit=0;
	while(weight_sum<=w)
	{
		cout<<weight[i]<<" ";
		total_profit+=profit[i];
		i++;
		ctr++;
		weight_sum+=weight[i];	
	}
	if(w-weight_sum!=0)
	{
		ctr++;
		float fraction;
		fraction=(float)(weight_sum-w)/(float)weight[i];
		fraction=1-fraction;
		//cout<<"fraction: "<<fraction<<endl;
		cout<<weight[i];
		total_profit+=(float)fraction*(float)profit[i];
	}
	cout<<endl<<"Total number of weights inclucded: "<<ctr<<endl;
	cout<<endl<<"Total profit: "<<total_profit<<endl;



}

int max_index(float a[], int start, int end)
{
	int max_index=start;
	for(int i=start;i<=end;i++)
	{
		if(a[i]>a[max_index])
			max_index=i;
	}

	return max_index;
}

template <typename T>
void print_array(T a[],int size)
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template <typename T>
void swap(T arr[], int index1, int index2)
{
	T temp;
	temp=arr[index1];
	arr[index1]=arr[index2];
	arr[index2]=temp;
}
// 4 end