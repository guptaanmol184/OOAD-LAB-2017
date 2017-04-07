#include <algorithm>

#include <queue>
#include <stdlib.h>

#include "./graphs.h"

graph::graph()
{
	cout<<"Enter no. of vertices"<<endl;

	cin>>no_vertices;
	adjacency=(int *)malloc(sizeof(int)*no_vertices*no_vertices);

	read_adjacency();
}

int graph::atleast1Edge()
{
	int i,j;

	int edgeExist=0;

	for(i=0;i<no_vertices;++i)
		for(j=0;j<no_vertices;++j)
		{
			if(*(adjacency+no_vertices*i+j)==1)
			{
				edgeExist=1;
				break;
			}

		}

	return edgeExist;

}

int graph::getVertexCnt()
{
	return no_vertices;
}

int graph::existsEdge(int node1,int node2)
{
	return *(adjacency+node1*no_vertices+node2);
}

void graph::read_adjacency()
{	
	int i,j;
	cout<<endl<<"Enter ADJACENCY MATRIX"<<endl;

	for(i=0;i<no_vertices;++i)
		for(j=0;j<no_vertices;++j)
			cin>>*(adjacency+i*no_vertices+j);
}

void graph::print_adjacency()
{
	int i,j;
	cout<<endl<<"ADJACENCY MATRIX"<<endl;

	for(i=0;i<no_vertices;++i)
	{
		for(j=0;j<no_vertices;++j)
			cout<<*(adjacency+i*no_vertices+j)<<" ";
		cout<<endl;
	}

}

int graph::getDegree(int node)
{
	int degree=0;
	for(int i=0;i<no_vertices;++i)
	{
		degree+=*(adjacency+node*no_vertices+i);
	}

	return degree;
}

/*Start of Traversal tree*/
void traversalTree::print_adjacency()
{	
	int i,j;
	cout<<endl<<"TRAVERSAL TREE ADJACENCY"<<endl;
	for(i=0;i<no_vertices;++i)
	{
		for(j=0;j<no_vertices;++j)
			cout<<*(adjacency+i*no_vertices+j)<<" ";
		cout<<endl;
	}
}


void traversalTree::BFS(graph G,int traversalRoot)
{
	no_vertices=G.getVertexCnt();
	root=traversalRoot;

	adjacency=(int *)malloc(sizeof(int)*no_vertices*no_vertices);
	fill_n(adjacency,no_vertices*no_vertices,0);

	vertexLevels=(int *)malloc(sizeof(int)*no_vertices);
	traversalOrder=(int *)malloc(sizeof(int)*no_vertices);

	/*Start of BFS Traversal*/
	visited=(int *)malloc(sizeof(int)*no_vertices);
	fill_n(visited,no_vertices,0);

	visited[root]=1;

	queue<int> bfsVertices;
	bfsVertices.push(root);

	vertexLevels[root]=0;

	int traversalNum=0;
	traversalOrder[root]=traversalNum++;

	int i,cur_vertex;
	while(!bfsVertices.empty())
	{
		cur_vertex=bfsVertices.front();

		//visit all unvisited vertices of current node
		for(i=0;i<no_vertices;++i)
		{
			if(G.existsEdge(cur_vertex,i)&&visited[i]==0)
			{
				bfsVertices.push(i);
				visited[i]=1;

				//add edge between cur_vertex and i in BFS tree
				//Child Edge = 1	|	Parent Edge = 2
				*(adjacency+cur_vertex*no_vertices+i)=1;
				*(adjacency+i*no_vertices+cur_vertex)=2;
				
				vertexLevels[i]=vertexLevels[cur_vertex]+1;
				traversalOrder[i]=traversalNum++;

			}
		}

		bfsVertices.pop();
	}
}

//get the number of vertices visited
int traversalTree::getCntVerVisited()
{
	int no_visited=0;
	for(int i=0;i<no_vertices;++i)
		if(visited[i]==1)
			no_visited++;

	return no_visited;
}

/*returns 0 : if is not K4 component
returns 1   : if is K4 component*/
int traversalTree::isK4component(graph G)
{
	int isK4=0;
	if(getCntVerVisited()==4)
	{
		isK4=1;
		for(int i=0;i<no_vertices;++i)
		{
			if(visited[i]==1 && G.getDegree(i)!=3)
			{
				isK4=0;
				break;
			}
		}
			
	}

	return isK4;
}

int traversalTree::getVertexCnt()
{
	return no_vertices;
}

int traversalTree::getVertexLevels(int node)
{
	return vertexLevels[node];
}

int traversalTree::getAdjacency(int node1,int node2)
{
	return *(adjacency+node1*no_vertices+node2);
}

int traversalTree::isVisited(int node)
{
	return visited[node];
}

int traversalTree::parent(int node)
{
	int p=-1;

	for(int i=0;i<no_vertices;++i)
		if(*(adjacency+no_vertices*node+i)==2)
		{
			p=i;
			break;
		}

	return p;
	
}

// Start of BFS tree functions
int BFSTree::isMissingEdge(graph G,int node1,int node2)
{
	//looks in visited component of graph
	if(G.existsEdge(node1,node2) && getAdjacency(node1,node2)==0 && isVisited(node1)==1 && isVisited(node2)==1)
	{
		//cross Edge
		if(getVertexLevels(node1)==getVertexLevels(node2))
			return 1;

		//Slant Edge in BFS
		else
			return 2;
	}

	else
		return 0;
}

int BFSTree::C3exists(graph G)
{
	int i,j,k;

	int C3exist=0;

	for(i=0;(i<getVertexCnt()-1) && C3exist==0; ++i)
		for(j=i+1;j<getVertexCnt() && C3exist==0 ;++j)
		{
			if(isMissingEdge(G,i,j)==1)
			{
				
				//check if both have same parent
				if(parent(i)==parent(j))
				{
					//cout<<"C3 Cycle : "<<i<<" "<<j<<" "<<parent(i)<<endl;
					C3exist=1;
				}

				
				else
				{	
					//check if there exists slant edge between 'some neighbour of i' and j
					for(k=0;k<getVertexCnt();++k)
						if(getAdjacency(i,k)!=0 && isMissingEdge(G,j,k)==2)
						{
							C3exist=1;
							//cout<<"C3 Cycle : "<<i<<" "<<j<<" "<<k<<endl;
							break;
						}
							

					for(k=0;k<getVertexCnt() && C3exist==0 ;++k)
						if(getAdjacency(j,k)!=0 && isMissingEdge(G,i,k)==2)
						{
							C3exist=1;
							//cout<<"C3 Cycle : "<<i<<" "<<j<<" "<<k<<endl;
							break;
						}
							
					
						
				}

			}
		}
			

	return C3exist;
}