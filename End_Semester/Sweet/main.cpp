#include <iostream>
using namespace std;

#include "./graphs.cpp"

int allVisited(int *visited,int no_vertices);
int getUnvisited(int *visited,int no_vertices);
void markAllVisited(int *visited,int no_vertices, traversalTree bfs_tree);

main()
{
	graph G;
	//G.print_adjacency();

	int K4exists=0,K3exists=0;

	int no_vertices=G.getVertexCnt();
	int visited[no_vertices];
	fill_n(visited,no_vertices,0);

	BFSTree bfs_tree;
	while(allVisited(visited,no_vertices)==0 && K4exists==0)
	{

		bfs_tree.BFS(G,getUnvisited(visited,no_vertices));

		if(bfs_tree.isK4component(G))
			K4exists=1;

		else if(bfs_tree.C3exists(G))
			K3exists=1;

		markAllVisited(visited,no_vertices,bfs_tree);

	}

	if(K4exists==1)
		cout<<"Maximum Clique is K4"<<endl;

	else if(K3exists==1)
		cout<<"Maximum Clique is K3"<<endl;

	else if(G.atleast1Edge())
		cout<<"Maximum Clique is K2"<<endl;

	else
		cout<<"Maximum Clique is K1"<<endl;

	

}

int allVisited(int *visited,int no_vertices)
{
	int i,allVisit=1;

	for(i=0;i<no_vertices;++i)
		if(*(visited+i)==0)
		{
			allVisit=0;
			break;
		}

	return allVisit;
	
}

int getUnvisited(int *visited,int no_vertices)
{
	int i;
	int unvisited=-1;

	for(i=0;i<no_vertices;++i)
		if(visited[i]==0)
		{
			unvisited=i;
			break;
		}

	return unvisited;
}	

void markAllVisited(int *visited,int no_vertices, traversalTree bfs_tree)
{
	for(int i=0;i<no_vertices;++i)
		if(bfs_tree.isVisited(i))
			visited[i]=1;
}