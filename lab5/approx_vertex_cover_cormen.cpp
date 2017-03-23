#include <iostream>
using namespace std;

int main()
{
	int vertex_count=6;

	int edge_count;
	int i,j,k;
	int ctr=0;
	int vertex_cover[vertex_count]={0};
	int adj_mat[vertex_count][vertex_count];

	int graph_array[]={
				0,1,1,0,0,0,
				1,0,1,1,0,0,
				1,1,0,1,1,0,
				0,1,1,0,0,0,
				0,0,1,0,0,1,
				0,0,0,0,1,0
			};

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

	//cout<<endl;


	cout<<"Vertex Cover : ";
	for(i=0;i<vertex_count;++i)
		if(vertex_cover[i]==1)
			cout<<i<<" ";

	cout<<endl;

	cout<<"COMPLEMENT of Vertex Cover : ";
	for(i=0;i<vertex_count;++i)
		if(vertex_cover[i]==0)
			cout<<i<<" ";

	cout<<endl;

	return 0;
}