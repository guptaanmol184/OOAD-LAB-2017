#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ramsey_header.h"
#include <algorithm>
#include <math.h>
using namespace std;
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

int main()

{
    srand(time(NULL));
	int i,j,k;
    
	int frenemy_edges[21]={0};
	int friend_graph[7][7]={{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4},
							{4,4,4,4,4,4,4}};
	int case_success=0;
	//print_array(frenemy_edges);

	//it is enough to show that the ramsay's proof holds till 11 friend edges
	//because friends and enemies are symmetrical
 	for(int no_of_friends=0;no_of_friends<=11;++no_of_friends)
 	{

 		do
 		{
 			print_array(frenemy_edges);
 			convert_to_graph(frenemy_edges,friend_graph); 
 			print_graph(friend_graph);
 			do
 			{
 				i=rand()%7;
 				j=rand()%7;
 				k=rand()%7;
 			}while(i==j||j==k||i==k);
 			if(mutual_frenemy_available(friend_graph,i,j,k)==1)
 				{
                     ++case_success;                     
        
 				   }
 		   
 			cout<<endl; //just to seperate different cases:)
 			
 		}while(next_permutation(frenemy_edges,frenemy_edges+21));
 		
 		if(no_of_friends<21)
 			frenemy_edges[21-no_of_friends-1]=1;
 	}

cout<<"\t the probability of success:"<<float(case_success)/pow(2,21);
cout<<"\t the probabiltity of failure:"<<float(pow(2,21)-case_success)/pow(2,21); 	
}
