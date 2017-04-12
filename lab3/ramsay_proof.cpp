#include <iostream>
#include <algorithm> 
#include "./find_mutual.h"
using namespace std;

void print_array(int *a);
void convert_to_graph(int frenemy_edges[],int friend_graph[][7]);
void print_graph(int a[][7]);

int main(void)
{
	//generate a string to represent weather an edge is a friend or a enemy
	int frenemy_edges[21]={0};
	int friend_graph[7][7]={{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4}};
	int case_fail=0;
	//print_array(frenemy_edges);

	//it is enough to show that the ramsay's proof holds till 11 friend edges
	//because friends and enemies are symmetrical
 	for(int no_of_friends=0;no_of_friends<=21;++no_of_friends)
 	{

 		do
 		{
 			print_array(frenemy_edges);
 			convert_to_graph(frenemy_edges,friend_graph); 
 			print_graph(friend_graph);
 			if(mutual_frenemy_available(friend_graph)!=1)
 				++case_fail;
 			cout<<endl; //just to seperate different cases:)
 			
 		}while(next_permutation(frenemy_edges,frenemy_edges+21));
 		
 		if(no_of_friends<21)
 			frenemy_edges[21-no_of_friends-1]=1;
 	}

 	if(case_fail==0)
 	{
 		cout<<"THE RAMSAY'S THEOREM HOLDS FOR A GROUP OF 7 MEMBERS!!!!\n";
 	}

 	else
 		cout<<"DOSEN'T SATISFY THE THEOREM!!\n";


	return(0);
}

void print_array(int *a)
{
	for(int edge_no=0;edge_no<21;++edge_no)
		cout<<a[edge_no]<<" ";
		cout<<"\n";
}

void convert_to_graph(int frenemy_edges[21],int friend_graph[7][7])
{
	int k=0;
	for(int i=0;i<7;++i)
	{
		for(int j=i+1;j<7;++j)
		{
			friend_graph[j][i]=frenemy_edges[k];
			friend_graph[i][j]=friend_graph[j][i];
			++k;
		}
	}
}

void print_graph(int a[][7])
{
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
		
}