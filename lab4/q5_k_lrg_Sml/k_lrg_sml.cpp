#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int partition(int a[],int p,int r)
{
	int x=a[r];
	int i=p-1,j;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{	i++;
		 swap(a[i],a[j]);
	    }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int randomized_partition(int a[],int p,int r)
{
	int k= p+rand()%(r-p+1);
	swap(a[k],a[r]);
	partition(a,p,r);
}
int randomized_select(int a[],int p,int r,int i)
{
	int q,k;
	q=randomized_partition(a,p,r);
	k=q-p+1;
	if(i==k)
		return q;
	else if (i<k)
		return randomized_select(a,p,q-1,i);
	else 
		return randomized_select(a,q+1,r,i-k);
}

int main()
{
	system("cls");
	int i,a[100],n,k;
	cout<<"\t enter the number of elements:";
	cin>>n;
	srand(time(NULL));
	cout<<"\t the randomly-generalized array:";
    for(i=0;i<n;i++)
    {
    	a[i]=rand()%1000;
        cout<<" "<<a[i];
    }
    cout<<"\n";
    cout<<"\t enter the number of largest and smallest elements required:";
    cin>>k;
    int u=randomized_select(a,0,n-1,k);
    cout<<"\t the k-smallest elements:";
    for(i=0;i<=u;i++)
    	cout<<"\t"<<a[i];
 	cout<<"\n";
 	cout<<"\t the k-largest elements:";
 	for(i=u+1;i<u+k+1;i++)
 		cout<<"\t"<<a[i];

 cout<<endl;
}