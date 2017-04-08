#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct dfs_ver					//for the  calculation of the articulation point 
{
	int dfs_no=-1;
	int L=-1;
};

struct ver
{
	int vertex=-1;
	int pred=-1;
};

struct edge
{
	int v1;
	int v2;
};

class DFS
{	
	public:
	int n;
	int edge;	
	int graph[5][5]={{0}};
	struct dfs_ver v[5];
	struct ver vert[5];
	struct edge e;
	vector<int> art;
	vector<struct edge> edg;
	vector< vector<int> > bicon;
	int root;

	public:	
	void dfs(int start,int graph[][5]);
	void assign_L();	
	int L_val_child(int ver);
	int dfn_bk(int ver);			//dfs no of the backedges to a vertex
	void art_points(); 
	void bridges();
	void biconn_com();
	//int is_art_point(int ver);
	int min(int a,int b,int c);	
};


int main(void)
{
	DFS g;
	int k,i,j;


	cout<<"enter the no of vertices:";
	cin>>g.n;
	cout<<"enter the no of edges:";
	cin>>g.edge;

	cout<<"enter the edges\n";
	for (k = 0; k < g.edge;++k)
	{
		cin>>i;
		cin>>j;
		g.graph[i][j]=1;
		g.graph[j][i]=1;
	}
	g.root=0;
	g.dfs(g.root,g.graph);

	cout<<"\n";

	for ( k = 0; k < g.n; ++k)
	{
		for (int l = 0; l < g.n; ++l)
		{
			cout<<" "<<g.graph[k][l];
		}
		cout<<"\n";
	}
	cout<<"\n";

	k=0;
	cout<<"dfs traversal: ";
	while(k<g.n)
	{
		cout<<" "<<g.vert[k].vertex;
		++k;
	}
	cout<<"\n";

	k=0;
	cout<<"dfs traversal pred: ";
	while(k<g.n)
	{
		cout<<" "<<g.vert[k].pred;
		++k;
	}
	cout<<"\n";	

	k=0;
	cout<<"dfs_no: ";
	while(k<g.n)
	{
		cout<<" "<<g.v[k].dfs_no;
		++k;
	}
	cout<<"\n";

	k=0;
	cout<<"L value: ";
	while(k<g.n)
	{
		cout<<" "<<g.v[k].L;
		++k;
	}
	cout<<"\n";	
	
	k=0;
	g.art_points();
	cout<<"art_points :";
	for (auto k=g.art.begin(); k != g.art.end(); ++k)
	{
		cout<<" "<<*k;
	}
	cout<<"\n";

	k=0;
	g.bridges();
	cout<<"bridges :";
	for (auto k=g.edg.begin(); k != g.edg.end(); ++k)
	{
		cout<<" "<<k->v1<<"-"<<k->v2;
	}
	cout<<"\n";

	g.biconn_com();
	cout<<"biconn_com :";
	for (int i = 0; i < g.bicon.size(); ++i)
	{
		for (int j = 0; j < g.bicon[i].size(); ++j)
		{
			cout<<g.bicon[i][j]<<" ";
		}
		cout<<"   ";
	}
	cout<<"\n";
	 //cout<<"bk[2]="<<g.dfn_bk(2);

	return 0;
}


void DFS::dfs(int start,int graph[][5])
{
	stack<int> s;
	int ver;
	int visit[n]={0};
	int i=0,j,k=1,l=0;
	start=root;

	s.push(start);
	vert[start].pred=-1;
	//vertex[i]=0;
	v[i].dfs_no=1;
	while(!s.empty())
	{

		ver=s.top();
		//cout<<"  "<<s.top();
	
		if(visit[ver]==0)
		visit[ver]=1;

		for(j=0;j<n;++j)
		{
			if(graph[ver][j]==1 && visit[j]==0)
			{	
				s.push(j);
				++k;
				vert[j].pred=ver;			//adding the pred to a vertex in the dfs traversal	
				v[j].dfs_no=k; 				//assigning dfs_no to the vertex j
				break;
			}	
		}

		if(j==n) 
		{	
			vert[i].vertex=s.top(); 				//post order dfs traversal
			v[vert[i].vertex].L = min(v[vert[i].vertex].dfs_no,L_val_child(vert[i].vertex),dfn_bk(vert[i].vertex));	//L value evaluation			
			s.pop();
			++i;
		}		
	}
}


int DFS::dfn_bk(int ver)
{	
	int i,c=0;
	int min_dfn=n+1;
	for (i = 0; i < n; ++i)
	{
		if(graph[ver][i]==1 && (v[ver].dfs_no-v[i].dfs_no)>1 && !(vert[ver].pred==i))
			if(min_dfn > v[i].dfs_no)
				{
					min_dfn=v[i].dfs_no;
					++c;
				}	

	}

	if((c==0)||(ver==root))
		return(65000);
	else
		return(min_dfn);
}

int DFS::L_val_child(int ver)
{
	int min_L=n+1;
	if(ver==root)
	{	
		for (int i = 0; i < n; ++i)
		{
			if(graph[ver][i]==1 && min_L > v[i].L)
				min_L=v[i].L;
		}
		return(min_L);
	}

	for ( int i = 0; i < n; ++i)
	{
		if(graph[ver][i]==1 && (v[ver].dfs_no+1)==v[i].dfs_no)
			min_L=v[i].L;
	}

	if(min_L==n+1)
	return(65000);

	else
	return(min_L);	
}

void DFS::art_points()
{
	int deg;
	for (int i = 0; i < n; ++i)
	{
		if(graph[root][i]==1)
			++deg;

		if(deg>1)
		{
			art.push_back(root);
			break;
		}
	}

	for (int i = 0; i < n; ++i)
	{	
		if(i!=root && vert[i].pred!=root)
		if(v[vert[i].pred].dfs_no <= v[i].L)
			art.push_back(vert[i].pred);
	}
}

void DFS::bridges()
{
	int j=0;
	for (int i = 0; i < n; ++i)
	{	
		for(j=0;j < n;++j)
		{
			if(v[j].dfs_no < v[i].L && graph[i][j]==1 && i!=j)
			{
				e.v1=i;
				e.v2=j;
				edg.push_back(e);
			}
		}
	}
}

void DFS::biconn_com()
{	
	vector<int> com;
	int graph_cp[5][5];
	int k=0,inc=0,p,q;
	int visit[n]={-1};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			vert[i].vertex=-1;
			graph_cp[i][j]=graph[i][j];
		}
	}
	//cout<<"hello"<<endl;

	for (auto k = edg.begin();k!=edg.end(); ++k)
	{	
		graph_cp[k->v1][k->v2]=0;
		graph_cp[k->v2][k->v1]=0;

		com.clear();
		com.push_back(k->v1);
		com.push_back(k->v2);
		bicon.push_back(com);
			
	}

/*	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<" "<<graph_cp[i][j];
		}
		cout<<endl;
	}
	cout<<endl;*/
	
	
	while(visit[inc]==-1)
	{	
		dfs(inc,graph_cp);
		k=0;
/*		for (int i = 0; i < n; ++i)
		{
			cout<<" "<<vert[i].vertex;
		}*/
		cout<<endl;
		com.clear();
		while(vert[k].vertex!=-1 && k<n)
		{
			//cout<<"hrllo"<<endl;	
			com.push_back(vert[k].vertex);
			++k;
		}

		bicon.push_back(com);
		++inc;
	}

}

/*int DFS::is_art_point(int ver)
{
	int k;
	for (auto k=g.art.begin(); k != g.art.end(); ++k)
	{
		if(ver==*k)
			return(1);
	}
	return(0);	
}*/

int DFS::min(int a,int b,int c)
{
	if((a<=b) && (a<=c))
		return(a);

	if((b<=a) && (b<=c))
	return(b);

	if((c<=a) && (c<=b))
	return(c);

}

/*void DFS::assign_L()
{

	 for (int i = 0; i < n; ++i)
	 {
	 	v[vertex[i]].L=min(v[vertex[i]].dfs_no,L_val_child(vertex[i]),dfn_bk(vertex[i]));
	 }
}*/