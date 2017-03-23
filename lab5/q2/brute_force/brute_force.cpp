/*Reads graphs line by line from a file
  to give input to other functons
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <typeinfo>
using namespace std;

void graph_complement(int a[], int no_vertices);
void brute_force(int vertex_count,int *graph);
void print_graph_array(int a[]);
int is_vertex_cover(int *vertex,int *graph,int n);
int is_zero(int *graph,int n);
void row_zero(int *graph,int ver,int n);


int VERTEX_COUNT=5;



int main()
{
	char ch;
	string filename="../../extra_stuff/graphs_file_read/planar_conn_"+to_string(VERTEX_COUNT)+".txt";
	
	ifstream file;
	file.open(filename,ios::in);

	int graph[VERTEX_COUNT*VERTEX_COUNT];
	int i=-1;
	if(file.is_open())
	{
		while(file>>noskipws>>ch)
		{
			if(ch=='\n')
			{
				i=-1;
				cout<<"Graph  : ";
				print_graph_array(graph);
				graph_complement(graph,VERTEX_COUNT);
				cout<<"Graph' : ";
				print_graph_array(graph);
				brute_force(VERTEX_COUNT,graph);
			}
			else
				graph[++i]=ch-'0';
		}


	}
	else
		cout<<"Unable to open file\n";

	return 0;
}




void brute_force(int vertex_count,int *graph)
{	
	int opt_soln=0;

	int n=5;
	int k=vertex_count*vertex_count;

	
	int vertex[vertex_count]={0};

	vertex[vertex_count-1]=1;

	int i;
/*	for (i = 0; i < k; ++i)
	{
		scanf("%1d",&graph[i]);
	}*/

	/*for (i = 0; i < k; ++i)
	{
		printf("%d ",graph[i]);
	}
	printf("\n");*/

	//graph_to_adj(graph,adj,n);

	for (i = 1; i < vertex_count; ++i)
	{
		do{
			if(is_vertex_cover(vertex,graph,n))
			{
				opt_soln=1;
				//for(int l=0;l<n;++l)
				//	printf("%d ",vertex[l] );
				//printf("\n");
				break;
			}

		  }while(next_permutation(vertex,vertex+n));

		if(opt_soln==1)
			break;	

		vertex[n-i-1]=1;				
	}


	/*for ( i = 0; i < vertex_count; ++i)
	{
		printf("%d ",vertex[i]);		
	}
	printf("\n");*/

	cout<<"Vertex Cover : ";
	for(i=0;i<vertex_count;++i)
		if(vertex[i]==1)
			cout<<i<<" ";

	cout<<endl;


	cout<<"COMPLEMENT of Vertex Cover / Largest friend set : ";
	for(i=0;i<vertex_count;++i)
		if(vertex[i]==0)
			cout<<i<<" ";

	cout<<endl<<endl;
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

void print_graph_array(int a[])
{
	for(int i=0;i<VERTEX_COUNT*VERTEX_COUNT;i++)
		cout<<a[i];
	cout<<endl;
}

void graph_complement(int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==0)
			a[i]=1;
		else
			a[i]=0;		
	}
}