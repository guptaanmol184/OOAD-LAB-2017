#include <iostream>
#include <stdlib.h>
using namespace std;
int traversal[100][100]={0};
int visited[100]={0},q[100],f=0,r=-1,degree[100],leaf[100]={0},count=0;
int maxi(int d[],int n)
{
	int max=0,i;
	for(i=1;i<n;i++)
	{
		if(d[max]<d[i])
		{
			max=i;

		}
	}
	return max;
}
void check(int a,int c[][100],int n)
{
	 int t,i;
  for(i=0;i<n;i++)
   { if(c[a][i]==1 && visited[i]!=1)
       {
       	 traversal[a][i]=1;
       	 traversal[i][a]=1;
       	 leaf[i]=degree[i];
       	 visited[i]=1;
       	 count++;
       	 }
       }
     
    int m=maxi(leaf,n);
    leaf[m]=0;
    int flag=0;
    for(i=0;i<n;i++)
    {
       if(visited[i]==0)
       {
        flag=1;
        break;
       }

    }
    if(flag==0)
      return;
    else
    check(m,c,n);   
}

int main()
{
    system("reset");
	int count=0,sum=0,i,j,adj[100][100],n;
	cout<<"\tEnter the number of vertices:";
	cin>>n;
	cout<<"\tEnter the adjacency matrix:\n";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
     cin>>adj[i][j];
    for(i=0;i<n;i++)
    {	
    	sum=0;
    	for(j=0;j<n;++j)
    	{
    		sum=sum+adj[i][j];
    	  }
    	degree[i]=sum;
     }
    
    int m=maxi(degree,n);
    visited[m]=1;   
    check(m,adj,n);
   cout<<"\tRoot of the tree is:"<<m<<"\n";
   cout<<"\tThe spanning tree matrix:\n";
    for(i=0;i<n;i++)
    { cout<<"\n";
      sum=0;
      for(j=0;j<n;j++)
        {
         cout<<"\t"<<traversal[i][j]<<"\t";
         sum=sum+traversal[i][j]; 
         }
      if(sum==1)
      count++;
      }
      cout<<"\n";
    cout<<"\tThe number of leaves:"<<count<<"\n";
  }
