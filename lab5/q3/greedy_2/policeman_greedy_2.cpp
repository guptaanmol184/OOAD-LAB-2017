#include <iostream>
#include <fstream>
using namespace std;

void vertex_cover_approx(int vertex_count,int graph_array[]);
void print_graph_array(int a[]);

int VERTEX_COUNT=5;

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
				vertex_cover_approx(VERTEX_COUNT,graph);
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

void print_graph_array(int a[])
{
	for(int i=0;i<VERTEX_COUNT*VERTEX_COUNT;i++)
		cout<<a[i];
	cout<<endl;
}

void vertex_cover_approx(int vertex_count,int graph_array[])
{
	//int vertex_count=6;

	//int edge_count;
	int i,j,k;
	int ctr=0;
	int vertex_cover[vertex_count]={0};
	int adj_mat[vertex_count][vertex_count];

	/*int graph_array[]={
				0,1,1,0,0,0,
				1,0,1,1,0,0,
				1,1,0,1,1,0,
				0,1,1,0,0,0,
				0,0,1,0,0,1,
				0,0,0,0,1,0
			};*/

	//convert 1d to 2d graph
	k=-1;
	for(i=0;i<vertex_count;i++)
		for(j=0;j<vertex_count;j++)
			adj_mat[i][j]=graph_array[++k];


	

	/*cout<<"enter number of vertexs: "<<endl;
	cin>>vertex_count;
	int adj_mat[vertex_count][vertex_count];

	for(i=0;i<vertex_count;i++)
		for(j=0;j<vertex_count;j++)
			adj_mat[i][j]=0;


	cout<<"enter the edge matrix:"<<endl;
	cout<<"enter the number of edges: "<<endl;
	cin>>edge_count;

	int x,y;
	for(i=0;i<edge_count;i++)
	{
		cin>>x;
		cin>>y;
		adj_mat[x][y]=adj_mat[y][x]=1;
	}*/

	//print results
	// count total number of edges
	for(i=0;i<vertex_count;i++)
	{
		//cout<<endl;
		for(j=0;j<=i;j++)
			//cout<<"  ";
		for(j=i+1;j<vertex_count;j++)
		{
			//cout<<adj_mat[i][j]<<" ";
			if(adj_mat[i][j]==1)
				ctr++;
		}
	}
	//cout<<endl;

	//cout<<ctr<<endl;
	//untill edge set is not null
	while(ctr!=0)
	{
		int flag=0;
		for(i=0;i<vertex_count;i++)
		{
			for(j=i+1;j<vertex_count;j++)
			{
				if(adj_mat[i][j]==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}

		//display vertices
		//cout<<i<<" "<<j<<" ";
		//set vertex cover to 1
		vertex_cover[i]=vertex_cover[j]=1;

		for(k=0;k<vertex_count;k++)
		{
			adj_mat[i][k]=0;
			adj_mat[j][k]=0;
		}

		//count again and display graph
		ctr=0;
		for(i=0;i<vertex_count;i++)
		{
			//cout<<endl;
			for(j=0;j<=i;j++)
				//cout<<"  ";
			for(j=i+1;j<vertex_count;j++)
			{
				//cout<<adj_mat[i][j]<<" ";
				if(adj_mat[i][j]==1)
					ctr++;
			}
		}


	}


	cout<<"Vertex Cover : ";
	for(i=0;i<vertex_count;++i)
		if(vertex_cover[i]==1)
			cout<<i<<" ";

	cout<<endl;

	cout<<"COMPLEMENT of Vertex Cover / Largest Enemy Set : ";
	for(i=0;i<vertex_count;++i)
		if(vertex_cover[i]==0)
			cout<<i<<" ";

	cout<<endl;

}