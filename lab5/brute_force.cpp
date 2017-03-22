#include <iostream>
#include <algorithm>
using namespace std;
#include <stdio.h>


int is_zero(int *graph,int n);
int is_vertex_cover(int *vertex,int *graph,int n);
void row_zero(int *graph,int ver,int n);

int main(void)
{	
	int opt_soln=0;

	int n=5;
	int k=n*n;

	int graph[k];
	int vertex[n]={0};

	vertex[n-1]=1;

	int i;
	for (i = 0; i < k; ++i)
	{
		scanf("%1d",&graph[i]);
	}

	for (i = 0; i < k; ++i)
	{
		printf("%d ",graph[i]);
	}
	printf("\n");

	//graph_to_adj(graph,adj,n);

	for (i = 1; i < n; ++i)
	{
		do{
			if(is_vertex_cover(vertex,graph,n))
			{
				opt_soln=1;
				for(int l=0;l<n;++l)
					printf("%d ",vertex[l] );
				printf("\n");
				break;
			}

		  }while(next_permutation(vertex,vertex+n));

		if(opt_soln==1)
			break;	

		vertex[n-i-1]=1;				
	}


	for ( i = 0; i < n; ++i)
	{
		printf("%d ",vertex[i]);		
	}
	printf("\n");

	return 0;
}


int is_vertex_cover(int *vertex,int *graph,int n)
{	
	int k=n*n;
	int ctr=0;
	int graph_cp[k];

	int i,j;
	for (i = 0; i < k; ++i)		//duplicate graph
	{
		graph_cp[i]=graph[i];
	}


	for (i = 0; i < n; ++i)			//vertex include list..
	{
	  		if(vertex[i]==1)
			{		
				row_zero(graph_cp,i,n);
			}
	}
		
	if(is_zero(graph_cp,n))
		return(1);

	else 
		return(0);
}


int is_zero(int *graph,int n)
{
	int k=n*n;
	int ctr=0;
	for (int i = 0; i < k; ++i)
	{
		if(graph[i]==0)
			++ctr;
	}

	if(ctr==k)
		return(1);
	else
		return(0);
}

void row_zero(int *graph,int ver,int n)
{
	for (int i = 0; i < n; ++i)
	{
		graph[i+ver*n]=0;
		graph[ver+i*n]=0;
	}
}