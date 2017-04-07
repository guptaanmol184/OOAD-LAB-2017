#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge
{
public:
	int u;
	int v;
};

int is_2hit(int *vertex,vector<edge> subsets,vector<int> universe);

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

	// ------------- get min vertex cover size ---------
	int k;
	cout<<"enter vertex cover size: ";
	cin>>k;

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
	cout<<"universe: {";
	for(int i=0;i<vertices;i++)
		cout<<universe[i]<<",";
	cout<<"}"<<endl;

	// get subsets
	vector<edge> subsets;
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

	// ------------------ FIND MIN FOR TWO HITTING SET --------------
	
	int opt_soln=0;
	int n=vertices;
	int vertex[n]={0};

	vertex[n-1]=1;

	for (int i=1;i<n;++i)
	{
		do{
			if(is_2hit(vertex,subsets,universe))
			{
				opt_soln=1;
				break;
			}

		  }while(next_permutation(vertex,vertex+n));

		if(opt_soln==1)
			break;	

		vertex[n-i-1]=1;				
	}

	vector<int> universe_prime;
	for (int  i=0; i<n; ++i)
	{
		if(vertex[i]==1)
			universe_prime.push_back(universe[i]);		
	}


	if(universe_prime.size()>k)
		cout<<"vertex cover of size "<<k<<" does not exist";
	else
	{
		cout<<"vertex cover of size "<<k<<" exists"<<endl;
		cout<<"vertex cover: {";
		for(int i=0;i<universe_prime.size();i++)
			cout<<universe_prime[i]<<",";
		cout<<"}";
	}
	cout<<endl;
}

int is_2hit(int *vertex,vector<edge> subsets,vector<int> universe)
{	
	int flag=1;
	// verification code
	vector<int> universe_prime;

	for(int i=0;i<universe.size();i++)
	{
		if(vertex[i]==1)
			universe_prime.push_back(universe[i]);
	}

	// for each subset see if one element is in universe_prime
	for(int i=0;i<subsets.size();i++)
	{
		if((find(universe_prime.begin(),universe_prime.end(),subsets[i].u)==universe_prime.end())&&(find(universe_prime.begin(),universe_prime.end(),subsets[i].v)==universe_prime.end()))
		{
			flag=0;
			break;
		}	
			
	}

	return flag;
}