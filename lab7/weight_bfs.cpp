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
	void addPseudoVertices(int u, int v);
	void weight_bfs(int s);
};

int main(void)
{
	int n,bfsSource;
	graph g;
	g.getGraph(3);  // mode = 3 for weighted graph
	g.printGraph();
	
	// perform bfs and calculate distance
	cout<<"enter source vertex: ";
	cin>>bfsSource;
	g.weight_bfs(bfsSource);

	// print the new expanded graph
	//g.printGraph();


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
		cout<<" --enter the number of edges-- ";
		cin>>edge_count;

		cout<<"enter space seperated edges : "<<endl;
		for(int i=0;i<edge_count;i++)
		{
			//cout<<"i:"<<i<<" ";
			int u,v;
			cin>>u>>v;
			edgeList[(u*vertices)+v]=edgeList[(v*vertices)+u]=1;
		}
		cout<<"endl";
	}
	// mode 2 is for entering the adjacency matrix
	else if(mode==2)
	{
		cout<<"enter adjacency matrix: "<<endl;
		// input is adj matrix
		for(int i=0;i<vertices*vertices;i++)
			cin>>edgeList[i];
	}
	else if(mode == 3)
	{
		/*********weighted graph**********/

		// input is edge list
		int edge_count;
		cout<<"enter the number of edges: ";
		cin>>edge_count;

		cout<<"enter space seperated edges : "<<endl;
		for(int i=0;i<edge_count;i++)
		{
			cout<<"edge "<<i+1<<": ";
			//cout<<"i:"<<i<<" ";
			int u,v,weight;
			cin>>u>>v;
			cout<<"weight: ";
			cin>>weight;
			edgeList[(u*vertices)+v]=edgeList[(v*vertices)+u]=weight;
		}
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

}

void graph::addPseudoVertices(int u, int v)
{
	cout<<"edge : "<<u<<" "<<v<<endl;
	int weight;
	weight=edgeList[u*vertices+v];

	//cout<<weight;

	if(weight==1 || weight==0)
		return;
	else
	{
		int verticesToAdd=weight-1;
		int newVertexCount=vertices+verticesToAdd;
		int oldVertexCount=vertices;

		// create new edgerlist with new vertex count
		int *newEdgeList=(int *)malloc(sizeof(int)*newVertexCount*newVertexCount);

		//copy contents of old edgelist to new edgelist
		for (int i = 0; i < oldVertexCount; ++i)
		{
			for (int j = 0; j < oldVertexCount; ++j)
			{
				newEdgeList[i*newVertexCount+j]=newEdgeList[j*newVertexCount+i]=edgeList[i*oldVertexCount+j];
			}
		}

		//initialise extra rows/columns in new edgelist to zero 
		for(int i=oldVertexCount;i<newVertexCount;i++)
		{
			for(int j=0;j<newVertexCount;j++)
			{
				newEdgeList[i*newVertexCount+j]=newEdgeList[j*newVertexCount+i]=0;
			}
		}

		// destroy edge u ----- v
		newEdgeList[u*newVertexCount+v]=newEdgeList[v*newVertexCount+u]=0;

		//update new pseudo edges in graph
		// edge = u ----- oldVertexCount
		newEdgeList[u*newVertexCount+oldVertexCount]=newEdgeList[oldVertexCount*newVertexCount+u]=1;

		// edge = (newVertexCount-1) ---- v
		newEdgeList[(newVertexCount-1)*newVertexCount+v]=newEdgeList[v*newVertexCount+(newVertexCount-1)]=1;

		int startIndex=oldVertexCount;
		int endIndex=newVertexCount-1;
		for(int i=startIndex; i<(newVertexCount-1);i++)
		{
			// edge = i ----- (i+1)
			newEdgeList[i*newVertexCount+(i+1)]=newEdgeList[(i+1)*newVertexCount+i]=1;			
		}


		//free old edgelist memory
		free(edgeList);

		//update new edgelist and vertices
		edgeList=newEdgeList;
		vertices=newVertexCount;
	}

	//printGraph();
}

void graph::weight_bfs(int s)
{
	// store the original number of vertices in input
	int originalVerices=vertices;

	/*-----------------CONVERT GRAPH-----------------------*/
	// now verices will change as we enter pseudo verices
	// for every edge with weight > 1 enter pseudo vertices

	// do only for upper triangle
	for(int i=0;i<originalVerices;i++)
	{
		for(int j=0;j<originalVerices;j++)
		{
			if(edgeList[i*vertices+j]>1) // position is calculated with respect to the new vertices
				addPseudoVertices(i,j);
		}
	}

	/*---------------------OLD BFS START----------------------------*/
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

	//cout<<"\n----------bfs----------"<<endl;
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
		//cout<<u<<" ";
		queue.pop_front();
	}

	cout<<endl;

	//------------ PRINT DISTANCES OF OLD VERTICES ( no pseudo-vertices ) ---------

	cout<<"-----shortest distances from "<<s<<"-----"<<endl;

	for(int i=0;i<originalVerices;i++)
		cout<<i<<"-"<<distance[i]<<endl;
}