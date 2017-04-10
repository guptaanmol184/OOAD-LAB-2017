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

	int C4exist=0,C3exist=0;

	int no_vertices=G.getVertexCnt();
	int visited[no_vertices];
	fill_n(visited,no_vertices,0);

	BFSTree bfs_tree;
	while(allVisited(visited,no_vertices)==0)
	{

		bfs_tree.BFS(G,getUnvisited(visited,no_vertices));
		
		if(bfs_tree.C3exists(G))
		{
			C3exist=1;
			cout<<endl;

			bfs_tree.listAllC3(G);
		}

		if(bfs_tree.C4exists(G));
		{
			C4exist=1;
			cout<<endl;
			
			bfs_tree.listAllC4(G);

		}

		markAllVisited(visited,no_vertices,bfs_tree);

	}


	cout<<endl<<"C3 ";
	if(C3exist==0)
		cout<<"doesn't ";
	cout<<"exists in G"<<endl;

	cout<<"C4 ";
	if(C4exist==0)
		cout<<"doesn't ";
	cout<<"exists in G"<<endl;


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