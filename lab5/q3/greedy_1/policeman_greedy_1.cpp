#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "./INCLUDE/arrayOpns.h"

int VERTEX_COUNT=5;

void vertex_cover_directed(int no_vertices,int adjacency[]);
int maxDegreeNode(int *adjacency,int no_vertices);
int formDirectedGraph(int *adjacency,int no_vertices);
void sqrMatrixMultiply(int *matrixA,int *matrixB,int n,int *product);
void arrayClone(int *source,int *destination,int n);
void printSqrMatrix(int *matrix,int n);
void print_graph_array(int a[]);

int main()
{
	cout<<"Planar graphs with "<<VERTEX_COUNT<<" vertices"<<endl<<endl;
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
				cout<<"Graph: ";
				print_graph_array(graph);
				vertex_cover_directed(VERTEX_COUNT,graph);
				cout<<endl;
			}
			else
				graph[++i]=ch-'0';
		}


	}
	else
		cout<<"Unable to open file\n";

	return 0;
}

int formDirectedGraph(int *adjacency,int no_vertices)
{
	//all nodes are given pesudo indices using BFS
	int pseudo_indices[no_vertices];

	//node with highest degree has pseudo_index 0s
	pseudo_indices[0]=maxDegreeNode(adjacency,no_vertices);

	int i,j;
	//works only for connected graphs
	int cNode_pseudoIndex=0,top=0;

	while(top<no_vertices-1)
	{
		for(j=0;j<no_vertices;++j)
			if(*(adjacency+no_vertices*pseudo_indices[cNode_pseudoIndex]+j)==1)
			{
				//check if the element not given PSEUDO INDEX
				if(linearSrch(pseudo_indices,top+1,j)==0)
				{
					pseudo_indices[++top]=j;
				}
			}

		cNode_pseudoIndex++;
	}

	int rev_pseudo_indices[no_vertices];
	for(i=0;i<no_vertices;++i)
		rev_pseudo_indices[pseudo_indices[i]]=i;

	//convert to DIRECTED GRAPH by retaining only edges from i to j, s.t., i<j
	for(i=0;i<no_vertices;++i)
		for(j=0;j<no_vertices;++j)
			if(*(adjacency+i*no_vertices+j)==1)
			{
				if(rev_pseudo_indices[i]>rev_pseudo_indices[j])
				{
					*(adjacency+i*no_vertices+j)=0;
				}
			}
				

	return pseudo_indices[0];
}

int maxDegreeNode(int *adjacency,int no_vertices)
{
	
	int i,j;

	int maxDegreeNode=0,maxDegree=0;

	for(j=0;j<no_vertices;++j)
	{
		maxDegree+=*(adjacency+j);
	}

	int currentNode_degree;
	for(i=1;i<no_vertices;++i)
	{
		currentNode_degree=0;

		for(j=0;j<no_vertices;++j)
		{
			currentNode_degree+=*(adjacency+no_vertices*i+j);
		}

		if(currentNode_degree>maxDegree)
		{
			maxDegreeNode=i;
			maxDegree=currentNode_degree;
		}
	}

	return maxDegreeNode;
}

//multiply matrixA(nxn), matrixB(nxn) and store result in product
//Note: PRODUCT should not point to either matrixA or matrixB
void sqrMatrixMultiply(int *matrixA,int *matrixB,int n,int *product)
{
	int i,j,k;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			*(product+i*n+j)=0;
			for(k=0;k<n;k++)
			{
				*(product+i*n+j)+=*(matrixA+i*n+k)**(matrixB+k*n+j);
			}
		}
}

void arrayClone(int *source,int *destination,int n)
{
	int i;
	for(i=0;i<n;++i)
		*(destination+i)=*(source+i);
}

void printSqrMatrix(int *matrix,int n)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
			cout<<*(matrix+i*n+j)<<" ";
		cout<<endl;
	}

	cout<<endl;
}

void vertex_cover_directed(int no_vertices,int adjacency[])
{
	/*int no_vertices=6;

	int adjacency[]={
					0,1,1,0,0,0,
					1,0,1,1,0,0,
					1,1,0,1,1,0,
					0,1,1,0,0,0,
					0,0,1,0,0,1,
					0,0,0,0,1,0
					};*/

	//cout<<"ORIGINAL GRAPH ADJACENCY:"<<endl;
	//printSqrMatrix(adjacency,no_vertices);

	int startingVertex=formDirectedGraph(adjacency,no_vertices);

	//cout<<"DIRECTED GRAPH ADJACENCY:"<<endl;
	//printSqrMatrix(adjacency,no_vertices);

	//startingVertex added in vertex cover
	int vertexCover[no_vertices]={0};
	vertexCover[startingVertex]=1;

	int i,j;

	//form REACHABILITY MATRIX to find vertices at 2,4,6,... distances from starting vertex
	int base_reachability[no_vertices*no_vertices]={0};
	sqrMatrixMultiply(adjacency,adjacency,no_vertices,base_reachability);

	//cout<<"REACHABILITY MATRIX 1 :"<<endl;
	//printSqrMatrix(base_reachability,no_vertices);
	
	//include all vertices at distance 2 from startingVertex to vertexCover
	for(j=0;j<no_vertices;++j)
		if(*(base_reachability+no_vertices*startingVertex+j)!=0)
			vertexCover[j]=1;

	int reachability[no_vertices*no_vertices];
	arrayClone(base_reachability,reachability,no_vertices*no_vertices);

	int temp_matrix[no_vertices*no_vertices];
	for(j=4;j<no_vertices;j+=2)
	{
		sqrMatrixMultiply(reachability,base_reachability,no_vertices,temp_matrix);
		arrayClone(temp_matrix,reachability,no_vertices*no_vertices);

		//cout<<"REACHABILITY MATRIX "<<j/2<<" : "<<endl;
		//printSqrMatrix(reachability,no_vertices);

		for(i=0;i<no_vertices;++i)
			if(*(reachability+no_vertices*startingVertex+i)!=0)
				vertexCover[i]=1;
	}

	cout<<"Vertex Cover : ";
	for(i=0;i<no_vertices;++i)
		if(vertexCover[i]==1)
			cout<<i<<" ";

	cout<<endl;

	cout<<"COMPLEMENT of Vertex Cover / Largest Enemy Set : ";
	for(i=0;i<no_vertices;++i)
		if(vertexCover[i]==0)
			cout<<i<<" ";

	cout<<endl;

}

void print_graph_array(int a[])
{
	for(int i=0;i<VERTEX_COUNT*VERTEX_COUNT;i++)
		cout<<a[i];
	cout<<endl;
}