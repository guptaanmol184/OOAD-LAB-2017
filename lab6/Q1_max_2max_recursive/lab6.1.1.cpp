#include <iostream>
using namespace std;

#include <stdlib.h>

template <typename C>
struct node
{
	C data;
	node *next;
};

node<int> *h[100]={NULL},*current=NULL;

template <typename C>
void push(C value,int i)
{
	 
	node<C> *new_node=(node<C> *)malloc(sizeof(node<C>));
	new_node->data=value;
	new_node->next=NULL;
	if(h[i]==NULL)
	h[i]=new_node;
	else
	{
		 current=h[i];
		 while(current->next!=NULL)
		 {
		 	current=current->next;
		 }
		 current->next=new_node;

	} 
}

template <typename C>
int maxi(C a[],int i,int n)
{
	if(n==1)
		return i;
	else if(n==2)
	{
		if(a[i]>a[i+1])
			{
				push(a[i+1],i);
				return i;
			}
		else if(a[i]<a[i+1])
			{
				push(a[i],i+1);
                return i+1;
			}

	}
	else
	{
		int c=maxi(a,i,n/2);
		int d=maxi(a,i+n/2,n-n/2);
		if(a[c]>a[d])
			{
				push(a[d],c);
				return c;
			}
		else if(a[d]>a[c])
			{
			   push(a[c],d);
			   return d;
			}
	}
}

template <typename C>
C secondmax(int m)
{
	current=h[m];
	C max=current->data;
	current=current->next;
	while(current!=NULL)
	{
		if(current->data>max)
			max=current->data;
			current=current->next;
	}

	return max;
}

void display(int n)
{
	int i=0;
	while(i<=n)
	{
	   current=h[i];
	   while(current!=NULL)
	   {
	   	cout<<current->data<<"->";
	   	current=current->next;
	   }
	   cout<<"\n";
	   i++;
	}
}
int main()
{
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;

	int a[n];
	cout<<"\nenter the array"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];

	int max=maxi(a,0,n);

	cout<<"The maximum element in the array is "<<a[max]<<endl;

	//type detection f
    cout<<"The second maximum element in the array is "<<secondmax<int>(max)<<endl;

} 