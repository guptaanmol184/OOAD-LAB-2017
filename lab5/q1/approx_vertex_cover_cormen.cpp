#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int vertex_cout,edge_count;
	int i,j,k;
	int ctr=0;

	cout<<"enter number of vertexs: "<<endl;
	cin>>vertex_cout;
	int adj_mat[vertex_cout][vertex_cout];

	for(i=0;i<vertex_cout;i++)
		for(j=0;j<vertex_cout;j++)
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
	}

	//print results
	for(i=0;i<vertex_cout;i++)
	{
		//cout<<endl;
		for(j=0;j<=i;j++)
			cout<<"  ";
		for(j=i+1;j<vertex_cout;j++)
		{
			//cout<<adj_mat[i][j]<<" ";
			if(adj_mat[i][j]==1)
				ctr++;
		}
	}
	cout<<endl;

	//cout<<ctr<<endl;
	while(ctr!=0)
	{
		int flag=0;
		for(i=0;i<vertex_cout;i++)
		{
			for(j=i+1;j<vertex_cout;j++)
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
		cout<<i<<" "<<j<<" ";

		for(k=0;k<vertex_cout;k++)
		{
			adj_mat[i][k]=0;
			adj_mat[j][k]=0;
		}

		//count again and display graph
		ctr=0;
		for(i=0;i<vertex_cout;i++)
		{
			//cout<<endl;
			for(j=0;j<=i;j++)
				//cout<<"  ";
			for(j=i+1;j<vertex_cout;j++)
			{
				//cout<<adj_mat[i][j]<<" ";
				if(adj_mat[i][j]==1)
					ctr++;
			}
		}


	}

	cout<<endl;



	return 0;
}