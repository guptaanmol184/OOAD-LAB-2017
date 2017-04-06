#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

class graph
{
private:
	int vertices;
	int* edgeList;
public:
	graph();
	void printGraph();
	void getGraph(int mode);
	void bfs(int s);
};

int main(void)
{
	int n,bfsStart;
	graph g;
	g.getGraph(1);
	g.printGraph();
	cout<<"enter vertex to start bfs: ";
	cin>>bfsStart;
	g.bfs(bfsStart);
}

graph::graph()
{
	vertices=0;
	edgeList=NULL;
}

void graph::getGraph(int mode)
{
	cout<<"enter the number if vertices: ";
	cin>>vertices;

	edgeList = (int *)malloc(sizeof(int)*vertices*vertices);

	// mode 1 is for entering space seperated edges
	if(mode==1)
	{
		// input is edge list
		int edge_count;
		cout<<"enter the number of edges: ";
		cin>>edge_count;

		cout<<"enter space seperated edges : "<<endl;
		for(int i=0;i<edge_count;i++)
		{
			//cout<<"i:"<<i<<" ";
			int u,v;
			cin>>u>>v;
			edgeList[(u*vertices)+v]=edgeList[(v*vertices)+u]=1;
		}
		cout<<endl;
	}
	// mode 2 is for entering the adjacency matrix
	else if(mode==2)
	{
		cout<<"enter adjacency matrix: "<<endl;
		// input is adj matrix
		for(int i=0;i<vertices*vertices;i++)
			cin>>edgeList[i];
	}

	//cout<<"finction: "<<edgeList<<endl;
	//return edgeList;
}

void graph::printGraph()
{
	cout<<"\n------print graph------"<<endl;
	
	cout<<"vertices: "<<vertices<<endl;

	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<*(edgeList+i*vertices+j)<<" ";
		}
		cout<<endl;
	}

	cout<<endl;
}

void graph::bfs(int s)
{
	/*color
	  -1 = white //undiscovered
	   0 = gray //discovered but unvisited
	   1 = black // discovered and visited
	  predecessor
	  -1 = no predecessor
	 */
	int color[vertices];
	int distance[vertices];
	int predecessor[vertices];

	// initialise all vertices
	for(int i=0;i < vertices; i++)
	{
		color[i]= -1;
		distance[i] = 99999;
		predecessor[i] = -1;
	}

	//make source vertex as discovered
	color[s]=0;
	distance[s]=0;
	predecessor[s]=-1;

	// a queue for storing the vertices
	list<int> queue;

	queue.push_back(s);

	while(!queue.empty())
	{
		int u = queue.front();
		for(int j=0;j<vertices;j++)
		{
			//for each vertex adj to u
			if(*(edgeList+u*vertices+j)==1)
			{
				if(color[j]==-1)
				{
					color[j]=0; // discovered
					distance[j]=distance[u]+1;
					predecessor[j]=u;
					queue.push_back(j);
				}
			}
		}
		color[u]=1;
		cout<<u<<" ";
		queue.pop_front();
	}

	cout<<endl;


	// print distances
	cout<<"distances from "<<s<<":"<<endl;

	for(int i=0;i<vertices;i++)
		cout<<i<<"-"<<distance[i]<<endl;

}