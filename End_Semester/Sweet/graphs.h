/*Simple Connected Graph*/
class graph
{
private:
	//private data members
	int no_vertices;
	int *adjacency;

	//private helper functions;
	void read_adjacency();

public:
	//public interface functions
	graph();
	void print_adjacency();
	int getVertexCnt();
	int existsEdge(int node1,int node2);
	int getDegree(int node);
	int atleast1Edge();
};


/*CLASS FOR BFS and DFS tree*/
class traversalTree
{
private:
	int no_vertices;
	int *adjacency;
	int root;

	int *vertexLevels;
	int *traversalOrder;
	int *visited;

public:
	void BFS(graph G,int root);
	void print_adjacency();
	int getCntVerVisited();
	int isK4component(graph G);
	int parent(int node);
	int getVertexCnt();
	int getAdjacency(int node1,int node2);
	int isVisited(int node);
	int getVertexLevels(int node);
};


class BFSTree: public traversalTree
{
public:
	/*Checks if C3 exists
	Input : Original Graph G*/
	int C3exists(graph G);
	int isMissingEdge(graph G,int node1,int node2);
};



