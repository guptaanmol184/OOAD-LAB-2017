#include <iostream>
#include <stdlib.h>
using namespace std;
int visited[100]={0},q[100],f=0,r=-1,level[100]={0};
int BFS(int a,int b,int c[][100],int n)
{
	int i;
  for(i=0;i<n;i++)
   { if(c[a][i]==1 && visited[i]!=1)
       {
       	 level[i]=level[a]+1;
       	 q[++r]=i;
         visited[i]=1;
       	 if(i==b)
       	 {
       	 	
       	 	  return level[i];

       	 }
       	}
       }  	
    if(f<=r)
    {
    	visited[q[f]]=1;
    	BFS(q[f++],b,c,n);
    		
    	
    }
     		
}
int main()
{
	system("reset");
	int i,adj[100][100],n,copy[100][100],j,min=0,temp=0,count=0;
	cout<<"\tEnter the number of vertices:";
	cin>>n;
    cout<<"\tEnter the adjacency matrix:\n";
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
         cin>>adj[i][j];
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       copy[i][j]=adj[i][j];

  for(i=0;i<n;i++)
    {

    	for(j=0;j<n;j++)
    	{
    		if(copy[i][j]==1)
    		{
    			copy[i][j]=0;
    			copy[j][i]=0;
    			temp=BFS(i,j,copy,n)+1;
          if(min==0)
    			 min=temp;  
    			else if(temp<min && temp>2)
    			 {
    			 	
    			 	min=temp;
    			 	 
    			 }
    			copy[i][j]=1;
    			copy[j][i]=1;
    			f=0;
    			r=-1;
    			for(int k=0;k<n;k++)
    			{
    				visited[k]=0;
    				level[k]=0;
    			}
    			
    		}	
    	}
    	
    }
cout<<"\nShortest cycle in the graph:"<<min<<"\n";
} 