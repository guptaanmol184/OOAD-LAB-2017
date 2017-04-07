#include <iostream>
#include <vector>
using namespace std;

class edge
{
public:
	int u;
	int v;
};

int main()
{

	// --------------------REDUCTION ALGORITHM TO CONVERT GRAPH TO 2 HITTING SET----------------------
	int vertices;
	cout<<"enter the number of vertices in graph: ";
	cin>>vertices;

	int adj[vertices][vertices];
	int edge_count;
	cout<<"enter the number of edges: ";
	cin>>edge_count;

	// initialise adj list to 0
	for(int i=0;i<vertices;i++)
		for(int j=0;j<vertices;j++)
			adj[i][j]=0;

	// get edges
	cout<<"enter space seperated edges: "<<endl;
	int u,v;
	for(int i=0;i<edge_count;i++)
	{
		cin>>u;
		cin>>v;
		adj[u][v]=adj[v][u]=1;
	}

	// print graph
	cout<<"graph: "<<endl;
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

	// reduce to 2-hitting set
	vector<int> universe;

	//push into the universe untill (vertices-1)
	for(int i=0;i<vertices;i++)
		universe.push_back(i);

	// print universe set
	cout<<"universe: ";
	for(int i=0;i<vertices;i++)
		cout<<universe[i]<<",";
	cout<<endl;

	// get subsets
	vector<edge> subsets;
	int  k=0;
	for(int i=0;i<vertices;i++)
	{
		for(int j=i+1;j<vertices;j++)
		{
			if(adj[i][j]==1)
			{
				edge e;
				e.u=i;
				e.v=j;
				subsets.push_back(e);
			}
		}
	}

	// print the subsets
	cout<<"subsets: ";
	for(int  i=0;i<edge_count;i++)
	{

		cout<<"{";
		cout<<subsets[i].u<<","<<subsets[i].v;
		cout<<"}";
	}
	cout<<endl;
}